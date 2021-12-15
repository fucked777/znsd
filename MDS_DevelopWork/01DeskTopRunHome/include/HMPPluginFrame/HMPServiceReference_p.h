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


#ifndef HMPSERVICEREFERENCEPRIVATE_H
#define HMPSERVICEREFERENCEPRIVATE_H

#include <QAtomicInt>
#include <QSharedPointer>

#include "HMPServiceProperties_p.h"

class QObject;

class HMPServiceRegistrationPrivate;
class HMPPlugin;

/**
 * \ingroup PluginFramework
 */
class HMPServiceReferencePrivate
{
public:

  HMPServiceReferencePrivate(HMPServiceRegistrationPrivate* reg);

  ~HMPServiceReferencePrivate();

  /**
    * Get the service object.
    *
    * @param plugin requester of service.
    * @return Service requested or null in case of failure.
    */
  QObject* getService(QSharedPointer<HMPPlugin> plugin);

  /**
   * Unget the service object.
   *
   * @param plugin Plugin who wants remove service.
   * @param checkRefCounter If true decrement refence counter and remove service
   *                        if we reach zero. If false remove service without
   *                        checking refence counter.
   * @return True if service was remove or false if only refence counter was
   *         decremented.
   */
  bool ungetService(QSharedPointer<HMPPlugin> plugin, bool checkRefCounter);

  /**
   * Get all properties registered with this service.
   *
   * @return A HMPDictionary object containing properties or being empty
   *         if service has been removed.
   */
  const HMPServiceProperties& getProperties() const;

  /**
   * Returns the property value to which the specified property key is mapped
   * in the properties <code>HMPDictionary</code> object of the service
   * referenced by this <code>HMPServiceReference</code> object.
   *
   * <p>
   * Property keys are case-insensitive.
   *
   * <p>
   * This method must continue to return property values after the service has
   * been unregistered. This is so references to unregistered services can
   * still be interrogated.
   *
   * @param key The property key.
   * @param lock If <code>true</code>, access of the properties of the service
   *        referenced by this <code>HMPServiceReference</code> object will be
   *        synchronized.
   * @return The property value to which the key is mapped; an invalid QVariant
   *         if there is no property named after the key.
   */
  QVariant getProperty(const QString& key, bool lock) const;

  /**
   * Reference count for implicitly shared private implementation.
   */
  QAtomicInt ref;

  /**
   * Link to registration object for this reference.
   */
  HMPServiceRegistrationPrivate* const registration;

private:

  Q_DISABLE_COPY(HMPServiceReferencePrivate)
};

#endif // HMPSERVICEREFERENCEPRIVATE_H
