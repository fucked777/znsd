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


#ifndef HMPDICTIONARY_H
#define HMPDICTIONARY_H

#include <HMPPluginFrameworkExport.h>

#include "HMPPluginFramework_global.h"

/**
 * \ingroup PluginFramework
 *
 * A typedef for a QString to QVariant hash map. Typically used for service properties.
 *
 * \note This is equivalent to using HMPProperties.
 */
typedef QHash<QString,QVariant> HMPDictionary;

#endif // HMPDICTIONARY_H
