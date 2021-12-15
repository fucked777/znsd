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

#ifndef HMPPLUGINFRAMEWORKPROPERTIES_H
#define HMPPLUGINFRAMEWORKPROPERTIES_H

#include <HMPPluginFramework_global.h>

#include <QMutex>
#include <QMutexLocker>

class HMPPluginFrameworkProperties
{

private:

  static QMutex lock;

  /**@GuardedBy lock*/
  static HMPProperties properties;

public:

  static HMPProperties& getProperties();

  static QVariant getProperty(const QString& key);

  static QVariant getProperty(const QString& key, const QVariant& defaultValue);

  static QVariant setProperty(const QString& key, const QVariant& value);

  static QVariant clearProperty(const QString& key);

  static void setProperties(const HMPProperties& input);

  static void initializeProperties();

};

#endif // HMPPLUGINFRAMEWORKPROPERTIES_H
