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


#ifndef HMPPLUGINTRACKERCUSTOMIZER_H
#define HMPPLUGINTRACKERCUSTOMIZER_H

#include <QVariant>

#include "HMPPluginEvent.h"

class QObject;
class HMPPlugin;

/**
 * \ingroup PluginFramework
 *
 * The <code>HMPPluginTrackerCustomizer</code> interface allows a
 * <code>HMPPluginTracker</code> to customize the <code>HMPPlugin</code>s that are
 * tracked. A <code>HMPPluginTrackerCustomizer</code> is called when a plugin is
 * being added to a <code>HMPPluginTracker</code>. The
 * <code>HMPPluginTrackerCustomizer</code> can then return an object for the
 * tracked plugin. A <code>HMPPluginTrackerCustomizer</code> is also called when a
 * tracked plugin is modified or has been removed from a
 * <code>HMPPluginTracker</code>.
 *
 * <p>
 * The methods in this interface may be called as the result of a
 * <code>HMPPluginEvent</code> being received by a <code>HMPPluginTracker</code>.
 * Since <code>HMPPluginEvent</code>s are received synchronously by the
 * <code>HMPPluginTracker</code>, it is highly recommended that implementations of
 * these methods do not alter plugin states while being synchronized on any
 * object.
 *
 * <p>
 * The <code>HMPPluginTracker</code> class is thread-safe. It does not call a
 * <code>HMPPluginTrackerCustomizer</code> while holding any locks.
 * <code>HMPPluginTrackerCustomizer</code> implementations must also be
 * thread-safe.
 *
 * \tparam T The type of the tracked object.
 * \remarks This class is thread safe.
 */
template<class T>
struct HMPPluginTrackerCustomizer {

  virtual ~HMPPluginTrackerCustomizer() {}

  /**
   * A plugin is being added to the <code>HMPPluginTracker</code>.
   *
   * <p>
   * This method is called before a plugin which matched the search parameters
   * of the <code>HMPPluginTracker</code> is added to the
   * <code>HMPPluginTracker</code>. This method should return the object to be
   * tracked for the specified <code>HMPPlugin</code>. The returned object is
   * stored in the <code>HMPPluginTracker</code> and is available from the
   * HMPPluginTracker::getObject(HMPPlugin*) method.
   *
   * @param plugin The <code>HMPPlugin</code> being added to the
   *        <code>HMPPluginTracker</code>.
   * @param event The plugin event which caused this customizer method to be
   *        called or an invalid event (HMPPluginEvent::isNull() returns <code>true</code>)
   *        if there is no plugin event associated
   *        with the call to this method.
   * @return The object to be tracked for the specified <code>HMPPlugin</code>
   *         object or <code>null</code> if the specified <code>HMPPlugin</code>
   *         object should not be tracked.
   */
  virtual T addingPlugin(QSharedPointer<HMPPlugin> plugin, const HMPPluginEvent& event) = 0;

  /**
   * A plugin tracked by the <code>HMPPluginTracker</code> has been modified.
   *
   * <p>
   * This method is called when a plugin being tracked by the
   * <code>HMPPluginTracker</code> has had its state modified.
   *
   * @param plugin The <code>HMPPlugin</code> whose state has been modified.
   * @param event The plugin event which caused this customizer method to be
   *        called or an invalid event (HMPPluginEvent::isNull() returns <code>true</code>)
   *        if there is no plugin event associated
   *        with the call to this method.
   * @param object The tracked object for the specified plugin.
   */
  virtual void modifiedPlugin(QSharedPointer<HMPPlugin> plugin, const HMPPluginEvent& event,
      T object) = 0;

  /**
   * A plugin tracked by the <code>HMPPluginTracker</code> has been removed.
   *
   * <p>
   * This method is called after a plugin is no longer being tracked by the
   * <code>HMPPluginTracker</code>.
   *
   * @param plugin The <code>HMPPlugin</code> that has been removed.
   * @param event The plugin event which caused this customizer method to be
   *        called or an invalid event (HMPPluginEvent::isNull() returns <code>true</code>)
   *        if there is no plugin event associated
   *        with the call to this method.
   * @param object The tracked object for the specified plugin.
   */
  virtual void removedPlugin(QSharedPointer<HMPPlugin> plugin, const HMPPluginEvent& event,
      T object) = 0;
};

#endif // HMPPLUGINTRACKERCUSTOMIZER_H
