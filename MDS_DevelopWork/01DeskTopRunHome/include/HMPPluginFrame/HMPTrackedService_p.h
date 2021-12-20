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


#ifndef HMPTRACKEDSERVICE_P_H
#define HMPTRACKEDSERVICE_P_H

#include "HMPTrackedServiceListener_p.h"
#include "HMPPluginAbstractTracked_p.h"
#include "HMPServiceEvent.h"

/**
 * \ingroup PluginFramework
 */
template<class S, class T>
class HMPTrackedService : public HMPTrackedServiceListener,
    public HMPPluginAbstractTracked<HMPServiceReference, T, HMPServiceEvent>
{

public:
  HMPTrackedService(HMPServiceTracker<S,T>* serviceTracker,
                    HMPServiceTrackerCustomizer<T>* customizer);

  /**
   * Slot connected to service events for the
   * <code>HMPServiceTracker</code> class. This method must NOT be
   * synchronized to avoid deadlock potential.
   *
   * @param event <code>HMPServiceEvent</code> object from the framework.
   */
  void serviceChanged(const HMPServiceEvent& event);

private:

  typedef HMPPluginAbstractTracked<HMPServiceReference, T, HMPServiceEvent> Superclass;

  HMPServiceTracker<S,T>* serviceTracker;
  HMPServiceTrackerCustomizer<T>* customizer;

  /**
   * Increment the tracking count and tell the tracker there was a
   * modification.
   *
   * @GuardedBy this
   */
  void modified();

  /**
   * Call the specific customizer adding method. This method must not be
   * called while synchronized on this object.
   *
   * @param item Item to be tracked.
   * @param related Action related object.
   * @return Customized object for the tracked item or <code>null</code>
   *         if the item is not to be tracked.
   */
  T customizerAdding(HMPServiceReference item, const HMPServiceEvent& related);

  /**
   * Call the specific customizer modified method. This method must not be
   * called while synchronized on this object.
   *
   * @param item Tracked item.
   * @param related Action related object.
   * @param object Customized object for the tracked item.
   */
  void customizerModified(HMPServiceReference item,
                          const HMPServiceEvent& related, T object) ;

  /**
   * Call the specific customizer removed method. This method must not be
   * called while synchronized on this object.
   *
   * @param item Tracked item.
   * @param related Action related object.
   * @param object Customized object for the tracked item.
   */
  void customizerRemoved(HMPServiceReference item,
                         const HMPServiceEvent& related, T object) ;
};

#include "HMPTrackedService.tpp"

#endif // HMPTRACKEDSERVICE_P_H
