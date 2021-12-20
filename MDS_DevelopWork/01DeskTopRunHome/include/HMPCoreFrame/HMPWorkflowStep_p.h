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

#ifndef __HMPWorkflowStep_p_h
#define __HMPWorkflowStep_p_h

// Qt includes
#include <QObject>
#include <QPointer>

class QString;
class QState;

// HMP includes
#include <HMPPimpl.h>
#include "HMPWorkflow.h"
#include "HMPWorkflowStep.h"
#include "HMPWorkflowTransitions.h"
//#include "HMPCoreExport.h"
#include "core_global.h"
class HMPWorkflow;

//-----------------------------------------------------------------------------
/**
 * \ingroup Core
 */
class HMP_CORE_EXPORT HMPWorkflowStepPrivate: public QObject
{
  Q_OBJECT
  Q_DECLARE_PUBLIC(HMPWorkflowStep);

public:
  HMPWorkflowStep* q_ptr;
  HMPWorkflowStepPrivate(HMPWorkflowStep& object);
  ~HMPWorkflowStepPrivate();

protected:
  HMPWorkflow* Workflow;

  bool WidgetType;

  QString      Id;
  QString      Name;
  QString      Description;
  QString      StatusText;

  QPointer<QState> ProcessingState;
  QPointer<QState> ValidationState;

  HMPWorkflowIntrastepTransition* ValidationTransition;
  HMPWorkflowIntrastepTransition* ValidationFailedTransition;

  bool HasValidateCommand;
  bool HasOnEntryCommand;
  bool HasOnExitCommand;

  void invokeValidateCommandInternal(const QString& desiredBranchId)const;

  void validationCompleteInternal(bool validationSuceeded, const QString& branchId)const;

  void invokeOnEntryCommandInternal(const HMPWorkflowStep* comingFrom, const HMPWorkflowInterstepTransition::InterstepTransitionType transitionType)const;

  void onEntryCompleteInternal()const;

  void invokeOnExitCommandInternal(const HMPWorkflowStep* goingTo, const HMPWorkflowInterstepTransition::InterstepTransitionType transitionType)const;

  void onExitCompleteInternal()const;


Q_SIGNALS:
  void invokeValidateCommand(const QString& desiredBranchId)const;

  void validationComplete(bool validationSuceeded, const QString& branchId)const;

  void invokeOnEntryCommand(const HMPWorkflowStep* comingFrom, const HMPWorkflowInterstepTransition::InterstepTransitionType transitionType)const;

  void onEntryComplete()const;

  void invokeOnExitCommand(const HMPWorkflowStep* goingTo, const HMPWorkflowInterstepTransition::InterstepTransitionType transitionType)const;

  void onExitComplete()const;

private:
  friend class HMPWorkflowPrivate; // for access to invoke...Internal() methods

};

#endif
