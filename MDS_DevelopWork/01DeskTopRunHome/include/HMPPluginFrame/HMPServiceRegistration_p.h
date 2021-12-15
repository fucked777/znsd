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


#ifndef HMPSERVICEREGISTRATIONPRIVATE_H
#define HMPSERVICEREGISTRATIONPRIVATE_H

#include <QHash>
#include <QMutex>

#include "HMPServiceProperties_p.h"
#include "HMPServiceReference.h"


class HMPPluginPrivate;
class HMPServiceRegistration;

/**
 * \ingroup PluginFramework
 */
class HMPServiceRegistrationPrivate
{

protected:

  friend class HMPServiceRegistration;

  // The HMPServiceReferencePrivate class holds a pointer to a
  // HMPServiceRegistrationPrivate instance and needs to manipulate
  // its reference count. This way it can keep the HMPServiceRegistrationPrivate
  // instance alive and keep returning service properties for
  // unregistered service instances.
  friend class HMPServiceReferencePrivate;

  /**
   * Reference count for implicitly shared private implementation.
   */
  QAtomicInt ref;

  /**
   * Service or HMPServiceFactory object.
   */
  QObject* service;

public:

  /**
   * Plugin registering this service.
   */
  HMPPluginPrivate* plugin;

  /**
   * Reference object to this service registration.
   */
  HMPServiceReference reference;

  /**
   * Service properties.
   */
  HMPServiceProperties properties;

  /**
   * Plugins dependent on this service. Integer is used as
   * reference counter, counting number of unbalanced getService().
   */
  QHash<QSharedPointer<HMPPlugin>,int> dependents;

  /**
   * Object instances that factory has produced.
   */
  QHash<QSharedPointer<HMPPlugin>, QObject*> serviceInstances;

  /**
   * Is service available. I.e., if <code>true</code> then holders
   * of a HMPServiceReference for the service are allowed to get it.
   */
  volatile bool available;

  /**
   * Avoid recursive unregistrations. I.e., if <code>true</code> then
   * unregistration of this service has started but is not yet
   * finished.
   */
  volatile bool unregistering;

  /**
   * Lock object for synchronous event delivery.
   */
  QMutex eventLock;

  QMutex propsLock;

  HMPServiceRegistrationPrivate(HMPPluginPrivate* plugin, QObject* service,
                                const HMPDictionary& props);

  virtual ~HMPServiceRegistrationPrivate();

  /**
   * Check if a plugin uses this service
   *
   * @param p Plugin to check
   * @return true if plugin uses this service
   */
  bool isUsedByPlugin(QSharedPointer<HMPPlugin> p);

  virtual QObject* getService();

private:

  Q_DISABLE_COPY(HMPServiceRegistrationPrivate)

};


#endif // HMPSERVICEREGISTRATIONPRIVATE_H
