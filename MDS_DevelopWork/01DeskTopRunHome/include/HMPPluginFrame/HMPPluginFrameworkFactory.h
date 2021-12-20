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

#ifndef HMPPLUGINFRAMEWORKFACTORY_H
#define HMPPLUGINFRAMEWORKFACTORY_H

#include <QHash>
#include <QString>
#include <QVariant>
#include <QSharedPointer>

#include "HMPPluginFrameworkExport.h"

#include "HMPPluginFramework_global.h"

class HMPPluginFramework;
class HMPPluginFrameworkContext;

/**
 * \ingroup PluginFramework
 * A factory for creating HMPPluginFramework instances.
 */
class HMP_PLUGINFW_EXPORT HMPPluginFrameworkFactory
{

public:

  /**
   * Create a new <code>%HMPPluginFrameworkFactory</code> instance.
   *
   * <p>
   * The HMPProperties map is used to configure the HMPPluginFramework. The
   * plugin framework instance created with #getFramework() must interpret
   * the following properties:
   *
   * <p>
   * <ul><li>HMPPluginConstants::FRAMEWORK_STORAGE</li>
   * </ul>
   *
   * @param initProps The plugin framework configuration properties.
   *        The HMPPluginFramework instance created with #getFramework()
   *        must use some reasonable default configuration if certain
   *        properties are not provided.
   */
  HMPPluginFrameworkFactory(const HMPProperties& initProps = HMPProperties());

  ~HMPPluginFrameworkFactory();

  /**
   * Create a new HMPPluginFramework instance.
   *
   * @return A new, configured HMPPluginFramework instance. The plugin
   *         framework instance must be in the HMPPlugin::INSTALLED state.
   */
  QSharedPointer<HMPPluginFramework> getFramework();

private:

  HMPPluginFrameworkContext* fwCtx;

};


#endif // HMPPLUGINFRAMEWORKFACTORY_H
