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


#ifndef HMPSERVICETRACKER_H
#define HMPSERVICETRACKER_H

#include <QScopedPointer>

#include "HMPPluginFrameworkExport.h"

#include "HMPServiceReference.h"
#include "HMPServiceTrackerCustomizer.h"
#include "HMPLDAPSearchFilter.h"

template<class S, class T> class HMPTrackedService;
template<class S, class T> class HMPServiceTrackerPrivate;
class HMPPluginContext;

/**
 * \ingroup PluginFramework
 *
 * The <code>HMPServiceTracker</code> class simplifies using services from the
 * Framework's service registry.
 * <p>
 * A <code>HMPServiceTracker</code> object is constructed with search criteria and
 * a <code>HMPServiceTrackerCustomizer</code> object. A <code>HMPServiceTracker</code>
 * can use a <code>HMPServiceTrackerCustomizer</code> to customize the service
 * objects to be tracked. The <code>HMPServiceTracker</code> can then be opened to
 * begin tracking all services in the Framework's service registry that match
 * the specified search criteria. The <code>HMPServiceTracker</code> correctly
 * handles all of the details of listening to <code>HMPServiceEvent</code>s and
 * getting and ungetting services.
 * <p>
 * The <code>getServiceReferences</code> method can be called to get references
 * to the services being tracked. The <code>getService</code> and
 * <code>getServices</code> methods can be called to get the service objects for
 * the tracked service.
 * <p>
 * The <code>HMPServiceTracker</code> class is thread-safe. It does not call a
 * <code>HMPServiceTrackerCustomizer</code> while holding any locks.
 * <code>HMPServiceTrackerCustomizer</code> implementations must also be
 * thread-safe.
 *
 * \tparam S The type of the service being tracked. The type must be an
 *         assignable datatype. Further, if the
 *         <code>HMPServiceTracker(HMPPluginContext*, HMPServiceTrackerCustomizer<T>*)</code>
 *         constructor is used, the type must have an associated interface id via
 *         Q_DECLARE_INTERFACE.
 * \tparam T The type of the tracked object. The type must be an assignable
 *         datatype, provide a boolean conversion function, and provide
 *         a constructor and an assignment operator which can handle 0 as an argument.
 * \remarks This class is thread safe.
 */
template<class S = QObject*, class T = S>
class HMPServiceTracker : protected HMPServiceTrackerCustomizer<T>
{
public:

  ~HMPServiceTracker();

  /**
   * Create a <code>HMPServiceTracker</code> on the specified
   * <code>HMPServiceReference</code>.
   *
   * <p>
   * The service referenced by the specified <code>HMPServiceReference</code>
   * will be tracked by this <code>HMPServiceTracker</code>.
   *
   * @param context The <code>HMPPluginContext</code> against which the tracking
   *        is done.
   * @param reference The <code>HMPServiceReference</code> for the service to be
   *        tracked.
   * @param customizer The customizer object to call when services are added,
   *        modified, or removed in this <code>HMPServiceTracker</code>. If
   *        customizer is <code>null</code>, then this
   *        <code>HMPServiceTracker</code> will be used as the
   *        <code>HMPServiceTrackerCustomizer</code> and this
   *        <code>HMPServiceTracker</code> will call the
   *        <code>HMPServiceTrackerCustomizer</code> methods on itself.
   */
  HMPServiceTracker(HMPPluginContext* context,
                    const HMPServiceReference& reference,
                    HMPServiceTrackerCustomizer<T>* customizer = 0);

  /**
   * Create a <code>HMPServiceTracker</code> on the specified class name.
   *
   * <p>
   * Services registered under the specified class name will be tracked by
   * this <code>HMPServiceTracker</code>.
   *
   * @param context The <code>HMPPluginContext</code> against which the tracking
   *        is done.
   * @param clazz The class name of the services to be tracked.
   * @param customizer The customizer object to call when services are added,
   *        modified, or removed in this <code>HMPServiceTracker</code>. If
   *        customizer is <code>null</code>, then this
   *        <code>HMPServiceTracker</code> will be used as the
   *        <code>HMPServiceTrackerCustomizer</code> and this
   *        <code>HMPServiceTracker</code> will call the
   *        <code>HMPServiceTrackerCustomizer</code> methods on itself.
   */
  HMPServiceTracker(HMPPluginContext* context, const QString& clazz,
                    HMPServiceTrackerCustomizer<T>* customizer = 0);

