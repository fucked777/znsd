/*=========================================================================

  Library:   HMP

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __HMPAbstractPluginFactory_h
#define __HMPAbstractPluginFactory_h

// Qt includes
#include <QPluginLoader>
#include <QFileInfo>

// HMP includes
#include "HMPAbstractFileBasedFactory.h"

//----------------------------------------------------------------------------
/// \ingroup Core
template<typename BaseClassType>
class HMPFactoryPluginItem : public HMPAbstractFactoryFileBasedItem<BaseClassType>
{
public:
  virtual bool load();
  virtual QString loadErrorString()const;

protected:
  virtual BaseClassType* instanciator();

private:
  QPluginLoader    Loader;
};

//----------------------------------------------------------------------------
/// \ingroup Core
template<typename BaseClassType>
class HMPAbstractPluginFactory : public HMPAbstractFileBasedFactory<BaseClassType>
{
protected:
  virtual bool isValidFile(const QFileInfo& file)const;
  virtual HMPAbstractFactoryItem<BaseClassType>* createFactoryFileBasedItem();
};

#include "HMPAbstractPluginFactory.tpp"

#endif
