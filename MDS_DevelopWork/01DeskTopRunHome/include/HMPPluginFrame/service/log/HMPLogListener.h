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


#ifndef HMPLOGLISTENER_H
#define HMPLOGLISTENER_H

#include "HMPLogEntry.h"

/**
 * \ingroup LogService
 *
 * Subscribes to <code>HMPLogEntry</code> objects from the <code>HMPLogReaderService</code>.
 *
 * <p>
 * <code>HMPLogListener</code> objects may be registered with the Framework service
 * registry. After the listener is registered, the <code>logged(HMPLogEntryPtr)</code>
 * method will be called for each <code>HMPLogEntry</code> object created.
 *
 * <p>
 * Qt slots can also be used to be notified about new <code>HMPLogEntry</code>
 * objects. See <code>HMPLogReaderService#connectLogListener()</code>.
 *
 * @remarks This class is thread safe.
 * @see HMPLogReaderService
 * @see HMPLogEntry
 * @see HMPLogReaderService#connectLogListener()
 * @see HMPLogReaderService#disconnectLogListener()
 */
struct HMPLogListener
{
  virtual ~HMPLogListener() {}

  /**
   * Listener method called for each HMPLogEntry object created.
   *
   * <p>
   * As with all event listeners, this method should return to its caller as
   * soon as possible.
   *
   * @param entry A <code>HMPLogEntry</code> object containing log information.
   * @see HMPLogEntry
   */
  virtual void logged(HMPLogEntryPtr entry) = 0;
};

Q_DECLARE_INTERFACE(HMPLogListener, "org.commontk.service.log.LogListener")

#endif // HMPLOGLISTENER_H
