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


#ifndef HMPPLUGINTRACKERPRIVATE_H
#define HMPPLUGINTRACKERPRIVATE_H

#include "HMPPlugin.h"

#include <QSharedPointer>
#include <QMutex>

/**
 * \ingroup PluginFramework
 */
template<class T>
class HMPPluginTrackerPrivate
{
public:
  HMPPluginTrackerPrivate(HMPPluginTracker<T>* pt,
                          HMPPluginContext* context, HMPPlugin::States stateMask,
                          HMPPluginTrackerCustomizer<T>* customizer);

  ~HMPPluginTrackerPrivate();

  /**
   * Accessor method for the current HMPTrackedPlugin object. This method is only
   * intended to be used by the unsynchronized methods which do not modify the
   * trackedPlugin field.
   *
   * @return The current HMPTrackedPlugin object.
   */
  QSharedPointer<HMPTrackedPlugin<T> > tracked() const;

  /* set this to true to compile in debug messages */
  static const bool DEBUG_FLAG; //	= false;

  /**
   * The Bundle Context used by this <code>HMPPluginTracker</code>.
   */
  HMPPluginContext* const context;

  /**
   * The <code>HMPPluginTrackerCustomizer</code> object for this tracker.
   */
  HMPPluginTrackerCustomizer<T>* customizer;

  /**
   * Tracked plugins: <code>HMPPlugin</code> object -> customized Object and
   * plugin listener slot.
   */
  QSharedPointer<HMPTrackedPlugin<T> > trackedPlugin;

  /**
   * State mask for plugins being tracked. This field contains the ORed values
   * of the plugin states being tracked.
   */
  HMPPlugin::States mask;

  mutable QMutex mutex;

private:

  inline HMPPluginTracker<T>* q_func()
  {
    return static_cast<HMPPluginTracker<T> *>(q_ptr);
  }

  inline const HMPPluginTracker<T>* q_func() const
  {
    return static_cast<const HMPPluginTracker<T> *>(q_ptr);
  }

  friend class HMPPluginTracker<T>;

  HMPPluginTracker<T> * const q_ptr;
};

#include "HMPPluginTracker_p.tpp"

#endif // HMPPLUGINTRACKERPRIVATE_H
