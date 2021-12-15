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

#ifndef __HMPAbstractObjectFactory_h
#define __HMPAbstractObjectFactory_h

// Qt includes
#include <QDebug>

// HMP includes
#include "HMPAbstractFactory.h"

//----------------------------------------------------------------------------
namespace{
  /// \ingroup Core
  /// Function in charge of instanciating an object of type: ClassType
  template<typename BaseClassType, typename ClassType>
    BaseClassType *instantiateObject()
  {
    return new ClassType;
  }
}

//----------------------------------------------------------------------------
/// \ingroup Core
template<typename BaseClassType, typename ClassType>
class HMPFactoryObjectItem : public HMPAbstractFactoryItem<BaseClassType>
{
protected:
  typedef BaseClassType *(*InstantiateObjectFunc)();
public:
  virtual bool load();
protected:
  virtual BaseClassType* instanciator();
private:
  InstantiateObjectFunc instantiateObjectFunc;
};

//----------------------------------------------------------------------------
/// \ingroup Core
template<typename BaseClassType>
class HMPAbstractObjectFactory : public HMPAbstractFactory<BaseClassType>
{
public:
  explicit HMPAbstractObjectFactory();

  /// Register an object in the factory
  template<typename ClassType>
  bool registerObject(const QString& key);

private:
  HMPAbstractObjectFactory(const HMPAbstractObjectFactory &);  /// Not implemented
  void operator=(const HMPAbstractObjectFactory&); /// Not implemented
};

#include "HMPAbstractObjectFactory.tpp"

#endif