  /**
   * Create a <code>HMPServiceTracker</code> on the specified
   * <code>HMPLDAPSearchFilter</code> object.
   *
   * <p>
   * Services which match the specified <code>HMPLDAPSearchFilter</code> object will be
   * tracked by this <code>HMPServiceTracker</code>.
   *
   * @param context The <code>HMPPluginContext</code> against which the tracking
   *        is done.
   * @param filter The <code>HMPLDAPSearchFilter</code> to select the services to be
   *        tracked.
   * @param customizer The customizer object to call when services are added,
   *        modified, or removed in this <code>HMPServiceTracker</code>. If
   *        customizer is null, then this <code>HMPServiceTracker</code> will be
   *        used as the <code>HMPServiceTrackerCustomizer</code> and this
   *        <code>HMPServiceTracker</code> will call the
   *        <code>HMPServiceTrackerCustomizer</code> methods on itself.
   */
  HMPServiceTracker(HMPPluginContext* context, const HMPLDAPSearchFilter& filter,
                    HMPServiceTrackerCustomizer<T>* customizer = 0);

  /**
   * Create a <code>HMPServiceTracker</code> on the class template
   * argument S.
   *
   * <p>
   * Services registered under the interface name of the class template
   * argument S will be tracked by this <code>HMPServiceTracker</code>.
   *
   * @param context The <code>HMPPluginContext</code> against which the tracking
   *        is done.
   * @param customizer The customizer object to call when services are added,
   *        modified, or removed in this <code>HMPServiceTracker</code>. If
   *        customizer is null, then this <code>HMPServiceTracker</code> will be
   *        used as the <code>HMPServiceTrackerCustomizer</code> and this
   *        <code>HMPServiceTracker</code> will call the
   *        <code>HMPServiceTrackerCustomizer</code> methods on itself.
   */
  HMPServiceTracker(HMPPluginContext* context, HMPServiceTrackerCustomizer<T>* customizer = 0);

  /**
   * Open this <code>HMPServiceTracker</code> and begin tracking services.
   *
   * <p>
   * Services which match the search criteria specified when this
   * <code>HMPServiceTracker</code> was created are now tracked by this
   * <code>HMPServiceTracker</code>.
   *
   * @throws HMPIllegalStateException If the <code>HMPPluginContext</code>
   *         with which this <code>HMPServiceTracker</code> was created is no
   *         longer valid.
   */
  virtual void open();

  /**
   * Close this <code>HMPServiceTracker</code>.
   *
   * <p>
   * This method should be called when this <code>HMPServiceTracker</code> should
   * end the tracking of services.
   *
   * <p>
   * This implementation calls getServiceReferences() to get the list
   * of tracked services to remove.
   */
  virtual void close();

  /**
   * Wait for at least one service to be tracked by this
   * <code>HMPServiceTracker</code>. This method will also return when this
   * <code>HMPServiceTracker</code> is closed.
   *
   * <p>
   * It is strongly recommended that <code>waitForService</code> is not used
   * during the calling of the <code>HMPPluginActivator</code> methods.
   * <code>HMPPluginActivator</code> methods are expected to complete in a short
   * period of time.
   *
   * <p>
   * This implementation calls getService() to determine if a service
   * is being tracked.
   *
   * @param timeout The time interval in milliseconds to wait. If zero, the
   *        method will wait indefinitely.
   * @return Returns the result of getService().
   */
  virtual T waitForService(unsigned long timeout);

  /**
   * Return a list of <code>HMPServiceReference</code>s for all services being
   * tracked by this <code>HMPServiceTracker</code>.
   *
   * @return List of <code>HMPServiceReference</code>s.
   */
  virtual QList<HMPServiceReference> getServiceReferences() const;

