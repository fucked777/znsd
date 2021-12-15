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

#ifndef HMPVERSIONRANGE_H
#define HMPVERSIONRANGE_H

#include "HMPVersion.h"


/**
 * \ingroup PluginFramework
 *
 * Class representing HMP version ranges.
 */
class HMPVersionRange
{

private:

  HMPVersion low;
  HMPVersion high;
  bool lowIncluded;
  bool highIncluded;

public:

  /**
   * The empty version range "[0.0.0,inf)".
   */
  static HMPVersionRange defaultVersionRange();

  /**
   * Construct a HMPVersionRange object.
   * Format for a range:
   *   ( "(" | "[" ) LOW_VERSION ","  HIGH_VERSION ( ")" | "]" )
   * Format for at least a version:
   *   VERSION
   *
   * @param vr Input string.
   */
  HMPVersionRange(const QString& vr);


  /**
   * Construct the default HMPVersionRange object.
   *
   */
  HMPVersionRange();

  ~HMPVersionRange();


  bool isSpecified() const;


  /**
   * Check if specified version is within our range.
   *
   * @param ver HMPVersion to compare to.
   * @return Return true if within range, otherwise false.
   */
  bool withinRange(const HMPVersion& ver) const;


  /**
   * Check if objects range is within another HMPVersionRange.
   *
   * @param range HMPVersionRange to compare to.
   * @return Return true if within range, otherwise false.
   */
  bool withinRange(const HMPVersionRange& range) const;


  /**
   * Compare object to another HMPVersionRange. VersionRanges are compared on the
   * lower bound.
   *
   * @param obj HMPVersionRange to compare to.
   * @return Return 0 if equals, negative if this object is less than obj
   *         and positive if this object is larger then obj.
   * @exception ClassCastException if object is not a HMPVersionRange object.
   */
  int compare(const HMPVersionRange& obj) const;


  /**
   * String with version number. If version is not specified return
   * an empty string.
   *
   * @return QString.
   */
  QString toString() const;


  /**
   * Check if object is equal to this object.
   *
   * @param obj Package entry to compare to.
   * @return true if equal, otherwise false.
   */
  bool operator==(const HMPVersionRange& r) const;

};


#endif // HMPVERSIONRANGE_H
