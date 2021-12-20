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


#ifndef HMPMETATYPESERVICE_H
#define HMPMETATYPESERVICE_H

#include "HMPMetaTypeInformation.h"

/**
 * \ingroup Metatype
 *
 * The MetaType Service can be used to obtain meta type information for a
 * plugin. The MetaType Service will examine the specified plugin for meta type
 * documents to create the returned <code>HMPMetaTypeInformation</code> object.
 *
 * <p>
 * If the specified plugin does not contain any meta type documents, then a
 * <code>HMPMetaTypeInformation</code> object will be returned that wraps any
 * <code>HMPManagedService</code> or <code>HMPManagedServiceFactory</code>
 * services registered by the specified plugin that implement
 * <code>HMPMetaTypeProvider</code>. Thus the MetaType Service can be used to
 * retrieve meta type information for plugins which contain meta type
 * documents or which provide their own <code>HMPMetaTypeProvider</code> objects.
 */
struct HMP_PLUGINFW_EXPORT HMPMetaTypeService
{
 virtual ~HMPMetaTypeService() {}

 /**
  * Return the MetaType information for the specified plugin.
  *
  * @param plugin The plugin for which meta type information is requested.
  * @return A HMPMetaTypeInformation object for the specified plugin.
  */
 virtual HMPMetaTypeInformationPtr getMetaTypeInformation(const QSharedPointer<HMPPlugin>& plugin) = 0;

 /**
  * Location of meta type documents. The MetaType Service will process each
  * entry in the meta type documents directory.
  */
 static const QString METATYPE_DOCUMENTS_LOCATION; // = "HMP-INF/metatype"
};

Q_DECLARE_INTERFACE(HMPMetaTypeService, "org.commontk.service.metatype.MetaTypeServce")

#endif // HMPMETATYPESERVICE_H
