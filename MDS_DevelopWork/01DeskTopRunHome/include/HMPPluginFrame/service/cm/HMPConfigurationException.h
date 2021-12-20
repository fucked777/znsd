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


#ifndef HMPCONFIGURATIONEXCEPTION_H
#define HMPCONFIGURATIONEXCEPTION_H

#include "HMPException.h"

#include <HMPPluginFrameworkEvent.h>

/**
 * \ingroup ConfigAdmin
 *
 * An exception class to inform the Configuration Admin service
 * of problems with configuration data.
 */
class HMP_PLUGINFW_EXPORT HMPConfigurationException : public HMPRuntimeException
{

public:

  /**
   * Create a <code>HMPConfigurationException</code> object.
   *
   * @param property name of the property that caused the problem,
   *        <code>null</code> if no specific property was the cause
   * @param reason reason for failure
   */
  HMPConfigurationException(const QString& property, const QString& reason);

  /**
   * Create a <code>HMPConfigurationException</code> object.
   *
   * @param property name of the property that caused the problem,
   *        <code>null</code> if no specific property was the cause
   * @param reason reason for failure
   * @param cause The cause of this exception.
   */
  HMPConfigurationException(const QString& property, const QString& reason,
                            const HMPException& cause);

  HMPConfigurationException(const HMPConfigurationException& o);
  HMPConfigurationException& operator=(const HMPConfigurationException& o);

  ~HMPConfigurationException() throw();

  /**
   * @see HMPException::name()
   */
  const char* name() const throw();

  /**
   * @see HMPException::clone()
   */
  HMPConfigurationException* clone() const;

  /**
   * @see HMPException::rethrow()
   */
  void rethrow() const;

  /**
   * Return the property name that caused the failure or a null QString.
   *
   * @return name of property or null if no specific property caused the
   *         problem
   */
  QString getProperty() const;

  /**
   * Return the reason for this exception.
   *
   * @return reason of the failure
   */
  QString getReason() const;

private:

  QString property;
  QString reason;
};

/**
 * \ingroup ConfigAdmin
 */

HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug dbg, const HMPConfigurationException& exc);

/** @}*/

#endif // HMPCONFIGURATIONEXCEPTION_H
