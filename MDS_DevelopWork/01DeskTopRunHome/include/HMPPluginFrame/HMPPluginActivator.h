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

#ifndef HMPPLUGINACTIVATOR_H_
#define HMPPLUGINACTIVATOR_H_

#include "HMPPluginContext.h"

/**
 * \ingroup PluginFramework
 *
 * Customizes the starting and stopping of a plugin.
 * <p>
 * <code>%HMPPluginActivator</code> is an interface that must be implemented by
 * every plugin in the Framework. The Framework can create instances of a
 * plugin's <code>%HMPPluginActivator</code> as required. If an instance's
 * <code>HMPPluginActivator::start</code> method executes successfully, it is
 * guaranteed that the same instance's <code>HMPPluginActivator::stop</code>
 * method will be called when the plugin is to be stopped. The Framework must
 * not concurrently call a <code>%HMPPluginActivator</code> object.
 *
 * <p>
 * <code>%HMPPluginActivator</code> is a Qt interface which must be implemented
 * using the standard Qt Plugin facilities:
 *
 * <p>
 * \code
 * class MyPlugin : public QObject, public HMPPluginActivator
 * {
 *   Q_OBJECT
 *   Q_INTERFACES(HMPPluginActivator)
 *
 * public:
 *   void start(HMPPluginContext* context);
 *   void stop(HMPPluginContext* context);
 * };
 * \endcode
 * And in your implementation file:
 * \code
 * Q_EXPORT_PLUGIN2(mypluginlib, MyPlugin)
 * \endcode
 * where <code>mypluginlib</code> is the basename of your shared plugin library.
 *
 * <p>
 * See the Qt Documentation about <a href="http://doc.trolltech.com/4.6/plugins-howto.html">
 * How to Create Qt Plugins</a> for details.
 *
 * The class implementing the <code>%HMPPluginActivator</code> interface must have a public
 * constructor that takes no parameters so that a <code>%HMPPluginActivator</code>
 * object can be created by <code>QPluginLoader::instance</code>.
 *
 */
class HMPPluginActivator
{
public:

  virtual ~HMPPluginActivator() {}

  /**
   * Called when this plugin is started so the Framework can perform the
   * plugin-specific activities necessary to start this plugin. This method
   * can be used to register services or to allocate any resources that this
   * plugin needs.
   *
   * <p>
   * This method must complete and return to its caller in a timely manner.
   *
   * @param context The execution context of the plugin being started.
   * @throws std::exception If this method throws an exception, this
   *         plugin is marked as stopped and the Framework will remove this
   *         plugin's listeners, unregister all services registered by this
   *         plugin, and release all services used by this plugin.
   */
  virtual void start(HMPPluginContext* context) = 0;

  /**
   * Called when this plugin is stopped so the Framework can perform the
   * plugin-specific activities necessary to stop the plugin. In general, this
   * method should undo the work that the <code>HMPPluginActivator::start</code>
   * method started. There should be no active threads that were started by
   * this plugin when this plugin returns. A stopped plugin must not call any
   * Framework objects.
   *
   * <p>
   * This method must complete and return to its caller in a timely manner.
   *
   * @param context The execution context of the plugin being stopped.
   * @throws std::exception If this method throws an exception, the
   *         plugin is still marked as stopped, and the Framework will remove
   *         the plugin's listeners, unregister all services registered by the
   *         plugin, and release all services used by the plugin.
   */
  virtual void stop(HMPPluginContext* context) = 0;

};

Q_DECLARE_INTERFACE(HMPPluginActivator, "org.commontk.pluginfw.pluginactivator")

#endif /* HMPPLUGINACTIVATOR_H_ */
