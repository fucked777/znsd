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

#ifndef __HMPLogger_h
#define __HMPLogger_h

// Qt includes
#include <QObject>

// HMP includes
#include <HMPPimpl.h>
//#include "HMPCoreExport.h"
#include "core_global.h"
class HMPLoggerPrivate;

/// \deprecated This class was a wrapper around Log4Qt. Since Log4Qt dependency has been
/// removed, it is advised to use qDebug(), qWarning() and qCritical() instead.
/// \ingroup Core
class HMP_CORE_EXPORT HMPLogger : public QObject
{
  Q_OBJECT
public:
  typedef QObject Superclass;
  /// Default mode is Off
  explicit HMPLogger(QString name, QObject* parent = 0);
  virtual ~HMPLogger ();

  void debug(const QString& s);
  void info(const QString& s);
  void trace(const QString& s);
  void warn(const QString& s);
  void error(const QString& s);
  void fatal(const QString& s);

protected:
  QScopedPointer<HMPLoggerPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(HMPLogger);
  Q_DISABLE_COPY(HMPLogger);
};

#endif