  /**
   * Returns a <code>HMPServiceReference</code> for one of the services being
   * tracked by this <code>HMPServiceTracker</code>.
   *
   * <p>
   * If multiple services are being tracked, the service with the highest
   * ranking (as specified in its <code>service.ranking</code> property) is
   * returned. If there is a tie in ranking, the service with the lowest
   * service ID (as specified in its <code>service.id</code> property); that
   * is, the service that was registered first is returned. This is the same
   * algorithm used by <code>HMPPluginContext::getServiceReference()</code>.
   *
   * <p>
   * This implementation calls getServiceReferences() to get the list
   * of references for the tracked services.
   *
   * @return A <code>HMPServiceReference</code> for a tracked service.
   * @throws HMPServiceException if no services are being tracked.
   */
  virtual HMPServiceReference getServiceReference() const;

  /**
   * Returns the service object for the specified
   * <code>HMPServiceReference</code> if the specified referenced service is
   * being tracked by this <code>HMPServiceTracker</code>.
   *
   * @param reference The reference to the desired service.
   * @return A service object or <code>null</code> if the service referenced
   *         by the specified <code>HMPServiceReference</code> is not being
   *         tracked.
   */
  virtual T getService(const HMPServiceReference& reference) const;

  /**
   * Return a list of service objects for all services being tracked by this
   * <code>HMPServiceTracker</code>.
   *
   * <p>
   * This implementation calls getServiceReferences() to get the list
   * of references for the tracked services and then calls
   * getService(const HMPServiceReference&) for each reference to get the
   * tracked service object.
   *
   * @return A list of service objects or an empty list if no services
   *         are being tracked.
   */
  virtual QList<T> getServices() const;

  /**
   * Returns a service object for one of the services being tracked by this
   * <code>HMPServiceTracker</code>.
   *
   * <p>
   * If any services are being tracked, this implementation returns the result
   * of calling <code>getService(getServiceReference())</code>.
   *
   * @return A service object or <code>null</code> if no services are being
   *         tracked.
   */
  virtual T getService() const;

  /**
   * Remove a service from this <code>HMPServiceTracker</code>.
   *
   * The specified service will be removed from this
   * <code>HMPServiceTracker</code>. If the specified service was being tracked
   * then the <code>HMPServiceTrackerCustomizer::removedService</code> method will
   * be called for that service.
   *
   * @param reference The reference to the service to be removed.
   */
  virtual void remove(const HMPServiceReference& reference);

  /**
   * Return the number of services being tracked by this
   * <code>HMPServiceTracker</code>.
   *
   * @return The number of services being tracked.
   */
  virtual int size() const;

  /**
   * Returns the tracking count for this <code>HMPServiceTracker</code>.
   *
   * The tracking count is initialized to 0 when this
   * <code>HMPServiceTracker</code> is opened. Every time a service is added,
   * modified or removed from this <code>HMPServiceTracker</code>, the tracking
   * count is incremented.
   *
   * <p>
   * The tracking count can be used to determine if this
   * <code>HMPServiceTracker</code> has added, modified or removed a service by
   * comparing a tracking count value previously collected with the current
   * tracking count value. If the value has not changed, then no service has
   * been added, modified or removed from this <code>HMPServiceTracker</code>
   * since the previous tracking count was collected.
   *
   * @return The tracking count for this <code>HMPServiceTracker</code> or -1 if
   *         this <code>HMPServiceTracker</code> is not open.
   */
  virtual int getTrackingCount() const;

  /**
   * Return a sorted <code>QMap</code> of the <code>HMPServiceReference</code>s and
   * service objects for all services being tracked by this
   * <code>HMPServiceTracker</code>. The map is sorted in natural order
   * of <code>HMPServiceReference</code>. That is, the last entry is the service
   * with the highest ranking and the lowest service id.
   *
   * @return A <code>QMap</code> with the <code>HMPServiceReference</code>s
   *         and service objects for all services being tracked by this
   *         <code>HMPServiceTracker</code>. If no services are being tracked,
   *         then the returned map is empty.
   */
  virtual QMap<HMPServiceReference, T> getTracked() const;

