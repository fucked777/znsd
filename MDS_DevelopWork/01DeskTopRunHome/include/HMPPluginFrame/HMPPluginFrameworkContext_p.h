/*=============================================================================

  Library: HMP

  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#ifndef HMPPLUGINFRAMEWORKCONTEXT_P_H
#define HMPPLUGINFRAMEWORKCONTEXT_P_H

#include <QDebug>
#include <QMutex>
#include <QDir>

#include "HMPPluginFrameworkFactory.h"
#include "HMPPluginFramework.h"
#include "HMPPluginStorage_p.h"
#include "HMPPlugins_p.h"
#include "HMPPluginFrameworkListeners_p.h"
#include "HMPPluginFrameworkDebug_p.h"


class HMPPlugin;
class HMPPluginStorage;
class HMPServices;

/**
 * \ingroup PluginFramework
 */
class HMPPluginFrameworkContext
{

public:

  /**
   * All plugins in this framework.
   */
  HMPPlugins* plugins;

  /**
   * All listeners in this framework.
   */
  HMPPluginFrameworkListeners listeners;

  /**
   * All registered services in this framework.
   */
  HMPServices* services;

  /**
   * System plugin
   */
  QSharedPointer<HMPPluginFramework> systemPlugin;

  /**
   * HMPPlugin storage
   */
  HMPPluginStorage* storage;

  /**
   * Private Plugin data storage
   */
  QDir dataStorage;

  /**
   * First framework init
   */
  bool firstInit;

  /**
   * Framework id.
   */
  int id;

  /**
   * global lock.
   */
  static QMutex globalFwLock;

  /**
   * Id to use for next instance of plugin framework.
   */
  static int globalId;

  HMPProperties& props;

  /**
   * Debug handle.
   */
  HMPPluginFrameworkDebug debug;

  /**
   * Contruct a framework context
   *
   */
  HMPPluginFrameworkContext();

  ~HMPPluginFrameworkContext();


  /**
   * Initialize the framework
   *
   */
  void init();


  /**
   * Undo as much as possible of what init() does.
   *
   */
  void uninit();


  /**
   *
   */
  int getId() const;

  /**
   * Get private plugin data storage file handle
   */
  QFileInfo getDataStorage(long id);

  /**
   * Check that the plugin belongs to this framework instance.
   *
   */
  void checkOurPlugin(HMPPlugin* plugin) const;


  /**
   * Check that the plugin specified can resolve all its
   * Require-HMPPlugin constraints.
   *
   * @param plugin HMPPlugin to check, must be in INSTALLED state
   *
   * @throws HMPPluginException
   */
  void resolvePlugin(HMPPluginPrivate* plugin);


  /**
   * Log message for debugging framework
   *
   */
  QDebug log() const;

private:

  QSet<HMPPluginPrivate*> tempResolved;

  bool initialized;

  /**
   * Delete framework directory if it exists.
   *
   */
  void deleteFWDir();

  void checkRequirePlugin(HMPPluginPrivate* plugin);

  void initProperties();
};


#endif // HMPPLUGINFRAMEWORKCONTEXT_P_H
