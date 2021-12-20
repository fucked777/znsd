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

#ifndef HMPPLUGINEVENT_H
#define HMPPLUGINEVENT_H

#include <QSharedDataPointer>
#include <QSharedPointer>
#include <QMetaType>

#include "HMPPluginFrameworkExport.h"


class HMPPlugin;
class HMPPluginEventData;

/**
 * \ingroup PluginFramework
 *
 * An event from the Framework describing a plugin lifecycle change.
 * <p>
 * <code>HMPPluginEvent</code> objects are delivered to slots connected
 * via HMPPluginContext::connectPluginListener() when a change
 * occurs in a plugins's lifecycle. A type code is used to identify
 * the event type for future extendability.
 *
 * @see HMPPluginContext#connectPluginListener
 */
class HMP_PLUGINFW_EXPORT HMPPluginEvent
{

  QSharedDataPointer<HMPPluginEventData> d;

public:

  enum Type {
    /**
     * The plugin has been installed.
     *
     * @see HMPPluginContext::installBundle(const QString&)
     */
    INSTALLED,

    /**
     * The plugin has been started.
     * <p>
     * The plugin's
     * \link HMPPluginActivator::start(HMPPluginContext*) HMPPluginActivator start\endlink method
     * has been executed.
     *
     * @see HMPPlugin::start()
     */
    STARTED,

    /**
     * The plugin has been stopped.
     * <p>
     * The plugin's
     * \link HMPPluginActivator::stop(HMPPluginContext*) HMPPluginActivator stop\endlink method
     * has been executed.
     *
     * @see HMPPlugin::stop()
     */
    STOPPED,

    /**
     * The plugin has been updated.
     *
     * @see HMPPlugin::update()
     */
    UPDATED,

    /**
     * The plugin has been uninstalled.
     *
     * @see HMPPlugin::uninstall()
     */
    UNINSTALLED,

    /**
     * The plugin has been resolved.
     *
     * @see HMPPlugin::RESOLVED
     */
    RESOLVED,

    /**
     * The plugin has been unresolved.
     *
     * @see HMPPlugin::INSTALLED
     */
    UNRESOLVED,

    /**
     * The plugin is about to be activated.
     * <p>
     * The plugin's
     * \link HMPPluginActivator::start(HMPPluginContext*) HMPPluginActivator start\endlink method
     * is about to be called. This
     * event is only delivered to synchronuous slots, which have been registered with
     * Qt::DirectConnection or Qt::BlockingQueuedConnection in HMPPluginContext::connectPluginListener().
     *
     * @see HMPPlugin::start()
     */
    STARTING,

    /**
     * The plugin is about to deactivated.
     * <p>
     * The plugin's
     * \link HMPPluginActivator::stop(HMPPluginContext*) HMPPluginActivator stop\endlink method
     * is about to be called. This
     * event is only delivered to synchronuous slots, which have been registered with
     * Qt::DirectConnection or Qt::BlockingQueuedConnection in HMPPluginContext::connectPluginListener().
     *
     * @see HMPPlugin::stop()
     */
    STOPPING,

    /**
     * The plugin will be lazily activated.
     * <p>
     * The plugin has a \link HMPPluginConstants::ACTIVATION_LAZY lazy activation policy\endlink
     * and is waiting to be activated. It is now in the
     * \link HMPPlugin::STARTING STARTING\endlink state and has a valid
     * <code>HMPPluginContext</code>. This
     * event is only delivered to synchronuous slots, which have been registered with
     * Qt::DirectConnection or Qt::BlockingQueuedConnection in HMPPluginContext::connectPluginListener().
     */
    LAZY_ACTIVATION
  };

  /**
   * Default constructor for use with the Qt meta object system.
   */
  HMPPluginEvent();

  ~HMPPluginEvent();

  /**
   * Can be used to check if this HMPPluginEvent instance is valid,
   * or if it has been constructed using the default constructor.
   *
   * @return <code>true</code> if this event object is valid,
   *         <code>false</code> otherwise.
   */
  bool isNull() const;

  /**
   * Creates a plugin event of the specified type.
   *
   * @param type The event type.
   * @param plugin The plugin which had a lifecycle change.
   */
  HMPPluginEvent(Type type, QSharedPointer<HMPPlugin> plugin);

  HMPPluginEvent(const HMPPluginEvent& other);

  HMPPluginEvent& operator=(const HMPPluginEvent& other);

  /**
   * Returns the plugin which had a lifecycle change.
   *
   * @return The plugin that had a change occur in its lifecycle.
   */
  QSharedPointer<HMPPlugin> getPlugin() const;

  /**
   * Returns the type of lifecyle event. The type values are:
   * <ul>
   * <li>{@link #INSTALLED}
   * <li>{@link #RESOLVED}
   * <li>{@link #LAZY_ACTIVATION}
   * <li>{@link #STARTING}
   * <li>{@link #STARTED}
   * <li>{@link #STOPPING}
   * <li>{@link #STOPPED}
   * <li>{@link #UPDATED}
   * <li>{@link #UNRESOLVED}
   * <li>{@link #UNINSTALLED}
   * </ul>
   *
   * @return The type of lifecycle event.
   */
  Type getType() const;

};

Q_DECLARE_METATYPE(HMPPluginEvent)

/**
 * \ingroup PluginFramework
 * @{
 */
HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug debug, HMPPluginEvent::Type eventType);
HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug debug, const HMPPluginEvent& event);
/** @}*/

#endif // HMPPLUGINEVENT_H
