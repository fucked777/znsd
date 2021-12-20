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

#ifndef __HMPLinearValueProxy_h
#define __HMPLinearValueProxy_h

// HMP includes
//#include "HMPCoreExport.h"
#include "core_global.h"
#include "HMPValueProxy.h"
#include "HMPPimpl.h"

class HMPLinearValueProxyPrivate;

/// \ingroup Core
/// \brief Implementation of an affine value proxy.
/// The HMPLinearValueProxy takes a coefficient and an offset,
/// effectively implementing a value proxy such as:
/// valueProxy = coefficient * value + offset
/// Note: If the coefficient is null then the property value given
/// by value = (valueProxy - offset) / coefficient can give bad results
/// (+ or - infinity depending on the sign of valueProxy - offset).
/// \sa HMPValueProxy
class HMP_CORE_EXPORT HMPLinearValueProxy : public HMPValueProxy
{
  Q_OBJECT
  Q_PROPERTY(double coefficient READ coefficient WRITE setCoefficient)
  Q_PROPERTY(double offset READ offset WRITE setOffset)

public:
  typedef HMPValueProxy Superclass;
  explicit HMPLinearValueProxy(QObject* parent = 0);
  virtual ~HMPLinearValueProxy();

  virtual double proxyValueFromValue(double value) const;

  virtual double valueFromProxyValue(double proxyValue) const;

  virtual double coefficient() const;
  virtual double offset() const;

public Q_SLOTS:
  virtual void setCoefficient(double newCoeff);
  virtual void setOffset(double newOffset);

protected:
  QScopedPointer<HMPLinearValueProxyPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(HMPLinearValueProxy);
  Q_DISABLE_COPY(HMPLinearValueProxy);
};

#endif
