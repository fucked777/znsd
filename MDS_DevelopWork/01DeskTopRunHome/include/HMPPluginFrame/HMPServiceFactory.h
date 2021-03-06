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


#include "HMPServiceRegistration.h"


/**
 * \ingroup PluginFramework
 *
 * Allows services to provide customized service objects in the plugin
 * environment.
 *
 * <p>
 * When registering a service, a <code>HMPServiceFactory</code> object can be
 * used instead of a service object, so that the plugin developer can gain
 * control of the specific service object granted to a plugin that is using the
 * service.
 *
 * <p>
 * When this happens, the
 * <code>HMPPluginContext::getService(const HMPServiceReference&)</code> method calls the
 * <code>HMPServiceFactory::getService</code> method to create a service object
 * specifically for the requesting plugin. The service object returned by the
 * <code>HMPServiceFactory</code> is cached by the Framework until the plugin
 * releases its use of the service.
 *
 * <p>
 * When the plugin's use count for the service equals zero (including the plugin
 * stopping or the service being unregistered), the
 * <code>HMPServiceFactory::ungetService</code> method is called.
 *
 * <p>
 * <code>HMPServiceFactory</code> objects are only used by the Framework and are
 * not made available to other plugins in the plugin environment. The Framework
 * may concurrently call a <code>HMPServiceFactory</code>.
 *
 * @see HMPPluginContext#getService
 * @remarks This class is thread safe.
 */
class HMPServiceFactory
{

public:

  /**
   * Creates a new service object.
   *
   * <p>
   * The Framework invokes this method the first time the specified
   * <code>plugin</code> requests a service object using the
   * <code>HMPPluginContext::getService(const HMPServiceReference&)</code> method. The
   * service factory can then return a specific service object for each
   * plugin.
   *
   * <p>
   * The Framework caches the value returned (unless it is 0),
   * and will return the same service object on any future call to
   * <code>HMPPluginContext::getService</code> for the same plugins. This means the
   * Framework must not allow this method to be concurrently called for the
   * same plugin.
   *
   * <p>
   * The Framework will check if the returned service object is an instance of
   * all the classes named when the service was registered. If not, then
   * <code>0</code> is returned to the plugin.
   *
   * @param plugin The plugin using the service.
   * @param registration The <code>HMPServiceRegistration</code> object for the
   *        service.
   * @return A service object that <strong>must</strong> be an instance of all
   *         the classes named when the service was registered.
   * @see HMPPluginContext#getService
   */
  virtual QObject* getService(QSharedPointer<HMPPlugin> plugin, HMPServiceRegistration registration) = 0;

  /**
   * Releases a service object.
   *
   * <p>
   * The Framework invokes this method when a service has been released by a
   * plugin. The service object may then be destroyed.
   *
   * @param plugin The HMPPlugin releasing the service.
   * @param registration The <code>HMPServiceRegistration</code> object for the
   *        service.
   * @param service The service object returned by a previous call to the
   *        <code>HMPServiceFactory::getService</code> method.
   * @see HMPPluginContext#ungetService
   */
  virtual void ungetService(QSharedPointer<HMPPlugin> plugin, HMPServiceRegistration registration,
                            QObject* service) = 0;
};

Q_DECLARE_INTERFACE(HMPServiceFactory, "org.commontk.services.HMPServiceFactory")
