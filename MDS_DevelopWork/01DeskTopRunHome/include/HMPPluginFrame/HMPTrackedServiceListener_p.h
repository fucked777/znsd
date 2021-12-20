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


#ifndef HMPTRACKEDSERVICELISTENER_P_H
#define HMPTRACKEDSERVICELISTENER_P_H

#include <QObject>

#include "HMPServiceEvent.h"

/**
 * \ingroup PluginFramework
 */
class HMP_PLUGINFW_EXPORT HMPTrackedServiceListener : public QObject
{
  Q_OBJECT

public:
  HMPTrackedServiceListener(QObject *parent = 0)
    : QObject(parent)
  {}

public Q_SLOTS:

  /**
   * Slot connected to service events for the
   * <code>HMPServiceTracker</code> class. This method must NOT be
   * synchronized to avoid deadlock potential.
   *
   * @param event <code>HMPServiceEvent</code> object from the framework.
   */
  virtual void serviceChanged(const HMPServiceEvent& event) = 0;

};

#endif // HMPTRACKEDSERVICELISTENER_P_H
