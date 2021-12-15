/*=============================================================================

  Library: HMP

  Copyright (c) 2010 German Cancer Research Center,
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


#ifndef HMPLOGREADERSERVICE_H
#define HMPLOGREADERSERVICE_H

#include <QList>

#include "HMPLogEntry.h"

/**
 * \ingroup LogService
 *
 * Provides methods to retrieve <code>HMPLogEntry</code> objects from the log.
 * <p>
 * There are three ways to retrieve <code>HMPLogEntry</code> objects:
 * <ul>
 * <li>The primary way to retrieve <code>HMPLogEntry</code> objects is to register a
 * <code>HMPLogListener</code> object with the service registry whose
 * <code>HMPLogListener#logged()</code> method will
 * be called for each entry added to the log. This way you do not need to retrieve
 * any service object to express an interest in log entries.
 * <li>A Qt slot can be connected to the <code>HMPLogReaderService</code> by using
 * <code>connectLogListener()</code>.
 * <li>To retrieve past <code>HMPLogEntry</code> objects, the <code>getLog()</code>
 * method can be called which will return a QList of all
 * <code>HMPLogEntry</code> objects in the log.
 * </ul>
 *
 * @remarks This class is thread safe.
 * @see HMPLogEntry
 * @see HMPLogListener
 * @see HMPLogListener#logged(HMPLogEntryPtr)
 */
struct HMPLogReaderService
{
  virtual ~HMPLogReaderService() {}

  /**
   * Subscribes to <code>HMPLogEntry</code> objects.
   *
   * <p>
   * This method connects a Qt slot with the Log Reader
   * Service. The slot must take a <code>HMPLogEntryPtr</code> as the
   * only argument and will be
   * called for each <code>HMPLogEntry</code> object placed into the log.
   *
   * <p>
   * When a plugin which connects a Qt slot is stopped, the Log Reader
   * Service must disconnect all of the plugin's connected slots.
   *
   * <p>
   * If the same slot from the same object is already connected, this
   * method does nothing.
   *
   * @param receiver The object to connect to.
   * @param slot The name of the slot to be connected.
   * @returns <code>true</code> if the connection was successfull;
   *          <code>false</code> otherwise.
   * @see HMPLogListener
   * @see HMPLogEntry
   * @see HMPLogListener#logged(HMPLogEntryPtr)
   */
  virtual bool connectLogListener(const QObject* receiver, const char* slot) = 0;

  /**
   * Returns a QList of all <code>HMPLogEntry</code> objects in
   * the log.
   *
   * <p>
   * Each element of the QList is a <code>HMPLogEntry</code> object, ordered
   * with the most recent entry first. Whether the list is of all
   * <code>HMPLogEntry</code> objects since the Log Service was started or some
   * recent past is implementation-specific. Also implementation-specific is
   * whether informational and debug <code>HMPLogEntry</code> objects are included
   * in the list.
   * @return A QList of all <code>HMPLogEntry</code> objects in
   * the log.
   */
  virtual QList<HMPLogEntryPtr> getLog() = 0;
};

Q_DECLARE_INTERFACE(HMPLogReaderService, "org.commontk.service.log.LogReaderService")

#endif // HMPLOGREADERSERVICE_H
