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


#ifndef HMPTRACKEDPLUGINLISTENER_P_H
#define HMPTRACKEDPLUGINLISTENER_P_H

#include <QObject>

#include "HMPPluginEvent.h"

/**
 * \ingroup PluginFramework
 */
class HMP_PLUGINFW_EXPORT HMPTrackedPluginListener : public QObject
{
  Q_OBJECT

public:
  HMPTrackedPluginListener(QObject *parent = 0)
    : QObject(parent)
  {}

public Q_SLOTS:

  /**
   * Slot for the <code>HMPPluginTracker</code>
   * class. This method must NOT be synchronized to avoid deadlock
   * potential.
   *
   * @param event <code>HMPPluginEvent</code> object from the framework.
   */
  virtual void pluginChanged(const HMPPluginEvent& event) = 0;

};

#endif // HMPTRACKEDPLUGINLISTENER_P_H
