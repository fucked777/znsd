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


#ifndef HMPCONFIGURATIONLISTENER_H
#define HMPCONFIGURATIONLISTENER_H

#include "HMPConfigurationEvent.h"

/**
 * \ingroup ConfigAdmin
 *
 * Listener for Configuration Events. When a <code>HMPConfigurationEvent</code>
 * is fired, it is asynchronously delivered to a
 * <code>HMPConfigurationListener</code>.
 *
 * <p>
 * <code>HMPConfigurationListener</code> objects are registered with the
 * Framework service registry and are notified with a
 * <code>HMPConfigurationEvent</code> object when an event is fired.
 * <p>
 * <code>HMPConfigurationListener</code> objects can inspect the received
 * <code>HMPConfigurationEvent</code> object to determine its type, the pid of
 * the <code>HMPConfiguration</code> object with which it is associated, and the
 * Configuration Admin service that fired the event.
 *
 * <p>
 * Security Considerations. Plugins wishing to monitor configuration events will
 * require <code>HMPServicePermission[HMPConfigurationListener,REGISTER]</code> to
 * register a <code>HMPConfigurationListener</code> service.
 */
struct HMPConfigurationListener
{
  virtual ~HMPConfigurationListener() {}

  /**
   * Receives notification of a HMPConfiguration that has changed.
   *
   * @param event The <code>HMPConfigurationEvent</code>.
   */
  virtual void configurationEvent(const HMPConfigurationEvent& event) = 0;
};

Q_DECLARE_INTERFACE(HMPConfigurationListener, "org.commontk.service.cm.ConfigurationListener")

#endif // HMPCONFIGURATIONLISTENER_H
