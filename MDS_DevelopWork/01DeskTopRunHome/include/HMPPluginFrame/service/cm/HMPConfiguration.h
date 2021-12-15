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


#ifndef HMPCONFIGURATION_H
#define HMPCONFIGURATION_H

#include <QSharedPointer>

#include "HMPDictionary.h"


/**
 * \ingroup ConfigAdmin
 * The configuration information for a <code>HMPManagedService</code> or
 * <code>HMPManagedServiceFactory</code> object.
 *
 * The Configuration Admin service uses this interface to represent the
 * configuration information for a <code>HMPManagedService</code> or for a
 * service instance of a <code>HMPManagedServiceFactory</code>.
 *
 * <p>
 * A <code>HMPConfiguration</code> object contains a configuration dictionary and
 * allows the properties to be updated via this object. Plugins wishing to
 * receive configuration dictionaries do not need to use this class - they
 * register a <code>HMPManagedService</code> or
 * <code>HMPManagedServiceFactory</code>. Only administrative plugins, and
 * plugins wishing to update their own configurations need to use this class.
 *
 * <p>
 * The properties handled in this configuration have case insensitive
 * <code>QString</code> objects as keys. However, case is preserved from the
 * last set key/value.
 * <p>
 * A configuration can be <i>bound </i> to a plugin location (
 * <code>HMPPlugin#getLocation()</code>). The purpose of binding a
 * <code>HMPConfiguration</code> object to a location is to make it impossible
 * for another plugin to forge a PID that would match this configuration. When a
 * configuration is bound to a specific location, and a plugin with a different
 * location registers a corresponding <code>HMPManagedService</code> object or
 * <code>HMPManagedServiceFactory</code> object, then the configuration is not
 * passed to the updated method of that object.
 *
 * <p>
 * If a configuration's location is empty, it is not yet bound to
 * a location. It will become bound to the location of the first plugin that
 * registers a <code>HMPManagedService</code> or
 * <code>HMPManagedServiceFactory</code> object with the corresponding PID.
 * <p>
 * The same <code>HMPConfiguration</code> object is used for configuring both a
 * Managed Service Factory and a Managed Service. When it is important to
 * differentiate between these two the term "factory configuration" is used.
 */
struct HMP_PLUGINFW_EXPORT HMPConfiguration
{

  virtual ~HMPConfiguration();

  /**
   * Get the PID for this <code>HMPConfiguration</code> object.
   *
   * @return the PID for this <code>HMPConfiguration</code> object.
   * @throws HMPIllegalStateException if this configuration has been deleted
   */
  virtual QString getPid() const = 0;

  /**
   * Return the properties of this <code>HMPConfiguration</code> object.
   *
   * The <code>Dictionary</code> object returned is a private copy for the
   * caller and may be changed without influencing the stored configuration.
   * The keys in the returned dictionary are case insensitive and are always
   * of type <code>String</code>.
   *
   * <p>
   * If called just after the configuration is created and before update has
   * been called, this method returns <code>null</code>.
   *
   * @return A private copy of the properties for the caller or
   *         <code>null</code>. These properties must not contain the
   *         "service.bundleLocation" property. The value of this property may
   *         be obtained from the <code>getBundleLocation</code> method.
   * @throws IllegalStateException if this configuration has been deleted
   */
  virtual HMPDictionary getProperties() const = 0;

  /**
   * Update the properties of this <code>HMPConfiguration</code> object.
   *
   * Stores the properties in persistent storage after adding or overwriting
   * the following properties:
   * <ul>
   * <li>"service.pid" : is set to be the PID of this configuration.</li>
   * <li>"service.factoryPid" : if this is a factory configuration it is set
   * to the factory PID else it is not set.</li>
   * </ul>
   * These system properties are all of type <code>QString</code>.
   *
   * <p>
   * If the corresponding Managed Service/Managed Service Factory is
   * registered, its updated method must be called asynchronously. Else, this
   * callback is delayed until aforementioned registration occurs.
   *
   * <p>
   * Also initiates an asynchronous call to all
   * <code>HMPConfigurationListener</code>s with a
   * <code>HMPConfigurationEvent::CM_UPDATED</code> event.
   *
   * @param properties the new set of properties for this configuration
   * @throws HMPIOException if update cannot be made persistent
   * @throws HMPInvalidArgumentException if the <code>HMPDictionary</code> object
   *         contains invalid configuration types or contains case variants of
   *         the same key name.
   * @throws HMPIllegalStateException if this configuration has been deleted
   */
  virtual void update(const HMPDictionary& properties) = 0;

