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


#ifndef HMPSERVICETRACKERPRIVATE_H
#define HMPSERVICETRACKERPRIVATE_H

#include "HMPServiceReference.h"
#include "HMPLDAPSearchFilter.h"

#include <QMutex>
#include <QSharedPointer>

/**
 * \ingroup PluginFramework
 */
template<class S, class T>
class HMPServiceTrackerPrivate
{

public:

  HMPServiceTrackerPrivate(HMPServiceTracker<S,T>* st,
                           HMPPluginContext* context,
                           const HMPServiceReference& reference,
                           HMPServiceTrackerCustomizer<T>* customizer);

  HMPServiceTrackerPrivate(HMPServiceTracker<S,T>* st,
      HMPPluginContext* context, const QString& clazz,
      HMPServiceTrackerCustomizer<T>* customizer);

  HMPServiceTrackerPrivate(
      HMPServiceTracker<S,T>* st,
      HMPPluginContext* context, const HMPLDAPSearchFilter& filter,
      HMPServiceTrackerCustomizer<T>* customizer);

  ~HMPServiceTrackerPrivate();

  /**
   * Returns the list of initial <code>HMPServiceReference</code>s that will be
   * tracked by this <code>HMPServiceTracker</code>.
   *
   * @param className The class name with which the service was registered, or
   *        <code>null</code> for all services.
   * @param filterString The filter criteria or <code>null</code> for all
   *        services.
   * @return The list of initial <code>HMPServiceReference</code>s.
   * @throws HMPInvalidArgumentException If the specified filterString has an
   *         invalid syntax.
   */
  QList<HMPServiceReference> getInitialReferences(const QString& className,
                                                  const QString& filterString);

  QList<HMPServiceReference> getServiceReferences_unlocked(HMPTrackedService<S,T>* t) const;

  /* set this to true to compile in debug messages */
  static const bool	DEBUG_FLAG; //	= false;

  /**
   * The Plugin Context used by this <code>HMPServiceTracker</code>.
   */
  HMPPluginContext* const	context;

  /**
   * The filter used by this <code>HMPServiceTracker</code> which specifies the
   * search criteria for the services to track.
   */
  HMPLDAPSearchFilter	filter;

  /**
   * The <code>HMPServiceTrackerCustomizer</code> for this tracker.
   */
  HMPServiceTrackerCustomizer<T>* customizer;

  /**
   * Filter string for use when adding the ServiceListener. If this field is
   * set, then certain optimizations can be taken since we don't have a user
   * supplied filter.
   */
  QString listenerFilter;

  /**
   * Class name to be tracked. If this field is set, then we are tracking by
   * class name.
   */
  QString trackClass;

  /**
   * Reference to be tracked. If this field is set, then we are tracking a
   * single HMPServiceReference.
   */
  HMPServiceReference	trackReference;

  /**
   * Tracked services: <code>HMPServiceReference</code> -> customized Object and
   * <code>HMPServiceSlotEntry</code> object
   */
  QSharedPointer<HMPTrackedService<S,T> > trackedService;

  /**
   * Accessor method for the current HMPTrackedService object. This method is only
   * intended to be used by the unsynchronized methods which do not modify the
   * trackedService field.
   *
   * @return The current Tracked object.
   */
  QSharedPointer<HMPTrackedService<S,T> > tracked() const;

  /**
   * Called by the HMPTrackedService object whenever the set of tracked services is
   * modified. Clears the cache.
   */
  /*
   * This method must not be synchronized since it is called by HMPTrackedService while
   * HMPTrackedService is synchronized. We don't want synchronization interactions
   * between the listener thread and the user thread.
   */
  void modified();

  /**
   * Cached HMPServiceReference for getServiceReference.
   */
  mutable HMPServiceReference cachedReference;

  /**
   * Cached service object for getService.
   *
   * This field is volatile since it is accessed by multiple threads.
   */
  mutable T volatile cachedService;

  mutable QMutex mutex;

private:

  inline HMPServiceTracker<S,T>* q_func()
  {
    return static_cast<HMPServiceTracker<S,T> *>(q_ptr);
  }

  inline const HMPServiceTracker<S,T>* q_func() const
  {
    return static_cast<const HMPServiceTracker<S,T> *>(q_ptr);
  }

  friend class HMPServiceTracker<S,T>;

  HMPServiceTracker<S,T> * const q_ptr;

};

#include "HMPServiceTracker_p.tpp"

#endif // HMPSERVICETRACKERPRIVATE_H
