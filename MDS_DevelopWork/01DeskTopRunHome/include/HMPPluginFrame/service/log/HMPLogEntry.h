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


#ifndef HMPLOGENTRY_H
#define HMPLOGENTRY_H

#include <QSharedPointer>
#include <QDateTime>
#include <QMetaType>

#include <HMPServiceReference.h>

class HMPRuntimeException;


/**
 * \ingroup LogService
 *
 * Provides methods to access the information contained in an individual Log
 * Service log entry.
 *
 * <p>
 * A <code>HMPLogEntry</code> object may be acquired from the
 * <code>HMPLogReaderService#getLog()</code> method or by registering a
 * <code>HMPLogListener</code> object.
 *
 * @remarks This class is thread safe.
 * @see HMPLogReaderService#getLog()
 * @see HMPLogListener
 */
struct HMPLogEntry
{
  virtual ~HMPLogEntry() {}

  /**
   * Returns the plugin that created this <code>HMPLogEntry</code> object.
   *
   * @return The plugin that created this <code>HMPLogEntry</code> object;
   *         null if no plugins is associated with this
   *         <code>HMPLogEntry</code> object.
   */
  virtual QSharedPointer<HMPPlugin> getPlugin() const = 0;

  /**
   * Returns the <code>HMPServiceReference</code> object for the service associated
   * with this <code>HMPLogEntry</code> object.
   *
   * @return <code>HMPServiceReference</code> object for the service associated
   *         with this <code>HMPLogEntry</code> object; A default constructed object if no
   *         <code>HMPServiceReference</code> object was provided.
   */
  virtual HMPServiceReference getServiceReference() const = 0;

  /**
   * Returns the severity level of this <code>HMPLogEntry</code> object.
   *
   * <p>
   * This is one of the severity levels defined by the <code>HMPLogService</code>
   * interface.
   *
   * @return Severity level of this <code>HMPLogEntry</code> object.
   *
   * @see HMPLogService#LOG_ERROR
   * @see HMPLogService#LOG_WARNING
   * @see HMPLogService#LOG_INFO
   * @see HMPLogService#LOG_DEBUG
   */
  virtual int getLevel() const = 0;

  /**
   * Returns the human readable message associated with this <code>HMPLogEntry</code>
   * object.
   *
   * @return <code>QString</code> containing the message associated with this
   *         <code>HMPLogEntry</code> object.
   */
  virtual QString getMessage() const = 0;

  /**
   * Returns the absolute file name of the source file with which this
   * <code>HMPLogEntry</code> is associated.
   *
   * @return The source file name or an empty string if no information
   *         about the file name is available.
   */
  virtual QString getFileName() const = 0;

  /**
   * Returns the function name of the calling function with which this
   * <code>HMPLogEntry</code> is associated.
   *
   * @return The function name or an empty string if no information
   *         about the function is available.
   */
  virtual QString getFunctionName() const = 0;

  /**
   * Returns the line number in the source file with which this
   * <code>HMPLogEntry</code> is associated.
   *
   * @return The line number (a positive integer) or 0 if no information
   *         about the line number is available.
   */
  virtual int getLineNumber() const = 0;

  /**
   * Returns the exception object associated with this <code>HMPLogEntry</code>
   * object.
   *
   * <p>
   * In some implementations, the returned exception may not be the original
   * exception. For example, STL exceptions associated with log entries may be wrapped
   * in a derived HMPRuntimeException. The returned object will attempt to provide as much
   * information as possible from the original exception object.
   *
   * @return <code>HMPRuntimeException</code> object of the exception associated with this
   *         <code>HMPLogEntry</code>; <code>null</code> if no exception is
   *         associated with this <code>HMPLogEntry</code> object.
   */
  virtual HMPRuntimeException* getException() const = 0;

  /**
   * Returns the value of <code>QDateTime::currentDateTime()</code> at the time this
   * <code>HMPLogEntry</code> object was created.
   *
   * @return The system time when this <code>HMPLogEntry</code>
   *         object was created.
   * @see "QDateTime::currentDateTime()"
   */
  virtual QDateTime getTime() const = 0;
};

/**
 * \ingroup LogService
 * @{
 */

typedef QSharedPointer<HMPLogEntry> HMPLogEntryPtr;

Q_DECLARE_METATYPE(HMPLogEntryPtr)

/** @}*/

#endif // HMPLOGENTRY_H
