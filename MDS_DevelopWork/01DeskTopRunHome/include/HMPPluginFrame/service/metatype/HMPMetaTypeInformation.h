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


#ifndef HMPMETATYPEINFORMATION_H
#define HMPMETATYPEINFORMATION_H

#include "HMPMetaTypeProvider.h"

#include <QSharedPointer>

class HMPPlugin;

/**
 * \ingroup Metatype
 *
 * A MetaType Information object is created by the HMPMetaTypeService to return
 * meta type information for a specific plugin.
 */
struct HMPMetaTypeInformation : public HMPMetaTypeProvider
{
  /**
   * Return the PIDs (for ManagedServices) for which HMPObjectClassDefinition
   * information is available.
   *
   * @return List of PIDs.
   */
  virtual QStringList getPids() const = 0;

  /**
   * Return the Factory PIDs (for ManagedServiceFactories) for which
   * HMPObjectClassDefinition information is available.
   *
   * @return List of Factory PIDs.
   */
  virtual QStringList getFactoryPids() const = 0;

  /**
   * Return the plugin for which this object provides meta type information.
   *
   * @return Plugin for which this object provides meta type information.
   */
  virtual QSharedPointer<HMPPlugin> getPlugin() const = 0;
};

/**
 * \ingroup Metatype
 */
typedef QSharedPointer<HMPMetaTypeInformation> HMPMetaTypeInformationPtr;

#endif // HMPMETATYPEINFORMATION_H
