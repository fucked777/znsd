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

#ifndef HMPPLUGINDATABASEEXCEPTION_H
#define HMPPLUGINDATABASEEXCEPTION_H

#include "HMPException.h"

#include <HMPPluginFrameworkExport.h>

/**
 * \ingroup PluginFramework
 */
class HMP_PLUGINFW_EXPORT HMPPluginDatabaseException : public HMPRuntimeException
{
public:

  enum Type {
    UNSPECIFIED,
    DB_CONNECTION_INVALID,
    DB_NOT_OPEN_ERROR,
    DB_NOT_FOUND_ERROR,
    DB_CREATE_DIR_ERROR,
    DB_WRITE_ERROR,
    DB_FILE_INVALID,
    DB_SQL_ERROR
  };

  HMPPluginDatabaseException(const QString& msg, const Type& type = UNSPECIFIED);
  HMPPluginDatabaseException(const QString& msg, const Type& type, const HMPException& cause);
  HMPPluginDatabaseException(const QString& msg, const HMPException& cause);

  HMPPluginDatabaseException(const HMPPluginDatabaseException& o);
  HMPPluginDatabaseException& operator=(const HMPPluginDatabaseException& o);

  ~HMPPluginDatabaseException() throw();

  /**
   * @see HMPException::name()
   */
  const char* name() const throw();

  /**
   * @see HMPException::clone()
   */
  HMPPluginDatabaseException* clone() const;

  /**
   * @see HMPException::rethrow()
   */
  void rethrow() const;

  Type getType() const;

private:

  Type type;

};

#endif // HMPPLUGINDATABASEEXCEPTION_H
