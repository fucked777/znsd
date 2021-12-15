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


#ifndef HMPSERVICES_P_H
#define HMPSERVICES_P_H

#include <QHash>
#include <QObject>
#include <QMutex>
#include <QStringList>

#include "HMPPlugin_p.h"
#include "HMPServiceRegistration.h"


/**
 * \ingroup PluginFramework
 *
 * Here we handle all the services that are registered in the framework.
 */
class HMPServices {

public:

  mutable QMutex mutex;

  /**
   * Creates a new HMPDictionary object containing <code>in</code>
   * with the keys converted to lower case.
   *
   * @param classes A list of class names which will be added to the
   *        created HMPDictionary object under the key
   *        PluginConstants::OBJECTCLASS.
   * @param sid A service id which will be used instead of a default one.
   */
  static HMPDictionary createServiceProperties(const HMPDictionary& in,
                                 const QStringList& classes = QStringList(),
                                 long sid = -1);

  /**
   * All registered services in the current framework.
   * Mapping of registered service to class names under which
   * the service is registerd.
   */
  QHash<HMPServiceRegistration, QStringList> services;

  /**
   * Mapping of classname to registered service.
   * The List of registered services are ordered with the highest
   * ranked service first.
   */
  QHash<QString, QList<HMPServiceRegistration> > classServices;


  HMPPluginFrameworkContext* framework;

  HMPServices(HMPPluginFrameworkContext* fwCtx);

  ~HMPServices();

  void clear();

  /**
   * Register a service in the framework wide register.
   *
   * @param plugin The plugin registering the service.
   * @param classes The class names under which the service can be located.
   * @param service The service object.
   * @param properties The properties for this service.
   * @return A HMPServiceRegistration object.
   * @exception HMPInvalidArgumentException If one of the following is true:
   * <ul>
   * <li>The service object is 0.</li>
   * <li>The service parameter is not a HMPServiceFactory or an
   * instance of all the named classes in the classes parameter.</li>
   * </ul>
   */
  HMPServiceRegistration registerService(HMPPluginPrivate* plugin,
                               const QStringList& classes,
                               QObject* service,
                               const HMPDictionary& properties);


  /**
   * Service ranking changed, reorder registered services
   * according to ranking.
   *
   * @param serviceRegistration The HMPServiceRegistrationPrivate object.
   * @param rank New rank of object.
   */
  void updateServiceRegistrationOrder(const HMPServiceRegistration& sr,
                                      const QStringList& classes);


  /**
   * Checks that a given service object is an instance of the given
   * class name.
   *
   * @param service The service object to check.
   * @param cls     The class name to check for.
   */
  bool checkServiceClass(QObject* service, const QString& cls) const;


  /**
   * Get all services implementing a certain class.
   * Only used internally by the framework.
   *
   * @param clazz The class name of the requested service.
   * @return A sorted list of {@link HMPServiceRegistrationPrivate} objects.
   */
  QList<HMPServiceRegistration> get(const QString& clazz) const;


  /**
   * Get a service implementing a certain class.
   *
   * @param plugin The plugin requesting reference
   * @param clazz The class name of the requested service.
   * @return A {@link HMPServiceReference} object.
   */
  HMPServiceReference get(HMPPluginPrivate* plugin, const QString& clazz) const;


  /**
   * Get all services implementing a certain class and then
   * filter these with a property filter.
   *
   * @param clazz The class name of requested service.
   * @param filter The property filter.
   * @param plugin The plugin requesting reference.
   * @return A list of {@link HMPServiceReference} object.
   */
  QList<HMPServiceReference> get(const QString& clazz, const QString& filter,
                                 HMPPluginPrivate* plugin) const;


  /**
   * Remove a registered service.
   *
   * @param sr The HMPServiceRegistration object that is registered.
   */
  void removeServiceRegistration(const HMPServiceRegistration& sr) ;


  /**
   * Get all services that a plugin has registered.
   *
   * @param p The plugin
   * @return A set of {@link HMPServiceRegistration} objects
   */
  QList<HMPServiceRegistration> getRegisteredByPlugin(HMPPluginPrivate* p) const;


  /**
   * Get all services that a plugin uses.
   *
   * @param p The plugin
   * @return A set of {@link HMPServiceRegistration} objects
   */
  QList<HMPServiceRegistration> getUsedByPlugin(QSharedPointer<HMPPlugin> p) const;

private:

  QList<HMPServiceReference> get_unlocked(const QString& clazz, const QString& filter,
                                          HMPPluginPrivate* plugin) const;

};



#endif // HMPSERVICES_P_H
