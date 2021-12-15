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

#ifndef HMPPLUGINFRAMEWORK_H
#define HMPPLUGINFRAMEWORK_H

#include <HMPPluginFrameworkExport.h>

#include "HMPPlugin.h"
#include "HMPPluginFrameworkEvent.h"

class HMPPluginFrameworkContext;
class HMPPluginFrameworkPrivate;

/**
 * \ingroup PluginFramework
 *
 * A %HMPPluginFramework instance. A %HMPPluginFramework is also known as a System %Plugin.
 *
 * <p>
 * %HMPPluginFramework instances are created using a HMPPluginFrameworkFactory. The methods
 * of this class can be used to manage and control the created plugin framework
 * instance.
 *
 * @remarks This class is thread safe.
 */
class HMP_PLUGINFW_EXPORT HMPPluginFramework : public HMPPlugin
{

public:

  /**
   * Initialize this %HMPPluginFramework. After calling this method, this %HMPPluginFramework
   * must:
   * <ul>
   * <li>Be in the {@link #STARTING} state.</li>
   * <li>Have a valid Plugin Context.</li>
   * <li>Be at start level 0.</li>
   * <li>Have event handling enabled.</li>
   * <li>Have create HMPPlugin objects for all installed plugins.</li>
   * <li>Have registered any framework services.</li>
   * </ul>
   *
   * <p>
   * This %HMPPluginFramework will not actually be started until {@link #start() start}
   * is called.
   *
   * <p>
   * This method does nothing if called when this %HMPPluginFramework is in the
   * {@link #STARTING}, {@link #ACTIVE} or {@link #STOPPING} states.
   *
   * @throws HMPPluginException If this %HMPPluginFramework could not be initialized.
   */
  void init();

  /**
   * Wait until this %HMPPluginFramework has completely stopped. The <code>stop</code>
   * and <code>update</code> methods perform an asynchronous
   * stop of the Framework. This method can be used to wait until the
   * asynchronous stop of this Framework has completed. This method will only
   * wait if called when this Framework is in the {@link #STARTING},
   * {@link #ACTIVE}, or {@link #STOPPING} states. Otherwise it will return
   * immediately.
   * <p>
   * A Framework Event is returned to indicate why this Framework has stopped.
   *
   * @param timeout Maximum number of milliseconds to wait until this
   *        Framework has completely stopped. A value of zero will wait
   *        indefinitely.
   * @return A Framework Event indicating the reason this method returned. The
   *         following <code>HMPPluginFrameworkEvent</code> types may be returned by
   *         this method.
   *         <ul>
   *         <li>{@link HMPPluginFrameworkEvent#FRAMEWORK_STOPPED STOPPED} - This Framework has
   *         been stopped. </li>
   *
   *         <li>{@link HMPPluginFrameworkEvent#FRAMEWORK_STOPPED_UPDATE STOPPED_UPDATE} - This
   *         Framework has been updated which has shutdown and will now
   *         restart.</li>
   *
   *         <li>{@link HMPPluginFrameworkEvent#PLUGIN_ERROR ERROR} - The Framework
   *         encountered an error while shutting down or an error has occurred
   *         which forced the framework to shutdown. </li>
   *
   *         <li> {@link HMPPluginFrameworkEvent#FRAMEWORK_WAIT_TIMEDOUT WAIT_TIMEDOUT} - This
   *         method has timed out and returned before this Framework has
   *         stopped.</li>
   *         </ul>
   */
  HMPPluginFrameworkEvent waitForStop(unsigned long timeout);

  /**
   * Start this %HMPPluginFramework.
   *
   * <p>
   * The following steps are taken to start this %HMPPluginFramework:
   * <ol>
   * <li>If this %HMPPluginFramework is not in the {@link #STARTING} state,
   * {@link #init() initialize} this %HMPPluginFramework.</li>
   * <li>All installed plugins must be started in accordance with each
   * plugin's persistent <i>autostart setting</i>. This means some plugins
   * will not be started, some will be started with <i>lazy activation</i>
   * and some will be started with their <i>declared activation</i> policy.
   * Any exceptions that occur during plugin starting must be wrapped in a
   * {@link HMPPluginException} and then published as a plugin framework event of type
   * {@link HMPPluginFrameworkEvent::PLUGIN_ERROR}</li>
   * <li>This %PluinFramework's state is set to {@link #ACTIVE}.</li>
   * <li>A plugin framework event of type {@link HMPPluginFrameworkEvent::FRAMEWORK_STARTED} is fired</li>
   * </ol>
   *
   * @param options Ignored. There are no start options for the %HMPPluginFramework.
   * @throws HMPPluginException If this %HMPPluginFramework could not be started.
   */
  void start(const HMPPlugin::StartOptions& options = 0);

  /**
   * Stop this %HMPPluginFramework.
   *
   * <p>
   * The method returns immediately to the caller after initiating the
   * following steps to be taken on another thread.
   * <ol>
   * <li>This Framework's state is set to {@link #STOPPING}.</li>
   * <li>All installed plugins must be stopped without changing each plugin's
   * persistent <i>autostart setting</i>. If this Framework implements the
   * optional <i>Start Level Service Specification</i>, then the start level
   * of this Framework is moved to start level zero (0), as described in the
   * <i>Start Level Service Specification</i>. Any exceptions that occur
   * during plugin stopping must be wrapped in a {@link HMPPluginException} and
   * then published as a framework event of type {@link HMPPluginFrameworkEvent#PLUGIN_ERROR}</li>
   * <li>Unregister all services registered by this Framework.</li>
   * <li>Event handling is disabled.</li>
   * <li>This Framework's state is set to {@link #RESOLVED}.</li>
   * <li>All resources held by this Framework are released. This includes
   * threads, loaded libraries, open files, etc.</li>
   * <li>Notify all threads that are waiting at {@link #waitForStop(unsigned long)
   * waitForStop} that the stop operation has completed.</li>
   * </ol>
   * <p>
   * After being stopped, this Framework may be discarded, initialized or
   * started.
   *
   * @param options Ignored. There are no stop options for the Framework.
   * @throws HMPPluginException If stopping this Framework could not be
   *         initiated.
   * @see "Start Level Service Specification"
   */
  void stop(const StopOptions& options = 0);

  /**
   * The %HMPPluginFramework cannot be uninstalled.
   *
   * <p>
   * This method always throws a HMPPluginException.
   *
   * @throws HMPPluginException This Framework cannot be uninstalled.
   */
  void uninstall();

  /**
   * @see HMPPlugin::getHeaders()
   */
  QHash<QString, QString> getHeaders();

  /**
   * @see HMPPlugin::getResourceList()
   */
  QStringList getResourceList(const QString& path) const;

  /**
   * @see HMPPlugin::getResource()
   */
  QByteArray getResource(const QString& path) const;

protected:

  friend class HMPPluginFrameworkContext;

  HMPPluginFramework();

private:
  Q_DECLARE_PRIVATE(HMPPluginFramework)
  Q_DISABLE_COPY(HMPPluginFramework)
};


#endif // HMPPLUGINFRAMEWORK_H
