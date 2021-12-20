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

#ifndef __HMPAbstractLibraryFactory_h
#define __HMPAbstractLibraryFactory_h

// Qt includes
#include <QFileInfo>
#include <QLibrary>
#include <QStringList>

// HMP includes
#include "HMPAbstractFileBasedFactory.h"

//----------------------------------------------------------------------------
/// \ingroup Core
template<typename BaseClassType>
class HMPFactoryLibraryItem : public HMPAbstractFactoryFileBasedItem<BaseClassType>
{

public:

#if QT_VERSION < 0x50000
  typedef void* SymbolAddressType;
#else
  typedef QFunctionPointer SymbolAddressType;
#endif

protected:
  typedef typename QHash<QString, SymbolAddressType>::const_iterator ConstIterator;
  typedef typename QHash<QString, SymbolAddressType>::iterator       Iterator;

public:
  //explicit HMPFactoryLibraryItem(const QString& path);
 
  virtual bool load();

  ///
  /// Set list of required symbols
  void setSymbols(const QStringList& symbols);

  /// Set lookup hints for symbol resolution. See QLibrary documentation.
  void setLoadHints(QLibrary::LoadHints hints);

  ///
  /// \brief Resolve symbols
  /// \note The function will return False if it fails to resolve one
  /// of the required symbols set using setSymbols(const QStringList&)
  bool resolve();

  ///
  /// Get symbol address
  SymbolAddressType symbolAddress(const QString& symbol)const;

protected:
  mutable QLibrary      Library;
  QHash<QString, SymbolAddressType> ResolvedSymbols;
  QStringList           Symbols;
};

//----------------------------------------------------------------------------
/// \ingroup Core
template<typename BaseClassType>
class HMPAbstractLibraryFactory
  : public HMPAbstractFileBasedFactory<BaseClassType>
{
public:
  /// Set the list of symbols
  void setSymbols(const QStringList& symbols);

protected:
  virtual bool isValidFile(const QFileInfo& file)const;
  virtual void initItem(HMPAbstractFactoryItem<BaseClassType>* item);

private:
  QStringList Symbols;
};

#include "HMPAbstractLibraryFactory.tpp"

#endif
