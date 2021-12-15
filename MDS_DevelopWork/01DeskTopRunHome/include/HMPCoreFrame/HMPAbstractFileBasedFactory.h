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

#ifndef __HMPAbstractFileBasedFactory_h
#define __HMPAbstractFileBasedFactory_h

// Qt includes
#include <QFileInfo>
#include <QStringList>

// HMP includes
#include "HMPAbstractFactory.h"

//----------------------------------------------------------------------------
/// \ingroup Core
template<typename BaseClassType>
class HMPAbstractFactoryFileBasedItem
  : public HMPAbstractFactoryItem<BaseClassType>
{
public:
  /// Get path associated with the object identified by \a key
  void setPath(const QString& path);
  QString path()const;

private:
  QString               Path;
};

//----------------------------------------------------------------------------
/// \ingroup Core
template<typename BaseClassType>
class HMPAbstractFileBasedFactory : public HMPAbstractFactory<BaseClassType>
{
public:
  virtual bool isValidFile(const QFileInfo& file)const;
  QString itemKey(const QFileInfo& file)const;

  /// Register the item and return the itemkey on success, otherwise return an
  /// empty string.
  QString registerFileItem(const QFileInfo& file);

  /// Get path associated with the library identified by \a key
  virtual QString path(const QString& key);

protected:
  void registerAllFileItems(const QStringList& directories);

  bool registerFileItem(const QString& key, const QFileInfo& file);

  virtual HMPAbstractFactoryItem<BaseClassType>* createFactoryFileBasedItem();
  virtual void initItem(HMPAbstractFactoryItem<BaseClassType>* item);

  virtual QString fileNameToKey(const QString& path)const;
};

#include "HMPAbstractFileBasedFactory.tpp"

#endif
