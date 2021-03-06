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

#ifndef __HMPFileLogger_h
#define __HMPFileLogger_h

// Qt includes
#include <QObject>

// HMP includes
//#include "HMPCoreExport.h"
#include "core_global.h"
//------------------------------------------------------------------------------
class HMPFileLoggerPrivate;

//------------------------------------------------------------------------------
/// \ingroup Core
class HMP_CORE_EXPORT HMPFileLogger : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool enabled READ enabled WRITE setEnabled)
  Q_PROPERTY(QString filePath READ filePath WRITE setFilePath)

public:
  typedef QObject Superclass;
  typedef HMPFileLogger Self;
  explicit HMPFileLogger(QObject* parentObject = 0);
  virtual ~HMPFileLogger();

  bool enabled()const;
  void setEnabled(bool value);

  QString filePath()const;
  void setFilePath(const QString& filePath);

  int numberOfFilesToKeep()const;
  void setNumberOfFilesToKeep(int value);

public Q_SLOTS:
  void logMessage(const QString& msg);

protected:
  QScopedPointer<HMPFileLoggerPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(HMPFileLogger);
  Q_DISABLE_COPY(HMPFileLogger);
};

#endif
