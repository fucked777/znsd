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


#ifndef HMPSERVICESLOTENTRY_P_H
#define HMPSERVICESLOTENTRY_P_H


#include <QHash>
#include <QList>
#include <QString>
#include <QStringList>
#include <QExplicitlySharedDataPointer>

#include "HMPServiceEvent.h"
#include "HMPLDAPExpr_p.h"

class HMPPlugin;
class HMPServiceSlotEntryData;

class QObject;


/**
 * \ingroup PluginFramework
 *
 * Data structure for saving information about slots registered for
 * receiving service lifecycle events.
 */
class HMPServiceSlotEntry
{

public:

  HMPServiceSlotEntry(QSharedPointer<HMPPlugin> p, QObject* receiver, const char* slot,
                      const QString& filter = QString());

  HMPServiceSlotEntry(const HMPServiceSlotEntry& other);

  // default constructor for use in QSet
  HMPServiceSlotEntry();
  ~HMPServiceSlotEntry();

  // assignment operator for use in QSet
  HMPServiceSlotEntry& operator=(const HMPServiceSlotEntry& other);

  bool operator==(const HMPServiceSlotEntry& other) const;

  void invokeSlot(const HMPServiceEvent& event);

  void setRemoved(bool removed);

  bool isRemoved() const;

  QSharedPointer<HMPPlugin> getPlugin() const;

  HMPLDAPExpr getLDAPExpr() const;

  QString getFilter() const;

  HMPLDAPExpr::LocalCache& getLocalCache() const;

private:

  friend uint qHash(const HMPServiceSlotEntry& serviceSlot);

  QExplicitlySharedDataPointer<HMPServiceSlotEntryData> d;

};

/**
 * \ingroup PluginFramework
 */
uint qHash(const HMPServiceSlotEntry& serviceSlot);

#endif // HMPSERVICESLOTENTRY_P_H
