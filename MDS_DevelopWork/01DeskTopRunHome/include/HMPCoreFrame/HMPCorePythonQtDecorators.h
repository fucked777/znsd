/*=========================================================================

  Library:   CFS

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

#ifndef __CFSCorePythonQtDecorators_h
#define __CFSCorePythonQtDecorators_h

// PythonQt includes
#include <PythonQt.h>

// CFS includes
#include <CFSBooleanMapper.h>
#include <CFSErrorLogContext.h>
#include <CFSWorkflowStep.h>
#include <CFSWorkflowTransitions.h>

// NOTE:
//
// For decorators it is assumed that the methods will never be called
// with the self argument as NULL.  The self argument is the first argument
// for non-static methods.
//

/// \ingroup Core
class CFSCorePythonQtDecorators : public QObject
{
  Q_OBJECT
public:

  CFSCorePythonQtDecorators()
    {
    PythonQt::self()->registerClass(&CFSBooleanMapper::staticMetaObject, "CFSCore");
    PythonQt::self()->registerCPPClass("CFSErrorLogContext", 0, "CFSCore");
    PythonQt::self()->registerCPPClass("CFSWorkflowStep", 0, "CFSCore");
    PythonQt::self()->registerClass(&CFSWorkflowInterstepTransition::staticMetaObject, "CFSCore");
    }

public Q_SLOTS:

  //
  // CFSBooleanMapper
  //

  CFSBooleanMapper* new_CFSBooleanMapper(QObject* targetObject, const QByteArray& propertyName, const QByteArray& signal)
    {
    return new CFSBooleanMapper(targetObject, propertyName, signal);
    }

  //
  // CFSWorkflowStep
  //

  CFSWorkflowStep* new_CFSWorkflowStep()
    {
    return new CFSWorkflowStep();
    }

  CFSWorkflowStep* new_CFSWorkflowStep(const QString& newId)
    {
    return new CFSWorkflowStep(newId);
    }

  void delete_CFSWorkflowStep(CFSWorkflowStep * step)
    {
    delete step;
    }

  CFSWorkflow* workflow(CFSWorkflowStep* step)const
    {
    return step->workflow();
    }

  QString id(CFSWorkflowStep* step)const
    {
    return step->id();
    }

  void setId(CFSWorkflowStep* step, const QString& newId)const
    {
    step->setId(newId);
    }

  QString name(CFSWorkflowStep* step)const
    {
    return step->name();
    }

  void setName(CFSWorkflowStep* step, const QString& newName)
    {
    step->setName(newName);
    }

  QString description(CFSWorkflowStep* step)const
    {
    return step->description();
    }

  void setDescription(CFSWorkflowStep* step, const QString& newDescription)
    {
    step->setDescription(newDescription);
    }

  QString statusText(CFSWorkflowStep* step)const
    {
    return step->statusText();
    }

  bool hasValidateCommand(CFSWorkflowStep* step)const
    {
    return step->hasValidateCommand();
    }

  void setHasValidateCommand(CFSWorkflowStep* step, bool newHasValidateCommand)
    {
    step->setHasValidateCommand(newHasValidateCommand);
    }

  bool hasOnEntryCommand(CFSWorkflowStep* step)const
    {
    return step->hasOnEntryCommand();
    }

  void setHasOnEntryCommand(CFSWorkflowStep* step, bool newHasOnEntryCommand)
    {
    step->setHasOnEntryCommand(newHasOnEntryCommand);
    }

  bool hasOnExitCommand(CFSWorkflowStep* step)const
    {
    return step->hasOnExitCommand();
    }

  void setHasOnExitCommand(CFSWorkflowStep* step, bool newHasOnExitCommand)
    {
    step->setHasOnExitCommand(newHasOnExitCommand);
    }

  QObject* CFSWorkflowStepQObject(CFSWorkflowStep* step)
    {
    return step->CFSWorkflowStepQObject();
    }

  //
  // CFSWorkflowInterstepTransition
  //
  CFSWorkflowInterstepTransition* new_CFSWorkflowInterstepTransition(CFSWorkflowInterstepTransition::InterstepTransitionType newTransitionType)
    {
    return new CFSWorkflowInterstepTransition(newTransitionType);
    }

  CFSWorkflowInterstepTransition* new_CFSWorkflowInterstepTransition(CFSWorkflowInterstepTransition::InterstepTransitionType newTransitionType, const QString& newId)
    {
    return new CFSWorkflowInterstepTransition(newTransitionType, newId);
    }

  void delete_CFSWorkflowInterstepTransition(CFSWorkflowInterstepTransition * transition)
    {
    delete transition;
    }

  //
  // CFSErrorLogContext
  //
  CFSErrorLogContext* new_CFSErrorLogContext()
    {
    return new CFSErrorLogContext();
    }

  CFSErrorLogContext* new_CFSErrorLogContext(const QString& msg)
    {
    return new CFSErrorLogContext(msg);
    }

  void setCategory(CFSErrorLogContext* context, const QString& category)
    {
    context->Category = category;
    }
  QString category(CFSErrorLogContext* context)
    {
    return context->Category;
    }

  void setLine(CFSErrorLogContext* context, int line)
    {
    context->Line = line;
    }
  int line(CFSErrorLogContext* context)
    {
    return context->Line;
    }

  void setFile(CFSErrorLogContext* context, const QString& file)
    {
    context->File = file;
    }
  QString file(CFSErrorLogContext* context)
    {
    return context->File;
    }

  void setFunction(CFSErrorLogContext* context, const QString& function)
    {
    context->Function = function;
    }
  QString function(CFSErrorLogContext* context)
    {
    return context->Function;
    }

  void setMessage(CFSErrorLogContext* context, const QString& message)
    {
    context->Message = message;
    }
  QString message(CFSErrorLogContext* context)
    {
    return context->Message;
    }

};

//-----------------------------------------------------------------------------
void initCFSCorePythonQtDecorators()
{
  PythonQt::self()->addDecorators(new CFSCorePythonQtDecorators);
}

#endif
