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


#ifndef HMPSERVICEEXCEPTION_H
#define HMPSERVICEEXCEPTION_H

#include "HMPException.h"

#include <HMPPluginFrameworkExport.h>

/**
 * \ingroup PluginFramework
 *
 * A service exception used to indicate that a service problem occurred.
 *
 * <p>
 * A <code>HMPServiceException</code> object is created by the Framework or
 * to denote an exception condition in the service. An enum
 * type is used to identify the exception type for future extendability.
 *
 * <p>
 * This exception conforms to the general purpose exception chaining mechanism.
 */
class HMP_PLUGINFW_EXPORT HMPServiceException : public HMPRuntimeException
{
public:

  enum Type {
    /**
     * No exception type is unspecified.
     */
    UNSPECIFIED = 0,
    /**
     * The service has been unregistered.
     */
    UNREGISTERED = 1,
    /**
     * The service factory produced an invalid service object.
     */
    FACTORY_ERROR = 2,
    /**
     * The service factory threw an exception.
     */
    FACTORY_EXCEPTION = 3,
    /**
     * An error occurred invoking a remote service.
     */
    REMOTE = 5,
    /**
     * The service factory resulted in a recursive call to itself for the
     * requesting plugin.
     */
    FACTORY_RECURSION = 6
  };

  /**
   * Creates a <code>HMPServiceException</code> with the specified message and
   * type.
   *
   * @param msg The associated message.
   * @param type The type for this exception.
   */
  HMPServiceException(const QString& msg, const Type& type = UNSPECIFIED);

  /**
   * Creates a <code>HMPServiceException</code> with the specified message,
   * type and exception cause.
   *
   * @param msg The associated message.
   * @param type The type for this exception.
   * @param cause The cause of this exception.
   */
  HMPServiceException(const QString& msg, const Type& type, const HMPException& cause);

  /**
   * Creates a <code>HMPServiceException</code> with the specified message and
   * exception cause.
   *
   * @param msg The associated message.
   * @param cause The cause of this exception.
   */
  HMPServiceException(const QString& msg, const HMPException& cause);

  HMPServiceException(const HMPServiceException& o);
  HMPServiceException& operator=(const HMPServiceException& o);

  ~HMPServiceException() throw();

  /**
   * @see HMPException::name()
   */
  const char* name() const throw();

  /**
   * @see HMPException::clone()
   */
  HMPServiceException* clone() const;

  /**
   * @see HMPException::rethrow()
   */
  void rethrow() const;

  /**
   * Returns the type for this exception or <code>UNSPECIFIED</code> if the
   * type was unspecified or unknown.
   *
   * @return The type of this exception.
   */
  Type getType() const;

private:

  /**
   * Type of service exception.
   */
  Type type;

};

#endif // HMPSERVICEEXCEPTION_H
