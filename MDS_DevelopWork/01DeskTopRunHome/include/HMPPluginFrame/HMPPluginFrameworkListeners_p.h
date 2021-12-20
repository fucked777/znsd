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

#ifndef HMPPLUGINFRAMEWORKLISTENERS_H
#define HMPPLUGINFRAMEWORKLISTENERS_H

#include <QObject>
#include <QHash>
#include <QSet>
#include <QMutex>

#include "HMPPluginEvent.h"
#include "HMPPluginFrameworkEvent.h"
#include "HMPServiceReference.h"
#include "HMPServiceSlotEntry_p.h"
#include "HMPServiceEvent.h"

/**
 * \ingroup PluginFramework
 */
class HMPPluginFrameworkListeners : public QObject
{

  Q_OBJECT

public:

  HMPPluginFrameworkListeners(HMPPluginFrameworkContext* pluginFw);

  /**
   * Add a slot receiving service envents with filter to the current framework.
   * If no filter is wanted, call with a null filter.
   *
   * @param plugin Who wants to add the slot.
   * @param listener Object to add.
   * @param filter LDAP String used for filtering event before calling listener.
   */
  void addServiceSlot(QSharedPointer<HMPPlugin> plugin, QObject* receiver,
                      const char* slot, const QString& filter);

  /**
   * Remove a slot connected to service events.
   *
   * @param plugin The plugin removing this listener.
   * @param receiver The receiver containing the slot.
   * @param slot The slot in the receiver.
   */
  void removeServiceSlot(QSharedPointer<HMPPlugin> plugin, QObject* receiver,
                         const char* slot);

  /**
   * Gets the slots interested in modifications of the service reference
   *
   * @param sr The reference related to the event describing the service modification.
   * @param lockProps If access to the properties of the service object referenced by sr
   *        should be synchronized.
   * @return A set of listeners to notify.
   */
  QSet<HMPServiceSlotEntry> getMatchingServiceSlots(const HMPServiceReference& sr, bool lockProps = true);

  /**
   * Convenience method for throwing framework error event.
   *
   * @param p Plugin which caused the error.
   * @param e The exception.
   */
  void frameworkError(QSharedPointer<HMPPlugin> p, const HMPException& e);

  /**
   * Receive notification that a service has had a change occur in its lifecycle.
   */
  void serviceChanged(const QSet<HMPServiceSlotEntry>& receivers,
                      const HMPServiceEvent& evt,
                      QSet<HMPServiceSlotEntry>& matchBefore);

  void serviceChanged(const QSet<HMPServiceSlotEntry>& receivers,
                      const HMPServiceEvent& evt);

  void emitPluginChanged(const HMPPluginEvent& event);

  void emitFrameworkEvent(const HMPPluginFrameworkEvent& event);

Q_SIGNALS:

  void pluginChangedDirect(const HMPPluginEvent& event);
  void pluginChangedQueued(const HMPPluginEvent& event);

  void frameworkEvent(const HMPPluginFrameworkEvent& event);

private Q_SLOTS:

  void serviceListenerDestroyed(QObject* listener);

private:

  QMutex mutex;

  QList<QString> hashedServiceKeys;
  static const int OBJECTCLASS_IX; // = 0;
  static const int SERVICE_ID_IX; // = 1;
  static const int SERVICE_PID_IX; // = 2;

  // Service listeners with complicated or empty filters
  QList<HMPServiceSlotEntry> complicatedListeners;

  // Service listeners with "simple" filters are cached
  QList<QHash<QString, QList<HMPServiceSlotEntry> > > cache;

  QSet<HMPServiceSlotEntry> serviceSet;

  HMPPluginFrameworkContext* pluginFw;

  /**
   * Remove all references to a service slot from the service listener
   * cache.
   */
  void removeFromCache(const HMPServiceSlotEntry& sse);

  /**
   * Checks if the specified service slot's filter is simple enough
   * to cache.
   */
  void checkSimple(const HMPServiceSlotEntry& sse);

  /**
   * Add all members of the specified list to the specified set.
   */
  void addToSet(QSet<HMPServiceSlotEntry>& set, int cache_ix, const QString& val);

  /**
   * The unsynchronized version of removeServiceSlot().
   */
  void removeServiceSlot_unlocked(QSharedPointer<HMPPlugin> plugin, QObject* receiver,
                                  const char* slot);
};


#endif // HMPPLUGINFRAMEWORKLISTENERS_H
