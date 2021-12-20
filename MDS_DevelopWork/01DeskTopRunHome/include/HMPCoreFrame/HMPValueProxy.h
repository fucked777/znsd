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

#ifndef __HMPValueProxy_h
#define __HMPValueProxy_h

// Qt includes
#include <QObject>
#include <QScopedPointer>

// HMP includes
//#include "HMPCoreExport.h"
#include "core_global.h"
class HMPValueProxyPrivate;

/// \ingroup Core
/// \brief Base class for value proxies.
/// Value proxy allows to decouple the displayed value from the values
/// accessed within the program. For example, one may want to display
/// Fahrenheit while still working with Celsius.
///
/// A HMPValueProxy can be used by connecting signal/slots to the
/// value and proxyValue properties or by using directly the
/// valueFromProxyValue and proxyValueFromValue functions.
///
/// Subclasses should reimplement the function proxyValueFromValue()
/// and valueFromProxyValue().
/// \sa HMPLinearValueProxy
class HMP_CORE_EXPORT HMPValueProxy : public QObject
{
  Q_OBJECT

  /// The value holds the current value. If the value proxy is
  /// considered as a function, then this function applied to the value is
  /// the proxy value.
  /// The value is updated if the proxy value is changed.
  Q_PROPERTY(double value READ value WRITE setValue NOTIFY valueChanged)

  /// The proxy value holds the value transformed. If the value proxy is
  /// considered as a function, then the proxy value is the result of
  /// this function applied to value.
  /// The proxy value is updated if the value is changed.
  Q_PROPERTY(double proxyValue READ proxyValue WRITE setProxyValue NOTIFY proxyValueChanged)

public:
  typedef QObject Superclass;
  explicit HMPValueProxy(QObject* parent = 0);
  virtual ~HMPValueProxy();

  virtual double proxyValueFromValue(double value) const = 0;
  virtual double valueFromProxyValue(double proxyValue) const = 0;

  double value() const;
  virtual double proxyValue() const;

public Q_SLOTS:
  void setValue(double newValue);
  void setProxyValue(double newProxyValue);

Q_SIGNALS:
  void valueChanged(double);
  void proxyValueChanged(double);

  void proxyAboutToBeModified();
  void proxyModified();

protected:
  QScopedPointer<HMPValueProxyPrivate> d_ptr;

  /// Utilities function for subclasses.
  /// Can be called to update the value/proxyValue from the proxyValue/value.
  void updateProxyValue();
  void updateValue();

private:
  Q_DECLARE_PRIVATE(HMPValueProxy);
  Q_DISABLE_COPY(HMPValueProxy);
};

#endif
