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

#ifndef HMPSERVICEEVENT_H
#define HMPSERVICEEVENT_H

#ifdef REGISTERED
#error Try to reorder include files (this one first)\
 or write #undef REGISTERED before including this header.\
 Cause of this problem may be dcmimage.h, which indirectly\
 includes windows.h.
#endif

#include <QSharedDataPointer>
#include <QDebug>
#include <QMetaType>

#include "HMPPluginFrameworkExport.h"
#include "HMPServiceReference.h"

class HMPServiceEventData;

/**
 * \ingroup PluginFramework
 *
 * An event from the Plugin Framework describing a service lifecycle change.
 * <p>
 * <code>HMPServiceEvent</code> objects are delivered to
 * slots connected via HMPPluginContext::connectServiceListener() when a
 * change occurs in this service's lifecycle. A type code is used to identify
 * the event type for future extendability.
 */
class HMP_PLUGINFW_EXPORT HMPServiceEvent
{

  QSharedDataPointer<HMPServiceEventData> d;

public:

  enum Type {

    /**
     * This service has been registered.
     * <p>
     * This event is synchronously delivered <strong>after</strong> the service
     * has been registered with the Framework.
     *
     * @see HMPPluginContext#registerService()
     */
    REGISTERED = 0x00000001,

    /**
     * The properties of a registered service have been modified.
     * <p>
     * This event is synchronously delivered <strong>after</strong> the service
     * properties have been modified.
     *
     * @see HMPServiceRegistration#setProperties
     */
    MODIFIED = 0x00000002,

    /**
     * This service is in the process of being unregistered.
     * <p>
     * This event is synchronously delivered <strong>before</strong> the service
     * has completed unregistering.
     *
     * <p>
     * If a plugin is using a service that is <code>UNREGISTERING</code>, the
     * plugin should release its use of the service when it receives this event.
     * If the plugin does not release its use of the service when it receives
     * this event, the Framework will automatically release the plugin's use of
     * the service while completing the service unregistration operation.
     *
     * @see HMPServiceRegistration#unregister
     * @see HMPPluginContext#ungetService
     */
    UNREGISTERING = 0x00000004,

    /**
     * The properties of a registered service have been modified and the new
     * properties no longer match the listener's filter.
     * <p>
     * This event is synchronously delivered <strong>after</strong> the service
     * properties have been modified. This event is only delivered to slots
     * which were added with a non-<code>null</code> filter where the filter
     * matched the service properties prior to the modification but the filter
     * does not match the modified service properties.
     *
     * @see HMPServiceRegistration#setProperties
     */
    MODIFIED_ENDMATCH = 0x00000008

  };

  /**
   * Default constructor for use with the Qt meta object system.
   */
  HMPServiceEvent();

  ~HMPServiceEvent();

  /**
   * Can be used to check if this HMPServiceEvent instance is valid,
   * or if it has been constructed using the default constructor.
   *
   * @return <code>true</code> if this event object is valid,
   *         <code>false</code> otherwise.
   */
  bool isNull() const;

  /**
   * Creates a new service event object.
   *
   * @param type The event type.
   * @param reference A <code>HMPServiceReference</code> object to the service
   *        that had a lifecycle change.
   */
  HMPServiceEvent(Type type, const HMPServiceReference& reference);

  HMPServiceEvent(const HMPServiceEvent& other);

  HMPServiceEvent& operator=(const HMPServiceEvent& other);

  /**
   * Returns a reference to the service that had a change occur in its
   * lifecycle.
   * <p>
   * This reference is the source of the event.
   *
   * @return Reference to the service that had a lifecycle change.
   */
  HMPServiceReference getServiceReference() const;

  /**
   * Returns the type of event. The event type values are:
   * <ul>
   * <li>{@link #REGISTERED} </li>
   * <li>{@link #MODIFIED} </li>
   * <li>{@link #MODIFIED_ENDMATCH} </li>
   * <li>{@link #UNREGISTERING} </li>
   * </ul>
   *
   * @return Type of service lifecycle change.
   */
  Type getType() const;

};

Q_DECLARE_METATYPE(HMPServiceEvent)

/**
 * \ingroup PluginFramework
 * @{
 */
HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug dbg, HMPServiceEvent::Type type);
HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug dbg, const HMPServiceEvent& event);
/** @}*/

#endif // HMPSERVICEEVENT_H
