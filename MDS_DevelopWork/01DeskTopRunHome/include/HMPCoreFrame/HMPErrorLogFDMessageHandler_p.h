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

#ifndef __HMPErrorLogFDMessageHandler_p_h
#define __HMPErrorLogFDMessageHandler_p_h

// Qt includes
#include <QMutex>
#include <QThread>

// HMP includes
#include "HMPErrorLogAbstractMessageHandler.h"
#include "HMPErrorLogTerminalOutput.h"

// STD includes
#include <cstdio>

class HMPErrorLogFDMessageHandler;

// --------------------------------------------------------------------------
// HMPFDHandler

// --------------------------------------------------------------------------
/// \ingroup Core
class HMPFDHandler : public QThread
{
  Q_OBJECT
  Q_PROPERTY(bool enabled READ enabled WRITE setEnabled)
public:
  typedef HMPFDHandler Self;

  HMPFDHandler(HMPErrorLogFDMessageHandler* messageHandler,
               HMPErrorLogLevel::LogLevel logLevel,
               HMPErrorLogTerminalOutput::TerminalOutput terminalOutput);
  virtual ~HMPFDHandler();

  /// Enable/Disable the handler.
  void setEnabled(bool value);

  /// Return if the handler is enabled. This methods is thread-safe.
  bool enabled()const;

  FILE* terminalOutputFile();

protected:
  void setupPipe();

  void run();

private:
  HMPErrorLogFDMessageHandler * MessageHandler;
  HMPErrorLogLevel::LogLevel LogLevel;

  HMPErrorLogTerminalOutput::TerminalOutput TerminalOutput;

  int    SavedFDNumber;
  fpos_t SavedFDPos;

  int          Pipe[2]; // 0: Read, 1: Write

  mutable QMutex EnableMutex;
  bool Enabled;
};


#endif
