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

#ifndef __HMPAbstractFactory_h
#define __HMPAbstractFactory_h

// Qt includes
#include <QString>
#include <QHash>
#include <QSharedPointer>
#include <QStringList>

#ifdef _MSC_VER
  /// 4505: 'HMPAbstractFactoryItem<BaseClassType>::loadErrorString' :
  ///       unreferenced local function has been removed
# pragma warning(disable: 4505)
#endif

//----------------------------------------------------------------------------
/// \ingroup 核心
/// HMPAbstractFactoryItem是工厂项的基类。它们由键唯一定义，
/// 负责创建/保存BaseClassType对象的实例。
///
template<typename BaseClassType>
class HMPAbstractFactoryItem
{
public:
  //explicit HMPAbstractFactoryItem();
  HMPAbstractFactoryItem();
  virtual ~HMPAbstractFactoryItem();

  virtual bool load() = 0;

  QStringList instantiateErrorStrings()const;
  QStringList instantiateWarningStrings()const;

  QStringList loadErrorStrings()const;
  QStringList loadWarningStrings()const;

  BaseClassType* instantiate();
  bool isInstantiated()const;
  BaseClassType* instance()const;
  virtual void uninstantiate();

  void setVerbose(bool value);
  bool verbose()const;

protected:

  void appendInstantiateErrorString(const QString& msg);
  void clearInstantiateErrorStrings();

  void appendInstantiateWarningString(const QString& msg);
  void clearInstantiateWarningStrings();

  void appendLoadErrorString(const QString& msg);
  void clearLoadErrorStrings();

  void appendLoadWarningString(const QString& msg);
  void clearLoadWarningStrings();

  /// Must be reimplemented in subclasses to instanciate a BaseClassType*
  virtual BaseClassType* instanciator() = 0;
  BaseClassType* Instance;

private:
  QStringList InstantiateErrorStrings;
  QStringList InstantiateWarningStrings;
  QStringList LoadErrorStrings;
  QStringList LoadWarningStrings;
  bool Verbose;
};

//----------------------------------------------------------------------------
/// \ingroup Core
/// \brief HMPAbstractFactory是所有工厂的基类，其中的项目需要在实例化之前注册。HMPAbstractFactory包含一个HMPAbstractFactoryItems集合
/// <p> HMPAbstractFactory contains a collection of HMPAbstractFactoryItems that
/// are uniquely identifyed by a key. Subclasses of HMPAbstractFactory are
/// responsible for populating the list of HMPAbstractFactoryItems.
/// BaseClassType could be any type (most probably a QObject)
template<typename BaseClassType>
class HMPAbstractFactory
{
public:

  typedef QHash<QString, QSharedPointer<HMPAbstractFactoryItem<BaseClassType> > > HashType;

  /// Constructor/Desctructor
  HMPAbstractFactory();
  virtual ~HMPAbstractFactory();
  virtual void printAdditionalInfo();

  /// \brief Create an instance of the object.
  /// The item corresponding to the key should have been registered before.
  virtual BaseClassType * instantiate(const QString& itemKey);

  /// \brief Return the instance associated with \a itemKey if any, otherwise
  /// return 0.
  virtual BaseClassType * instance(const QString& itemKey);

  /// \brief Uninstanciate the object.
  /// Do nothing if the item given by the key has not be instantiated nor registered.
  void uninstantiate(const QString& itemKey);

  /// \brief Get path associated with the item identified by \a itemKey
  /// Should be overloaded in subclasse
  virtual QString path(const QString& itemKey){ Q_UNUSED(itemKey); return QString(); }

  void setSharedItems(const QSharedPointer<HashType>& items);
  QSharedPointer<HashType> sharedItems();

  /// Get list of all registered item keys.
  QStringList itemKeys() const;

  /// \brief Register items with the factory
  /// Method provided for convenience - Should be overloaded in subclasse
  virtual void registerItems(){}

  /// \brief Enabled verbose output
  /// Warning and error message will be printed to standard outputs
  void setVerbose(bool value);
  bool verbose()const;

protected:

  void displayStatusMessage(const QtMsgType& type, const QString& description,
                            const QString& status, bool display);

  /// \brief Call the load method associated with the item.
  /// If succesfully loaded, add it to the internal map.
  bool registerItem(const QString& key, const QSharedPointer<HMPAbstractFactoryItem<BaseClassType> > & item);

  /// Get a Factory item given its itemKey. Return 0 if any.
  HMPAbstractFactoryItem<BaseClassType> * item(const QString& itemKey)const;

  HMPAbstractFactoryItem<BaseClassType> * sharedItem(const QString& itemKey)const;

  typedef typename HashType::const_iterator ConstIterator;
  typedef typename HashType::iterator       Iterator;

private:
  /*
  HMPAbstractFactory(const HMPAbstractFactory &); /// Not implemented
  void operator=(const HMPAbstractFactory&); /// Not implemented
  */
  HashType RegisteredItemMap;
  QSharedPointer<HashType> SharedRegisteredItemMap;

  bool Verbose;
};

#include "HMPAbstractFactory.tpp"

#endif
