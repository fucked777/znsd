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

#ifndef HMPERRORLOGABSTRACTMESSAGEHANDLER_H
#define HMPERRORLOGABSTRACTMESSAGEHANDLER_H

// Qt includes
#include <QObject>
#include <QDateTime>

// HMP includes
//#include "HMPCoreExport.h"
#include "core_global.h"
#include "HMPErrorLogLevel.h"
#include "HMPErrorLogTerminalOutput.h"

//------------------------------------------------------------------------------
class HMPErrorLogAbstractMessageHandlerPrivate;
struct HMPErrorLogContext;

//------------------------------------------------------------------------------
/// \ingroup Core
class HMP_CORE_EXPORT HMPErrorLogAbstractMessageHandler : public QObject
{
  Q_OBJECT
public:
  typedef QObject Superclass;
  /// Disabled by default.
  HMPErrorLogAbstractMessageHandler();
  virtual ~HMPErrorLogAbstractMessageHandler();

  virtual QString handlerName()const = 0;

  QString handlerPrettyName()const;

  bool enabled()const;
  void setEnabled(bool value);

  void handleMessage(const QString& threadId, HMPErrorLogLevel::LogLevel logLevel,
                     const QString& origin, const HMPErrorLogContext& logContext,
                     const QString &text);

  HMPErrorLogTerminalOutput* terminalOutput(HMPErrorLogTerminalOutput::TerminalOutput terminalOutputType)const;
  void setTerminalOutput(HMPErrorLogTerminalOutput::TerminalOutput terminalOutputType,
                         HMPErrorLogTerminalOutput * terminalOutput);

Q_SIGNALS:
  void messageHandled(const QDateTime& currentDateTime, const QString& threadId,
                      HMPErrorLogLevel::LogLevel logLevel, const QString& origin,
                      const HMPErrorLogContext& logContext, const QString& text);

protected:
  void setHandlerPrettyName(const QString& newHandlerPrettyName);

  virtual void setEnabledInternal(bool value) = 0;

protected:
  QScopedPointer<HMPErrorLogAbstractMessageHandlerPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(HMPErrorLogAbstractMessageHandler)
  Q_DISABLE_COPY(HMPErrorLogAbstractMessageHandler)
};


#endif // HMPERRORLOGABSTRACTMESSAGEHANDLER_H
