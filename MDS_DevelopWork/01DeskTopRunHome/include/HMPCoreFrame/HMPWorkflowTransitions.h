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

#ifndef __HMPWorkflowTransition_h
#define __HMPWorkflowTransition_h

// Qt includes
#include <QEvent>
#include <QAbstractTransition>
#include <QString>

// HMP includes
//#include "HMPCoreExport.h"
#include "core_global.h"
/// \ingroup Core
/// \brief Custom transitions for use with HMPWorkflow.
///
/// HMPWorkflowIntrastepTransition: for transition between states of the same step.  The transition
/// occurs only when the transition event's EventTransitionType matches the transition's
/// TransitionType).
///
/// HMPWorkflowInterstepTransition: for transition between states of different steps.  The
/// transition occurs only when the transition event's EventTransitionType matches the transition's
/// TransitionType and the transition event's EventId matches the transition's Id.

//-----------------------------------------------------------------------------
struct HMP_CORE_EXPORT HMPWorkflowIntrastepTransitionEvent : public QEvent
{

  /// EventTransitionType is the value of a transition event, used to conditionally trigger transitions
  HMPWorkflowIntrastepTransitionEvent(int newTransitionType)
    : QEvent(QEvent::Type(getWorkflowIntrastepTransitionEventType())),
      EventTransitionType(newTransitionType){}

  /// Reserve a custom event type, ensuring that we are not re-using an
  /// event type that was previously used
  static inline int getWorkflowIntrastepTransitionEventType()
  {
    static int workflowIntrastepTransitionEventType = QEvent::registerEventType(QEvent::User+1);
    return workflowIntrastepTransitionEventType;
  }

  int EventTransitionType;
};

//-----------------------------------------------------------------------------
/// \ingroup Core
class HMP_CORE_EXPORT HMPWorkflowIntrastepTransition : public QAbstractTransition
{
  Q_OBJECT

public:

  enum IntrastepTransitionType
  {
    ValidationTransition = 0,
    ValidationFailedTransition
  };

  HMPWorkflowIntrastepTransition(IntrastepTransitionType newTransitionType)
    : TransitionType(newTransitionType){}

  IntrastepTransitionType transitionType() {return this->TransitionType;}

protected:
  virtual bool eventTest(QEvent* e)
  {
    // check the event type
    if (e->type() != HMPWorkflowIntrastepTransitionEvent::getWorkflowIntrastepTransitionEventType())
      {
      return false;
      }

    // check the event value (i.e. the TransitionType)
    HMPWorkflowIntrastepTransitionEvent* workflowEvent = static_cast<HMPWorkflowIntrastepTransitionEvent*>(e);

    return (this->TransitionType == workflowEvent->EventTransitionType);
  }

  void onTransition(QEvent*){}

private:
  IntrastepTransitionType TransitionType;

};

//-----------------------------------------------------------------------------
/// \ingroup Core
struct HMP_CORE_EXPORT HMPWorkflowInterstepTransitionEvent : public QEvent
{

  /// EventTransitionType is the value of a transition event, used to conditionally trigger transitions
  HMPWorkflowInterstepTransitionEvent(int newTransitionType)
    : QEvent(QEvent::Type(getWorkflowInterstepTransitionEventType())),
      EventTransitionType(newTransitionType){}
  HMPWorkflowInterstepTransitionEvent(int newTransitionType, const QString& newId)
    : QEvent(QEvent::Type(getWorkflowInterstepTransitionEventType())),
    EventTransitionType(newTransitionType),
    EventId(newId){}

  /// Reserve a custom event type, ensuring that we are not re-using an
  /// event type that was previously used
  static inline int getWorkflowInterstepTransitionEventType()
  {
    static int workflowInterstepTransitionEventType = QEvent::registerEventType(QEvent::User+1);
    return workflowInterstepTransitionEventType;
  }

  int     EventTransitionType;
  QString EventId;
};

//-----------------------------------------------------------------------------
/// \ingroup Core
class HMP_CORE_EXPORT HMPWorkflowInterstepTransition : public QAbstractTransition
{
  Q_OBJECT
  Q_ENUMS(InterstepTransitionType)

public:

  enum InterstepTransitionType
  {
    TransitionToNextStep = 0,
    TransitionToPreviousStep,
    StartingWorkflow,
    StoppingWorkflow,
    TransitionToPreviousStartingStepAfterSuccessfulGoToFinishStep
  };

  HMPWorkflowInterstepTransition(InterstepTransitionType newTransitionType)
    : TransitionType(newTransitionType){}
  HMPWorkflowInterstepTransition(InterstepTransitionType newTransitionType, const QString& newId)
    : TransitionType(newTransitionType),
    Id(newId) {}

  InterstepTransitionType transitionType() {return this->TransitionType;}
  QString& id() {return this->Id;}

protected:
  virtual bool eventTest(QEvent* e)
  {
    // check the event type
    if (e->type() != HMPWorkflowInterstepTransitionEvent::getWorkflowInterstepTransitionEventType())
      {
      return false;
      }

    // check the event value (i.e. the TransitionType)
    HMPWorkflowInterstepTransitionEvent* workflowEvent = static_cast<HMPWorkflowInterstepTransitionEvent*>(e);

    return (this->TransitionType == workflowEvent->EventTransitionType
            && this->Id == workflowEvent->EventId); 
  }

  void onTransition(QEvent*){}

private:
  InterstepTransitionType TransitionType;
  QString                 Id;

};

#endif
