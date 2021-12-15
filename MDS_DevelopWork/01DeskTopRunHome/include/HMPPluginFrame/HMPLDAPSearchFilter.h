/*=============================================================================

  Library: HMP

  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#ifndef HMPLDAPSEARCHFILTER_H
#define HMPLDAPSEARCHFILTER_H

#include "HMPPluginFrameworkExport.h"

#include "HMPServiceReference.h"
#include "HMPDictionary.h"

#include <QSharedDataPointer>
#include <QDebug>

class HMPLDAPSearchFilterData;

/**
 * \ingroup PluginFramework
 *
 * An <a href="http://www.ietf.org/rfc/rfc1960.txt">RFC 1960</a>-based Filter.
 *
 * <p>
 * A <code>HMPLDAPSearchFilter</code> can be used numerous times to determine if the match
 * argument matches the filter string that was used to create the <code>HMPLDAPSearchFilter</code>.
 * <p>
 * Some examples of LDAP filters are:
 *
 * \verbatim
 * "(cn=Babs Jensen)"
 * "(!(cn=Tim Howes))"
 * "(&(" + HMPPluginConstants::OBJECTCLASS + "=Person)(|(sn=Jensen)(cn=Babs J*)))"
 *  "(o=univ*of*mich*)"
 * \endverbatim
 *
 * \see "HMP Wiki for a description of the filter string syntax." TODO!
 * \remarks This class is thread safe.
 */
class HMP_PLUGINFW_EXPORT HMPLDAPSearchFilter {

public:

  /**
   * Creates in invalid <code>HMPLDAPSearchFilter</code> object.
   * Test the validity by using the boolean conversion operator.
   *
   * <p>
   * Calling methods on an invalid <code>HMPLDAPSearchFilter</code>
   * will result in undefined behavior.
   */
  HMPLDAPSearchFilter();

  /**
   * Creates a <code>HMPLDAPSearchFilter</code> object. This <code>HMPLDAPSearchFilter</code>
   * object may be used to match a <code>HMPServiceReference</code> object or a
   * <code>HMPDictionary</code> object.
   *
   * <p>
   * If the filter cannot be parsed, an HMPInvalidArgumentException will be
   * thrown with a human readable message where the filter became unparsable.
   *
   * @param filter The filter string.
   * @return A <code>HMPLDAPSearchFilter</code> object encapsulating the filter string.
   * @throws HMPInvalidArgumentException If <code>filter</code> contains an invalid
   *         filter string that cannot be parsed.
   * @see "Framework specification for a description of the filter string syntax." TODO!
   */
  HMPLDAPSearchFilter(const QString& filter);

  HMPLDAPSearchFilter(const HMPLDAPSearchFilter& other);

  ~HMPLDAPSearchFilter();

  operator bool() const;

  /**
   * Filter using a service's properties.
   * <p>
   * This <code>HMPLDAPSearchFilter</code> is executed using the keys and values of the
   * referenced service's properties. The keys are looked up in a case
   * insensitive manner.
   *
   * @param reference The reference to the service whose properties are used
   *        in the match.
   * @return <code>true</code> if the service's properties match this
   *         <code>HMPLDAPSearchFilter</code> <code>false</code> otherwise.
   */
  bool match(const HMPServiceReference& reference) const;

  /**
   * Filter using a <code>HMPDictionary</code> with case insensitive key lookup. This
   * <code>HMPLDAPSearchFilter</code> is executed using the specified <code>HMPDictionary</code>'s keys
   * and values. The keys are looked up in a case insensitive manner.
   *
   * @param dictionary The <code>HMPDictionary</code> whose key/value pairs are used
   *        in the match.
   * @return <code>true</code> if the <code>HMPDictionary</code>'s values match this
   *         filter; <code>false</code> otherwise.
   */
  bool match(const HMPDictionary& dictionary) const;

  /**
   * Filter using a <code>HMPDictionary</code>. This <code>HMPLDAPSearchFilter</code> is executed using
   * the specified <code>HMPDictionary</code>'s keys and values. The keys are looked
   * up in a normal manner respecting case.
   *
   * @param dictionary The <code>HMPDictionary</code> whose key/value pairs are used
   *        in the match.
   * @return <code>true</code> if the <code>HMPDictionary</code>'s values match this
   *         filter; <code>false</code> otherwise.
   */
  bool matchCase(const HMPDictionary& dictionary) const;

  /**
   * Returns this <code>HMPLDAPSearchFilter</code>'s filter string.
   * <p>
   * The filter string is normalized by removing whitespace which does not
   * affect the meaning of the filter.
   *
   * @return This <code>HMPLDAPSearchFilter</code>'s filter string.
   */
  QString toString() const;

  /**
   * Compares this <code>HMPLDAPSearchFilter</code> to another <code>HMPLDAPSearchFilter</code>.
   *
   * <p>
   * This implementation returns the result of calling
   * <code>this->toString() == other.toString()</code>.
   *
   * @param other The object to compare against this <code>HMPLDAPSearchFilter</code>.
   * @return Returns the result of calling
   *         <code>this->toString() == other.toString()</code>.
   */
  bool operator==(const HMPLDAPSearchFilter& other) const;

  HMPLDAPSearchFilter& operator=(const HMPLDAPSearchFilter& filter);

protected:

  QSharedDataPointer<HMPLDAPSearchFilterData> d;

};

/**
 * \ingroup PluginFramework
 */
HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug dbg, const HMPLDAPSearchFilter& filter);

#endif // HMPLDAPSEARCHFILTER_H
