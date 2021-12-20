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

#ifndef HMPSERVICEPROPERTIES_P_H
#define HMPSERVICEPROPERTIES_P_H

#include <QVarLengthArray>
#include <QVariant>

#include "HMPPluginFramework_global.h"

class HMPServiceProperties
{

private:

  QVarLengthArray<QString,10> ks;
  QVarLengthArray<QVariant,10> vs;

  QMap<QString, QVariant> map;

public:

  HMPServiceProperties(const HMPProperties& props);

  QVariant value(const QString& key) const;
  QVariant value(int index) const;

  int find(const QString& key) const;
  int findCaseSensitive(const QString& key) const;

  QStringList keys() const;

};

#endif // HMPSERVICEPROPERTIES_P_H
