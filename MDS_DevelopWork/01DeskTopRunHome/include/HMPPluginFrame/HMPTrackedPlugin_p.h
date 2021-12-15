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


#ifndef HMPTRACKEDPLUGIN_P_H
#define HMPTRACKEDPLUGIN_P_H

#include <QSharedPointer>

#include "HMPTrackedPluginListener_p.h"
#include "HMPPluginAbstractTracked_p.h"
#include "HMPPluginEvent.h"
#include "HMPPlugin.h"

/**
 * \ingroup PluginFramework
 */
template<class T>
class HMPTrackedPlugin : public HMPTrackedPluginListener,
    public HMPPluginAbstractTracked<QSharedPointer<HMPPlugin>, T, HMPPluginEvent>
{

public:
  HMPTrackedPlugin(HMPPluginTracker<T>* pluginTracker,
                   HMPPluginTrackerCustomizer<T>* customizer);


  /**
   * Slot for the <code>HMPPluginTracker</code>
   * class. This method must NOT be synchronized to avoid deadlock
   * potential.
   *
   * @param event <code>HMPPluginEvent</code> object from the framework.
   */
  void pluginChanged(const HMPPluginEvent& event);

private:

  typedef HMPPluginAbstractTracked<QSharedPointer<HMPPlugin>, T, HMPPluginEvent> Superclass;

  HMPPluginTracker<T>* pluginTracker;
  HMPPluginTrackerCustomizer<T>* customizer;

  /**
   * Call the specific customizer adding method. This method must not be
   * called while synchronized on this object.
   *
   * @param item Item to be tracked.
   * @param related Action related object.
   * @return Customized object for the tracked item or <code>null</code>
   *         if the item is not to be tracked.
   */
  T customizerAdding(QSharedPointer<HMPPlugin> item,
                     const HMPPluginEvent& related);

  /**
   * Call the specific customizer modified method. This method must not be
   * called while synchronized on this object.
   *
   * @param item Tracked item.
   * @param related Action related object.
   * @param object Customized object for the tracked item.
   */
  void customizerModified(QSharedPointer<HMPPlugin> item,
                          const HMPPluginEvent& related, T object);

  /**
   * Call the specific customizer removed method. This method must not be
   * called while synchronized on this object.
   *
   * @param item Tracked item.
   * @param related Action related object.
   * @param object Customized object for the tracked item.
   */
  void customizerRemoved(QSharedPointer<HMPPlugin> item,
                         const HMPPluginEvent& related, T object);
};

#include "HMPTrackedPlugin.tpp"

#endif // HMPTRACKEDPLUGIN_P_H
