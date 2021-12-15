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


#ifndef HMPEVENTHANDLER_H
#define HMPEVENTHANDLER_H

#include "HMPEvent.h"

/**
 * \ingroup EventAdmin
 *
 * Listener for Events.
 *
 * <p>
 * <code>HMPEventHandler</code> objects are registered with the Framework service
 * registry and are notified with an <code>HMPEvent</code> object when an event
 * is sent or posted.
 * <p>
 * <code>HMPEventHandler</code> objects can inspect the received
 * <code>HMPEvent</code> object to determine its topic and properties.
 *
 * <p>
 * <code>HMPEventHandler</code> objects must be registered with a service
 * property {@link HMPEventConstants#EVENT_TOPIC} whose value is the list of topics
 * in which the event handler is interested.
 * <p>
 * For example:
 *
 * \code
 * QStringList topics("com/isv/&#42;");
 * HMPDictionary props;
 * props.insert(HMPEventConstants::EVENT_TOPIC, topics);
 * context->registerService<HMPEventHandler>(this, props);
 * \endcode
 *
 * Event Handler services can also be registered with an
 * {@link HMPEventConstants#EVENT_FILTER} service property to further filter the
 * events. If the syntax of this filter is invalid, then the Event Handler must
 * be ignored by the Event Admin service. The Event Admin service should log a
 * warning.
 * <p>
 * Security Considerations. Plugins wishing to monitor <code>HMPEvent</code>
 * objects will require <code>HMPServicePermission[HMPEventHandler,REGISTER]</code>
 * to register a <code>HMPEventHandler</code> service. The plugin must also have
 * <code>HMPTopicPermission[topic,SUBSCRIBE]</code> for the topic specified in
 * the event in order to receive the event.
 *
 * @see HMPEvent
 *
 * @remarks This class is thread safe.
 */
struct HMPEventHandler
{
  virtual ~HMPEventHandler() {}

  /**
   * Called by the {@link HMPEventAdmin} service to notify the listener of an
   * event.
   *
   * @param event The event that occurred.
   */
  virtual void handleEvent(const HMPEvent& event) = 0;
};

Q_DECLARE_INTERFACE(HMPEventHandler, "org.commontk.service.event.EventHandler")

#endif // HMPEVENTHANDLER_H
