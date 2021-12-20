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

#ifndef HMPSERVICEREGISTRATION_H
#define HMPSERVICEREGISTRATION_H

#include "HMPDictionary.h"
#include "HMPServiceReference.h"

#include "HMPPluginFrameworkExport.h"


class HMPServiceRegistrationPrivate;

/**
 * \ingroup PluginFramework
 *
 * A registered service.
 *
 * <p>
 * The Framework returns a <code>HMPServiceRegistration</code> object when a
 * <code>HMPPluginContext#registerService()</code> method invocation is successful.
 * The <code>HMPServiceRegistration</code> object is for the private use of the
 * registering plugin and should not be shared with other plugins.
 * <p>
 * The <code>HMPServiceRegistration</code> object may be used to update the
 * properties of the service or to unregister the service.
 *
 * @see HMPPluginContext#registerService()
 * @remarks This class is thread safe.
 */
class HMP_PLUGINFW_EXPORT HMPServiceRegistration {

public:

  /**
   * Creates an invalid HMPServiceRegistration object. You can use
   * this object in boolean expressions and it will evaluate to
   * <code>false</code>.
   */
  HMPServiceRegistration();

  HMPServiceRegistration(const HMPServiceRegistration& reg);

  operator bool() const;

  /**
   * Releases any resources held or locked by this
   * <code>HMPServiceRegistration</code> and renders it invalid.
   */
  HMPServiceRegistration& operator=(int null);

  ~HMPServiceRegistration();

  /**
   * Returns a <code>HMPServiceReference</code> object for a service being
   * registered.
   * <p>
   * The <code>HMPServiceReference</code> object may be shared with other
   * plugins.
   *
   * @throws HMPIllegalStateException If this
   *         <code>HMPServiceRegistration</code> object has already been
   *         unregistered or if it is invalid.
   * @return <code>HMPServiceReference</code> object.
   */
  HMPServiceReference getReference() const;

  /**
   * Updates the properties associated with a service.
   *
   * <p>
   * The {@link HMPPluginConstants#OBJECTCLASS} and {@link HMPPluginConstants#SERVICE_ID} keys
   * cannot be modified by this method. These values are set by the Framework
   * when the service is registered in the environment.
   *
   * <p>
   * The following steps are required to modify service properties:
   * <ol>
   * <li>The service's properties are replaced with the provided properties.
   * <li>A service event of type {@link HMPServiceEvent#MODIFIED} is fired.
   * </ol>
   *
   * @param properties The properties for this service. See {@link HMPPluginConstants}
   *        for a list of standard service property keys. Changes should not
   *        be made to this object after calling this method. To update the
   *        service's properties this method should be called again.
   *
   * @throws HMPIllegalStateException If this <code>HMPServiceRegistration</code>
   *         object has already been unregistered or if it is invalid.
   * @throws HMPInvalidArgumentException If <code>properties</code> contains
   *         case variants of the same key name.
   */
  void setProperties(const HMPDictionary& properties);

  /**
   * Unregisters a service. Remove a <code>HMPServiceRegistration</code> object
   * from the Framework service registry. All <code>HMPServiceReference</code>
   * objects associated with this <code>HMPServiceRegistration</code> object
   * can no longer be used to interact with the service once unregistration is
   * complete.
   *
   * <p>
   * The following steps are required to unregister a service:
   * <ol>
   * <li>The service is removed from the Framework service registry so that
   * it can no longer be obtained.
   * <li>A service event of type {@link HMPServiceEvent#UNREGISTERING} is fired
   * so that plugins using this service can release their use of the service.
   * Once delivery of the service event is complete, the
   * <code>HMPServiceReference</code> objects for the service may no longer be
   * used to get a service object for the service.
   * <li>For each plugin whose use count for this service is greater than
   * zero: <br>
   * The plugin's use count for this service is set to zero. <br>
   * If the service was registered with a {@link HMPServiceFactory} object, the
   * <code>HMPServiceFactory#ungetService</code> method is called to release
   * the service object for the plugin.
   * </ol>
   *
   * @throws HMPIllegalStateException If this
   *         <code>HMPServiceRegistration</code> object has already been
   *         unregistered or if it is invalid.
   * @see HMPPluginContext#ungetService
   * @see HMPServiceFactory#ungetService
   */
  void unregister();

  bool operator<(const HMPServiceRegistration& o) const;

  bool operator==(const HMPServiceRegistration& registration) const;

  HMPServiceRegistration& operator=(const HMPServiceRegistration& registration);


protected:

  friend class HMPServices;
  friend class HMPServiceReferencePrivate;

  friend uint HMP_PLUGINFW_EXPORT qHash(const HMPServiceRegistration&);

  HMPServiceRegistration(HMPServiceRegistrationPrivate* registrationPrivate);

  HMPServiceRegistration(HMPPluginPrivate* plugin, QObject* service,
                         const HMPDictionary& props);

  HMPServiceRegistrationPrivate* d_ptr;

private:
  Q_DECLARE_PRIVATE(HMPServiceRegistration)
};

/**
 * \ingroup PluginFramework
 */
uint HMP_PLUGINFW_EXPORT qHash(const HMPServiceRegistration& serviceRef);

#endif // HMPSERVICEREGISTRATION_H
