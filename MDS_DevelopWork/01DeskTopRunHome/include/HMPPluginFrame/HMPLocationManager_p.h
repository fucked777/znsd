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

#ifndef HMPLOCATIONMANAGER_H
#define HMPLOCATIONMANAGER_H

#include <QString>

class HMPBasicLocation;

/**
 * This class is used to manage the various Locations for BlueBerry.
 * <p>
 * Clients may not extend this class.
 * </p>
 * @noextend This class is not intended to be subclassed by clients.
 */
class HMPLocationManager
{

public:

  static const QString READ_ONLY_AREA_SUFFIX; // = ".readOnly";

  // configuration area file/dir names
  static const QString CONFIG_FILE; // = "config.ini";
  static const QString HMP_PROPERTIES; // = "HMP.properties";

  /**
   * Initializes the QFileInfo objects for the HMPLocationManager.
   */
  static void initializeLocations();

  /**
   * Returns the user HMPLocation object
   * @return the user HMPLocation object
   */
  static HMPBasicLocation* getUserLocation();

  /**
   * Returns the configuration HMPLocation object
   * @return the configuration HMPLocation object
   */
  static HMPBasicLocation* getConfigurationLocation();

  /**
   * Returns the install HMPLocation object
   * @return the install HMPLocation object
   */
  static HMPBasicLocation* getInstallLocation();

  /**
   * Returns the instance HMPLocation object
   * @return the instance HMPLocation object
   */
  static HMPBasicLocation* getInstanceLocation();

  static HMPBasicLocation* getHMPHomeLocation();

};

#endif // HMPLOCATIONMANAGER_H
