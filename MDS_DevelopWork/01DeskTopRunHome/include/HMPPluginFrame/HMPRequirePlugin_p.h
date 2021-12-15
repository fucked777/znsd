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

#ifndef HMPREQUIREPLUGIN_P_H
#define HMPREQUIREPLUGIN_P_H

#include <HMPVersionRange_p.h>


class HMPPluginPrivate;

/**
 * \ingroup PluginFramework
 */
class HMPRequirePlugin
{

public:

  const QString name;
  const QString resolution;
  const HMPVersionRange pluginRange;

  HMPRequirePlugin(HMPPluginPrivate* requestor,
                   const QString& name, const QString& res,
                   const QString& range);

  bool overlap(const HMPRequirePlugin& rp) const;

};


#endif // HMPREQUIREPLUGIN_P_H
