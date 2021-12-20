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

#ifndef __HMPErrorLogQtMessageHandler_h
#define __HMPErrorLogQtMessageHandler_h

// HMP includes
#include "HMPErrorLogAbstractMessageHandler.h"
//#include "HMPCoreExport.h"
#include "core_global.h"
// Qt includes
#if QT_VERSION >= 0x50000
#include <QtMessageHandler>
#endif

//------------------------------------------------------------------------------
/// \ingroup Core
class HMP_CORE_EXPORT HMPErrorLogQtMessageHandler : public HMPErrorLogAbstractMessageHandler
{
  Q_OBJECT

public:
  typedef HMPErrorLogAbstractMessageHandler Superclass;

  HMPErrorLogQtMessageHandler();

  static QString HandlerName;

  virtual QString handlerName()const;
  virtual void setEnabledInternal(bool value);

#if QT_VERSION >= 0x50000
  QtMessageHandler SavedQtMessageHandler;
#else
  QtMsgHandler SavedQtMessageHandler;
#endif
};

#endif

