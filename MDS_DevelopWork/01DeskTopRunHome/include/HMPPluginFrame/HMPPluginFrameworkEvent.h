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

#ifndef HMPPLUGINFRAMEWORKEVENT_H
#define HMPPLUGINFRAMEWORKEVENT_H

#include <QSharedDataPointer>
#include <QSharedPointer>
#include <QMetaType>

#include "HMPPluginFrameworkExport.h"

class HMPException;
class HMPPlugin;
class HMPPluginFrameworkEventData;

/**
 * \ingroup PluginFramework
 *
 * A general event from the Framework.
 *
 * <p>
 * <code>HMPPluginFrameworkEvent</code> objects are delivered to slots connected
 * via HMPPluginContext::connectFrameworkListener when a general event occurs
 * within the plugin environment.
 * A type code is used to identify the event type for future extendability.
 *
 * @see HMPPluginContext#connectFrameworkListener
 * @see HMPEventBus
 */
class HMP_PLUGINFW_EXPORT HMPPluginFrameworkEvent
{

  QSharedDataPointer<HMPPluginFrameworkEventData> d;

public:

  enum Type {
    /**
     * The Framework has started.
     *
     * <p>
     * This event is fired when the Framework has started after all installed
     * plugins that are marked to be started have been started and the Framework
     * has reached the initial start level. The source of this event is the
     * System Plugin.
     */
    FRAMEWORK_STARTED,

    /**
     * An error has occurred.
     *
     * <p>
     * There was an error associated with a plugin.
     */
    PLUGIN_ERROR,

    /**
     * A warning has occurred.
     *
     * <p>
     * There was a warning associated with a plugin.
     */
    PLUGIN_WARNING,

    /**
     * An informational event has occurred.
     *
     * <p>
     * There was an informational event associated with a plugin.
     */
    PLUGIN_INFO,

    /**
     * The Framework has stopped.
     *
     * <p>
     * This event is fired when the Framework has been stopped because of a stop
     * operation on the system plugin. The source of this event is the System
     * Plugin.
     */
    FRAMEWORK_STOPPED,

    /**
     * The Framework has stopped during update.
     *
     * <p>
     * This event is fired when the Framework has been stopped because of an
     * update operation on the system plugin. The Framework will be restarted
     * after this event is fired. The source of this event is the System Plugin.
     */
    FRAMEWORK_STOPPED_UPDATE,

    /**
     * The Framework did not stop before the wait timeout expired.
     *
     * <p>
     * This event is fired when the Framework did not stop before the wait
     * timeout expired. The source of this event is the System Plugin.
     */
    FRAMEWORK_WAIT_TIMEDOUT

  };

  /**
   * Default constructor for use with the Qt meta object system.
   */
  HMPPluginFrameworkEvent();

  ~HMPPluginFrameworkEvent();

  /**
   * Can be used to check if this HMPPluginFrameworkEvent instance is valid,
   * or if it has been constructed using the default constructor.
   *
   * @return <code>true</code> if this event object is valid,
   *         <code>false</code> otherwise.
   */
  bool isNull() const;

  /**
   * Creates a Framework event regarding the specified plugin and exception.
   *
   * @param type The event type.
   * @param plugin The event source.
   * @param fwException The related exception.
   */
  HMPPluginFrameworkEvent(Type type, QSharedPointer<HMPPlugin> plugin, const HMPException& fwException);

  /**
   * Creates a Framework event regarding the specified plugin.
   *
   * @param type The event type.
   * @param plugin The event source.
   */
  HMPPluginFrameworkEvent(Type type, QSharedPointer<HMPPlugin> plugin);

  HMPPluginFrameworkEvent(const HMPPluginFrameworkEvent& other);

  HMPPluginFrameworkEvent& operator=(const HMPPluginFrameworkEvent& other);

  /**
   * Returns the exception error string related to this event.
   *
   * @return The related error string.
   */
  QString getErrorString() const;

  /**
   * Returns the plugin associated with the event. This plugin is also the
   * source of the event.
   *
   * @return The plugin associated with the event.
   */
  QSharedPointer<HMPPlugin> getPlugin() const;

  /**
   * Returns the type of framework event.
   * <p>
   * The type values are:
   * <ul>
   * <li>{@link #FRAMEWORK_STARTED}
   * <li>{@link #PLUGIN_ERROR}
   * <li>{@link #PLUGIN_WARNING}
   * <li>{@link #PLUGIN_INFO}
   * <li>{@link #FRAMEWORK_STOPPED}
   * <li>{@link #FRAMEWORK_STOPPED_UPDATE}
   * <li>{@link #FRAMEWORK_WAIT_TIMEDOUT}
   * </ul>
   *
   * @return The type of state change.
   */
  Type getType() const;
};

Q_DECLARE_METATYPE(HMPPluginFrameworkEvent);

/**
 * \ingroup PluginFramework
 * @{
 */
HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug dbg, HMPPluginFrameworkEvent::Type type);
HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug dbg, const HMPPluginFrameworkEvent& event);
/** @} */

#endif // HMPPLUGINFRAMEWORKEVENT_H