  /**
   * Delete this <code>HMPConfiguration</code> object.
   *
   * Removes this configuration object from the persistent store. Notify
   * asynchronously the corresponding Managed Service or Managed Service
   * Factory. A <code>HMPManagedService</code> object is notified by a call to
   * its <code>updated</code> method with a <code>null</code> properties
   * argument. A <code>HMPManagedServiceFactory</code> object is notified by a
   * call to its <code>deleted</code> method.
   *
   * <p>
   * Also initiates an asynchronous call to all
   * <code>HMPConfigurationListener</code>s with a
   * <code>HMPConfigurationEvent::CM_DELETED</code> event.
   *
   * @throws HMPIOException If delete fails
   * @throws HMPIllegalStateException if this configuration has been deleted
   */
  virtual void remove() = 0;

  /**
   * For a factory configuration return the PID of the corresponding Managed
   * Service Factory, else return a null QString.
   *
   * @return factory PID or <code>null</code>
   * @throws HMPIllegalStateException if this configuration has been deleted
   */
  virtual QString getFactoryPid() const = 0;

  /**
   * Update the <code>HMPConfiguration</code> object with the current
   * properties.
   *
   * Initiate the <code>updated</code> callback to the Managed Service or
   * Managed Service Factory with the current properties asynchronously.
   *
   * <p>
   * This is the only way for a plugin that uses a Configuration Plugin
   * service to initiate a callback. For example, when that plugin detects a
   * change that requires an update of the Managed Service or Managed Service
   * Factory via its <code>HMPConfigurationPlugin</code> object.
   *
   * @see HMPConfigurationPlugin
   * @throws HMPIOException if update cannot access the properties in persistent
   *         storage
   * @throws HMPIllegalStateException if this configuration has been deleted
   */
  virtual void update() = 0;

  /**
   * Bind this <code>HMPConfiguration</code> object to the specified plugin
   * location.
   *
   * If the pluginLocation parameter is <code>null</code> then the
   * <code>HMPConfiguration</code> object will not be bound to a location. It
   * will be set to the plugin's location before the first time a Managed
   * Service/Managed Service Factory receives this <code>HMPConfiguration</code>
   * object via the updated method and before any plugins are called. The
   * plugin location will be set persistently.
   *
   * @param pluginLocation a plugin location or <code>null</code>.
   * @throws HMPIllegalStateException If this configuration has been deleted.
   * @throws HMPSecurityException If the caller does not have
   *         <code>HMPConfigurationPermission[*,CONFIGURE]</code>.
   */
  virtual void setPluginLocation(const QString& pluginLocation) = 0;

  /**
   * Get the plugin location.
   *
   * Returns the plugin location to which this configuration is bound, or
   * <code>null</code> if it is not yet bound to a plugin location.
   *
   * @return location to which this configuration is bound, or
   *         <code>null</code>.
   * @throws HMPIllegalStateException If this <code>Configuration</code> object
   *         has been deleted.
   * @throws HMPSecurityException If the caller does not have
   *         <code>HMPConfigurationPermission[*,CONFIGURE]</code>.
   */
  virtual QString getPluginLocation() const = 0;

  /**
   * Equality is defined to have equal PIDs
   *
   * Two Configuration objects are equal when their PIDs are equal.
   *
   * @param other <code>HMPConfiguration</code> object to compare against
   * @return <code>true</code> if equal, <code>false</code> if the PID's differ.
   */
  bool operator==(const HMPConfiguration& other) const;

};

/**
 * \ingroup ConfigAdmin
 * @{
 */

typedef QSharedPointer<HMPConfiguration> HMPConfigurationPtr;

/**
 * Hash code is based on PID.
 *
 * The hashcode for two HMPConfiguration objects must be the same when the
 * Configuration PID's are the same.
 *
 * @param configuration The configuration object for which to compute the hash value.
 * @return hash code for this HMPConfiguration object
 */
uint HMP_PLUGINFW_EXPORT qHash(HMPConfigurationPtr configuration);

bool HMP_PLUGINFW_EXPORT operator==(const HMPConfigurationPtr& c1, const HMPConfigurationPtr c2);

/** @}*/

#endif // HMPCONFIGURATION_H
