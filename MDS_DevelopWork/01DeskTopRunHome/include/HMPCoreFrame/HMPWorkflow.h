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

#ifndef __HMPWorkflow_h
#define __HMPWorkflow_h

// Qt includes
#include <QObject>

// HMP includes
#include "HMPPimpl.h"
//#include "HMPCoreExport.h"
#include "core_global.h"
class HMPWorkflowStep;
class HMPWorkflowPrivate;
class QAbstractState;

/// \ingroup Core
/// \brief HMPWorkflow is the basis for a workflow engine, i.e. a state
/// machine with enhancements to support HMPWorkflowStep.

class HMP_CORE_EXPORT HMPWorkflow : public QObject
{
  Q_OBJECT
  Q_ENUMS(TransitionDirectionality)
  Q_PROPERTY(bool isRunning READ isRunning DESIGNABLE false)
  Q_PROPERTY(bool goBackToOriginStepUponSuccess READ goBackToOriginStepUponSuccess WRITE setGoBackToOriginStepUponSuccess)
  Q_PROPERTY(bool verbose READ verbose WRITE setVerbose)

public:

  typedef QObject Superclass;
  explicit HMPWorkflow(QObject* parent = 0);
  virtual ~HMPWorkflow();

  /// \brief Start the workflow.
  /// The workflow will always start in the initial step, even if it is stopped and restarted).
  /// \note Calls onEntry() for the initial step.
  Q_INVOKABLE virtual void start();

  /// \brief Returns whether the workflow is currently running
  bool isRunning()const;

  /// \brief Stops the workflow.
  /// \note Calls onExit() for the current step.
  Q_INVOKABLE virtual void stop();

  /// \brief Transition directionalities.
  ///
  /// The direction of transitions between an origin step and a destination step can be either:
  /// <ul>
  ///  <li>\a Bidirectional: A transition from the origin to the destination, and a transition from
  /// the destination to the origin</li>
  ///  <li>\a Forward: A transition from the origin to the destination only</li>
  ///  <li>\a Backward: A transition from the destination to the origin only</li>
  /// </ul>
  enum TransitionDirectionality
  {
    Bidirectional = 0,
    Forward,
    Backward
  };

  /// \brief Creates a transition between two steps, and adds the two steps to the workflow if they
  /// have not been previously added. (Cannot add two steps with the same id).
  ///
  /// The destination step should semantically be a next step, i.e. from a workflow perspective, the
  /// \a destination step is meant to appear after the \a origin step.
  ///
  /// To add a single step, \a destination can be set to 0.
  ///
  /// Returns true/false indicating whether the method was successful.
  Q_INVOKABLE virtual bool addTransition(HMPWorkflowStep* origin, HMPWorkflowStep* destination,
                                         const QString& branchId = QString(),
                                         const HMPWorkflow::TransitionDirectionality directionality
                                         = HMPWorkflow::Bidirectional);

  /// \brief Determine whether a transition has already been added
  /// <ul>
  ///  <li>If a branch id is not given or is empty: a transition exists if a transition has been
  /// previously added with the same origin, destination and directionality</li>
  /// <li>If a non-empty branch id is given: a transition exists if the transition has been previously
  /// added with the same origin, destination and directionality, OR if a transition has been
  /// previously added with the same origin and branch id (for forward transitions) or
  /// with the same destination and branch id (for backward transitions)</li>
  /// </ul>
  Q_INVOKABLE bool hasTransition(HMPWorkflowStep* origin, HMPWorkflowStep* destination,
                                 const QString& branchId = QString(),
                                 const HMPWorkflow::TransitionDirectionality directionality
                                 = HMPWorkflow::Bidirectional);

  /// \brief Set/get the initial step.
  /// \note In not specified, the first step added will be considered as the initialStep
  /// \sa currentStep(), step(), hasStep(), steps()
  Q_INVOKABLE HMPWorkflowStep* initialStep()const;
  Q_INVOKABLE virtual void setInitialStep(HMPWorkflowStep* step);

  /// Get the current step of the state machine
  /// \sa initialStep(), step(), hasStep(), steps()
  Q_INVOKABLE HMPWorkflowStep* currentStep()const;

  /// Check to see if there is a step with a given id in the workflow.
  /// \sa step(), currentStep(), steps()
  Q_INVOKABLE bool hasStep(const QString& id)const;

  /// Return the step with matching \a id if any, 0 otherwise.
  /// \sa hasStep(), currentStep(), steps()
  Q_INVOKABLE HMPWorkflowStep* step(const QString& id)const;

  /// Returns whether or not we can go forward: i.e. there exists a step that directly follows the
  /// given step.
  ///
  /// If no step is given, then the workflow's current step will be used.
  Q_INVOKABLE bool canGoForward(HMPWorkflowStep* step=0)const;