  /**
   * Return if this <code>HMPServiceTracker</code> is empty.
   *
   * @return <code>true</code> if this <code>HMPServiceTracker</code> is not tracking any
   *         services.
   */
  virtual bool isEmpty() const;

protected:

  /**
   * Default implementation of the
   * <code>HMPServiceTrackerCustomizer::addingService</code> method.
   *
   * <p>
   * This method is only called when this <code>HMPServiceTracker</code> has been
   * constructed with a <code>null</code> HMPServiceTrackerCustomizer argument.
   *
   * <p>
   * This implementation returns the result of calling <code>getService</code>
   * on the <code>HMPPluginContext</code> with which this
   * <code>HMPServiceTracker</code> was created passing the specified
   * <code>HMPServiceReference</code>.
   * <p>
   * This method can be overridden in a subclass to customize the service
   * object to be tracked for the service being added. In that case, take care
   * not to rely on the default implementation of
   * \link removedService(const HMPServiceReference&, T service) removedService\endlink
   * to unget the service.
   *
   * @param reference The reference to the service being added to this
   *        <code>HMPServiceTracker</code>.
   * @return The service object to be tracked for the service added to this
   *         <code>ctlServiceTracker</code>.
   * @see HMPServiceTrackerCustomizer::addingService(const HMPServiceReference&)
   */
  T addingService(const HMPServiceReference& reference);

  /**
   * Default implementation of the
   * <code>HMPServiceTrackerCustomizer::modifiedService</code> method.
   *
   * <p>
   * This method is only called when this <code>HMPServiceTracker</code> has been
   * constructed with a <code>null</code> HMPServiceTrackerCustomizer argument.
   *
   * <p>
   * This implementation does nothing.
   *
   * @param reference The reference to modified service.
   * @param service The service object for the modified service.
   * @see HMPServiceTrackerCustomizer::modifiedService(const HMPServiceReference&, QObject*)
   */
  void modifiedService(const HMPServiceReference& reference, T service);

  /**
   * Default implementation of the
   * <code>HMPServiceTrackerCustomizer::removedService</code> method.
   *
   * <p>
   * This method is only called when this <code>HMPServiceTracker</code> has been
   * constructed with a <code>null</code> HMPServiceTrackerCustomizer argument.
   *
   * <p>
   * This implementation calls <code>ungetService</code>, on the
   * <code>HMPPluginContext</code> with which this <code>HMPServiceTracker</code>
   * was created, passing the specified <code>HMPServiceReference</code>.
   * <p>
   * This method can be overridden in a subclass. If the default
   * implementation of \link addingService(const HMPServiceReference&) addingService\endlink
   * method was used, this method must unget the service.
   *
   * @param reference The reference to removed service.
   * @param service The service object for the removed service.
   * @see HMPServiceTrackerCustomizer::removedService(const ServiceReference&, QObject*)
   */
  void removedService(const HMPServiceReference& reference, T service);

private:

  typedef HMPServiceTracker<S,T> ServiceTracker;
  typedef HMPTrackedService<S,T> TrackedService;
  typedef HMPServiceTrackerPrivate<S,T> ServiceTrackerPrivate;
  typedef HMPServiceTrackerCustomizer<T> ServiceTrackerCustomizer;

  friend class HMPTrackedService<S,T>;
  friend class HMPServiceTrackerPrivate<S,T>;

  inline ServiceTrackerPrivate* d_func()
  {
    return reinterpret_cast<ServiceTrackerPrivate*>(qGetPtrHelper(d_ptr));
  }

  inline const ServiceTrackerPrivate* d_func() const
  {
    return reinterpret_cast<const ServiceTrackerPrivate*>(qGetPtrHelper(d_ptr));
  }

  const QScopedPointer<ServiceTrackerPrivate> d_ptr;
};

#include "HMPServiceTracker.tpp"

#endif // HMPSERVICETRACKER_H
