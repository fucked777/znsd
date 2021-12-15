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


#ifndef HMPSERVICETRACKERCUSTOMIZER_H
#define HMPSERVICETRACKERCUSTOMIZER_H

#include <HMPServiceReference.h>


/**
 * \ingroup PluginFramework
 *
 * The <code>HMPServiceTrackerCustomizer</code> interface allows a
 * <code>HMPServiceTracker</code> to customize the service objects that are
 * tracked. A <code>HMPServiceTrackerCustomizer</code> is called when a service is
 * being added to a <code>HMPServiceTracker</code>. The
 * <code>HMPServiceTrackerCustomizer</code> can then return an object for the
 * tracked service. A <code>HMPServiceTrackerCustomizer</code> is also called when
 * a tracked service is modified or has been removed from a
 * <code>HMPServiceTracker</code>.
 *
 * <p>
 * The methods in this interface may be called as the result of a
 * <code>HMPServiceEvent</code> being received by a <code>HMPServiceTracker</code>.
 * Since <code>HMPServiceEvent</code>s are synchronously delivered by the
 * Framework, it is highly recommended that implementations of these methods do
 * not register (<code>HMPPluginContext::registerService</code>), modify (
 * <code>HMPServiceRegistration::setProperties</code>) or unregister (
 * <code>HMPServiceRegistration::unregister</code>) a service while being
 * synchronized on any object.
 *
 * <p>
 * The <code>HMPServiceTracker</code> class is thread-safe. It does not call a
 * <code>HMPServiceTrackerCustomizer</code> while holding any locks.
 * <code>HMPServiceTrackerCustomizer</code> implementations must also be
 * thread-safe.
 *
 * \tparam T The type of the tracked object.
 * \remarks This class is thread safe.
 */
template<class T = QObject*>
struct HMPServiceTrackerCustomizer {

  virtual ~HMPServiceTrackerCustomizer() {}

  /**
   * A service is being added to the <code>HMPServiceTracker</code>.
   *
   * <p>
   * This method is called before a service which matched the search
   * parameters of the <code>HMPServiceTracker</code> is added to the
   * <code>HMPServiceTracker</code>. This method should return the service object
   * to be tracked for the specified <code>HMPServiceReference</code>. The
   * returned service object is stored in the <code>HMPServiceTracker</code> and
   * is available from the <code>getService</code> and
   * <code>getServices</code> methods.
   *
   * @param reference The reference to the service being added to the
   *        <code>HMPServiceTracker</code>.
   * @return The service object to be tracked for the specified referenced
   *         service or <code>0</code> if the specified referenced service
   *         should not be tracked.
   */
  virtual T addingService(const HMPServiceReference& reference) = 0;

  /**
   * A service tracked by the <code>HMPServiceTracker</code> has been modified.
   *
   * <p>
   * This method is called when a service being tracked by the
   * <code>HMPServiceTracker</code> has had it properties modified.
   *
   * @param reference The reference to the service that has been modified.
   * @param service The service object for the specified referenced service.
   */
  virtual void modifiedService(const HMPServiceReference& reference, T service) = 0;

  /**
   * A service tracked by the <code>HMPServiceTracker</code> has been removed.
   *
   * <p>
   * This method is called after a service is no longer being tracked by the
   * <code>HMPServiceTracker</code>.
   *
   * @param reference The reference to the service that has been removed.
   * @param service The service object for the specified referenced service.
   */
  virtual void removedService(const HMPServiceReference& reference, T service) = 0;
};

#endif // HMPSERVICETRACKERCUSTOMIZER_H