  /// Returns whether or not we can go backward: i.e. there exists a step that directly preceeds the
  /// given step.
  ///
  /// If no step is given, then the workflow's current step will be used.
  Q_INVOKABLE bool canGoBackward(HMPWorkflowStep* step=0)const;

  /// Returns whether or not we can go to the goal step from the origin step: i.e. there is a path
  /// in the workflow from the current step to the given step.
  ///
  /// If no step is designated as the 'origin', then the workflow's current step will be used
  /// Note: does not currently work in branching workflows if the origin and target steps are not on
  /// the same branch
  Q_INVOKABLE bool canGoToStep(const QString& targetId, HMPWorkflowStep* step=0)const;

  /// Get the steps that directly follow the given step.
  ///
  /// More specifically, the returned list of steps will be the destination steps for which
  /// addTransition() has been called with the given step as the origin step and directionality set
  /// to HMPWorkflow::Bidirectional or HMPWorkflow::Forward.
  ///
  /// If no step is given, then the workflow's current step will be used.
  Q_INVOKABLE QList<HMPWorkflowStep*> forwardSteps(HMPWorkflowStep* step=0)const;

  /// Get the steps that directly preceed the given step.
  ///
  /// More specifically, the returned list of steps will be the origin steps for which
  /// addTransition() has been called with the given step as the destination step and directionality
  /// set to HMPWorkflow::Bidirectional or HMPWorkflow::Backward.
  ///
  /// If no step is given, then the workflow's current step will be used.
  Q_INVOKABLE QList<HMPWorkflowStep*> backwardSteps(HMPWorkflowStep* step=0)const;

  /// Get the steps that are 'finish' steps (i.e. have no step following them)
  Q_INVOKABLE QList<HMPWorkflowStep*> finishSteps()const;

  /// Returns list of steps managed by the workflow
  Q_INVOKABLE QList<HMPWorkflowStep*> steps()const;

  // Returns the distance of a given to step to another step.
  // The directionality used here is HMPWorkflow::Bidirectional or HMPWorkflow::Backward.
  // By default, step is the current step and origin the initial step.
  //
  // This is different from the other method as it's not limited to the backward or forward steps
  // but actually performs a recursive search.
  Q_INVOKABLE int backwardDistanceToStep(HMPWorkflowStep* fromStep = 0, HMPWorkflowStep* origin = 0)const;

  /// Configures the behavior of goToStep(targetId).
  ///
  /// If set to true, goToStep(targetId) goes back to the origin step after
  /// the attempt of going to the target step succeeded.
  /// If set to false, goToStep(targetId) stays at the target step when the attempt
  /// succeeded.
  bool goBackToOriginStepUponSuccess()const;
  void setGoBackToOriginStepUponSuccess(bool flag);

  /// If set debug messages will be displayed on standard output.
  bool verbose()const;
  void setVerbose(bool value);

public Q_SLOTS:

  /// Use this to trigger evaluation of the processing state of the current step, and subsequent
  /// conditional transition to the next step.
  virtual void goForward(const QString& desiredBranchId = QString());

  /// Use this to trigger transition to the previous step (does not require validation)
  virtual void goBackward(const QString& desiredBranchId = QString());

  /// Go to the given step by iteratively calling goForward() until we reach it.
  virtual void goToStep(const QString& targetId);

  /// \brief Receives the result of a step's validate(const QString&) function.
  ///
  /// If the validation is successful, then this slot begins the transition to the next step.
  virtual void evaluateValidationResults(bool validationSucceeded, const QString& branchId);

protected:

  void goToNextStepAfterSuccessfulValidation(const QString& branchId);

  void goToProcessingStateAfterValidationFailed();

  /// \brief Processing that occurs after the attempt to go to a 'goTo' step succeeds
  virtual void goToStepSucceeded();

  /// \brief Processing that occurs after the attempt to go to a 'goTo' step fails
  virtual void goToStepFailed();

  /// \brief Goes to the step from which the attempt to go to the 'goTo' step was initiated
  void goFromGoToStepToStartingStep();

protected Q_SLOTS:

  /// On an attempt to go to the next step, calls the current step's
  /// validate(const QString&) function to validate the processing step.
  void attemptToGoToNextStep();

  /// \brief Called when transitioning to the next step upon successful validation, or
  /// when transitioning to the previous step.
  /// Calls onExit() of the transition's origin step and then onEntry() of
  /// the transition's destination step.
  /// \note Must be sent by a HMPWorkflowTransition.
  void performTransitionBetweenSteps();

Q_SIGNALS:
  /// Emitted when the current step has changed, after the step's onEntry() has completed.
  /// \note This signal is not emitted in the process of going to a goToStep
  void currentStepChanged(HMPWorkflowStep* currentStep);

  /// Emitted when a step is registered with this workflow
  /// \sa addTransition
  void stepRegistered(HMPWorkflowStep* step);

protected:
  QScopedPointer<HMPWorkflowPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(HMPWorkflow);
  Q_DISABLE_COPY(HMPWorkflow);
};

#endif

