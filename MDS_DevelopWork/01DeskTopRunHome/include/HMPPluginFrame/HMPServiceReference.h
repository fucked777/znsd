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

#ifndef HMPSERVICEREFERENCE_H
#define HMPSERVICEREFERENCE_H

#include <QVariant>
#include <QMetaType>

#include "HMPPlugin.h"

#include "HMPPluginFrameworkExport.h"


class HMPServiceRegistrationPrivate;
class HMPServiceReferencePrivate;
class HMPServiceEvent;

/**
 * \ingroup PluginFramework
 *
 * A reference to a service.
 *
 * <p>
 * The Framework returns <code>HMPServiceReference</code> objects from the
 * <code>HMPPluginContext::getServiceReference</code> and
 * <code>HMPPluginContext::getServiceReferences</code> methods.
 * <p>
 * A <code>HMPServiceReference</code> object may be shared between plugins and
 * can be used to examine the properties of the service and to get the service
 * object.
 * <p>
 * Every service registered in the Framework has a unique
 * <code>HMPServiceRegistration</code> object and may have multiple, distinct
 * <code>HMPServiceReference</code> objects referring to it.
 * <code>HMPServiceReference</code> objects associated with a
 * <code>HMPServiceRegistration</code> are considered equal
 * (more specifically, their <code>operator==()</code>
 * method will return <code>true</code> when compared).
 * <p>
 * If the same service object is registered multiple times,
 * <code>HMPServiceReference</code> objects associated with different
 * <code>HMPServiceRegistration</code> objects are not equal.
 *
 * @see HMPPluginContext::getServiceReference
 * @see HMPPluginContext::getServiceReferences
 * @see HMPPluginContext::getService
 * @remarks This class is thread safe.
 */
class HMP_PLUGINFW_EXPORT HMPServiceReference {

public:

  /**
   * Creates an invalid HMPServiceReference object. You can use
   * this object in boolean expressions and it will evaluate to
   * <code>false</code>.
   */
  HMPServiceReference();

  HMPServiceReference(const HMPServiceReference& ref);

  /**
   * Converts this HMPServiceReference instance into a boolean
   * expression. If this instance was default constructed or
   * the service it references has been unregistered, the conversion
   * returns <code>false</code>, otherwise it returns <code>true</code>.
   */
  operator bool() const;

  /**
   * Releases any resources held or locked by this
   * <code>HMPServiceReference</code> and renders it invalid.
   */
  HMPServiceReference& operator=(int null);

  ~HMPServiceReference();

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
   * @return The property value to which the key is mapped; an invalid QVariant
   *         if there is no property named after the key.
   */
  QVariant getProperty(const QString& key) const;

  /**
   * Returns a list of the keys in the <code>HMPDictionary</code>
   * object of the service referenced by this <code>HMPServiceReference</code>
   * object.
   *
   * <p>
   * This method will continue to return the keys after the service has been
   * unregistered. This is so references to unregistered services can
   * still be interrogated.
   *
   * <p>
   * This method is not <i>case-preserving</i>; this means that every key in the
   * returned array is in lower case, which may not be the case for the corresponding key in the
   * properties <code>HMPDictionary</code> that was passed to the
   * {@link HMPPluginContext::registerService(const QStringList&, QObject*, const HMPDictionary&)} or
   * {@link HMPServiceRegistration::setProperties} methods.
   *
   * @return A list of property keys.
   */
  QStringList getPropertyKeys() const;

  /**
   * Returns the plugin that registered the service referenced by this
   * <code>HMPServiceReference</code> object.
   *
   * <p>
   * This method must return <code>0</code> when the service has been
   * unregistered. This can be used to determine if the service has been
   * unregistered.
   *
   * @return The plugin that registered the service referenced by this
   *         <code>HMPServiceReference</code> object; <code>0</code> if that
   *         service has already been unregistered.
   * @see HMPPluginContext::registerService(const QStringList&, QObject* , const HMPDictionary&)
   */
  QSharedPointer<HMPPlugin> getPlugin() const;

  /**
   * Returns the plugins that are using the service referenced by this
   * <code>HMPServiceReference</code> object. Specifically, this method returns
   * the plugins whose usage count for that service is greater than zero.
   *
   * @return A list of plugins whose usage count for the service referenced
   *         by this <code>HMPServiceReference</code> object is greater than
   *         zero.
   */
  QList<QSharedPointer<HMPPlugin> > getUsingPlugins() const;

  /**
   * Compares this <code>HMPServiceReference</code> with the specified
   * <code>HMPServiceReference</code> for order.
   *
   * <p>
   * If this <code>HMPServiceReference</code> and the specified
   * <code>HMPServiceReference</code> have the same {@link HMPPluginConstants::SERVICE_ID
   * service id} they are equal. This <code>HMPServiceReference</code> is less
   * than the specified <code>HMPServiceReference</code> if it has a lower
   * {@link HMPPluginConstants::SERVICE_RANKING service ranking} and greater if it has a
   * higher service ranking. Otherwise, if this <code>HMPServiceReference</code>
   * and the specified <code>HMPServiceReference</code> have the same
   * {@link HMPPluginConstants::SERVICE_RANKING service ranking}, this
   * <code>HMPServiceReference</code> is less than the specified
   * <code>HMPServiceReference</code> if it has a higher
   * {@link HMPPluginConstants::SERVICE_ID service id} and greater if it has a lower
   * service id.
   *
   * @param reference The <code>HMPServiceReference</code> to be compared.
   * @return Returns a false or true if this
   *         <code>HMPServiceReference</code> is less than or greater
   *         than the specified <code>HMPServiceReference</code>.
   * @throws HMPInvalidArgumentException If the specified
   *         <code>HMPServiceReference</code> was not created by the same
   *         framework instance as this <code>HMPServiceReference</code>.
   */
  bool operator<(const HMPServiceReference& reference) const;

  bool operator==(const HMPServiceReference& reference) const;

  HMPServiceReference& operator=(const HMPServiceReference& reference);


protected:

  friend class HMPLDAPSearchFilter;
  friend class HMPServiceRegistrationPrivate;
  friend class HMPPluginContext;
  friend class HMPPluginPrivate;
  friend class HMPPluginFrameworkListeners;
  template<class S, class T> friend class HMPServiceTracker;
  template<class S, class T> friend class HMPServiceTrackerPrivate;
  template<class S, class R, class T> friend class HMPPluginAbstractTracked;

  friend uint HMP_PLUGINFW_EXPORT qHash(const HMPServiceReference&);

  HMPServiceReference(HMPServiceRegistrationPrivate* reg);

  HMPServiceReferencePrivate * d_ptr;

private:
  Q_DECLARE_PRIVATE(HMPServiceReference)
};

/**
 * \ingroup PluginFramework
 * @{
 */
uint HMP_PLUGINFW_EXPORT qHash(const HMPServiceReference& serviceRef);
QDebug HMP_PLUGINFW_EXPORT operator<<(QDebug dbg, const HMPServiceReference& serviceRef);
/** @}*/

Q_DECLARE_METATYPE(HMPServiceReference)


#endif // HMPSERVICEREFERENCE_H
