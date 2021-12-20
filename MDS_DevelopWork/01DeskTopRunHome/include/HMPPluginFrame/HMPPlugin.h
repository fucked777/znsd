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

#ifndef HMPPLUGIN_H
#define HMPPLUGIN_H

#include <QHash>
#include <QWeakPointer>
#include <QMetaType>
#include <QUrl>

#include "HMPVersion.h"
#include "HMPPluginLocalization.h"
#include "HMPPluginConstants.h"
#include "service/log/HMPLogStream.h"

class HMPPluginContext;
class HMPPluginArchive;
class HMPPluginFrameworkContext;
class HMPPluginPrivate;

/**
 * \HMP PluginFramework 插件框架体系
 *
 * 本框架提供符合OSGI的插件框架，提供插件的动态加载、卸载等功能。
 *
 * <p>
 * A <code>%HMPPlugin</code> object is the access point to define the lifecycle of
 * an installed plugin. Each plugin installed in the plugin environment must have
 * an associated <code>%HMPPlugin</code> object.
 *
 * <p>
 * 一个插件只有一个独立的身份，由插件框架来分配； 在整个插件生命周期内，这个身份不会被改变；
 * 甚至在插件升级的事后，也不能该改变；但是卸载，重装这个插件，会被重新分配一个独立的身份。
 * <p>
 * 插件状态只可在以下6种状态中的一种:
 * <ul>
 * <li>{@link #UNINSTALLED}
 * <li>{@link #INSTALLED}
 * <li>{@link #RESOLVED}
 * <li>{@link #STARTING}
 * <li>{@link #STOPPING}
 * <li>{@link #ACTIVE}
 * </ul>
 * <p>
 * 可以通过States这个状态来确定插件是否可用；状态获取使用   <code> State getState() const  </code> 
 *
 * <p>
 * 插件只有在以下几种状态下才会正常运行。
 * <code>STARTING</code>, 
 * <code>ACTIVE</code>,
 * <code>STOPPING</code>.
 * <code>UNINSTALLED</code>
 * 
 * 插件为 <code>UNINSTALLED</code> 时，不能被设置为其他状态，仅作为僵尸插件，只能被访问，因为它的引用被保存在某个地方
 * <p>
 * The Framework is the only entity that is allowed to create
 * <code>%HMPPlugin</code> objects, and these objects are only valid within the
 * Framework that created them.
 *
 * @remarks This class is thread safe.
 */
class HMP_PLUGINFW_EXPORT HMPPlugin {

public:

    /**
   * @brief The State enum 插件状态
   */
  enum State {
    /**
     * 这个插件被卸载了，可能没有被使用。
     *
     * <p>
     * The <code>UNINSTALLED</code> state is only visible after a plugin is
     * uninstalled; the plugin is in an unusable state but references to the
     * <code>%HMPPlugin</code> object may still be available and used for
     * introspection.
     */
    UNINSTALLED = 0x00000001,

    /**
     * 这个插件被安装了，但还没有被解决。
     *
     * <p>
     * A plugin is in the <code>INSTALLED</code> state when it has been
     * installed in the Framework but is not or cannot be resolved.
     * <p>
     * This state is visible if the plugin's code dependencies are not resolved.
     * The Framework may attempt to resolve an <code>INSTALLED</code> plugin's
     * code dependencies and move the plugin to the <code>RESOLVED</code>
     * state.
     */
    INSTALLED = 0x00000002,

    /**
     * 这个插件被解决了，并且可以被启动。
     *
     * <p>
     * A plugin is in the <code>RESOLVED</code> state when the Framework has
     * successfully resolved the plugin's code dependencies. These dependencies
     * include:
     * <ul>
     * <li>The plugin's required plugin dependencies from its
     * {@link HMPPluginConstants::REQUIRE_PLUGIN} Manifest header.
     * </ul>
     * <p>
     * Note that the plugin is not active yet. A plugin must be put in the
     * <code>RESOLVED</code> state before it can be started. The Framework may
     * attempt to resolve a plugin at any time.
     */
    RESOLVED = 0x00000004,

    /**
     * 插件在启动的过程中。
     *
     * <p>
     * A plugin is in the <code>STARTING</code> state when its
     * {@link #start(const StartOptions&) start} method is active. A plugin must be in this
     * state when the plugin's {@link HMPPluginActivator::start} method is called. If the
     * <code>HMPPluginActivator::start</code> method completes without exception,
     * then the plugin has successfully started and must move to the
     * <code>ACTIVE</code> state.
     * <p>
     * If the plugin does not have a
     * {@link HMPPluginConstants#ACTIVATION_EAGER eager activation policy}, then the
     * plugin may remain in this state for some time until the activation is
     * triggered.
     */
    STARTING = 0x00000008,

    /**
     * 该插件在停止的过程中。
     *
     * <p>
     * A plugin is in the <code>STOPPING</code> state when its
     * {@link #stop(const StopOptions&) stop} method is active. A plugin must be in this state
     * when the plugin's {@link HMPPluginActivator::stop} method is called. When the
     * <code>HMPPluginActivator::stop</code> method completes the plugin is
     * stopped and must move to the <code>RESOLVED</code> state.
     */
    STOPPING = 0x00000010,

    /**
     * 插件现在正在运行。
     *
     * <p>
     * A plugin is in the <code>ACTIVE</code> state when it has been
     * successfully started and activated.
     */
    ACTIVE = 0x00000020
  };

  /**
   * Represents an ORed combination of plugin states.
   *
   * @see #State
   */
  Q_DECLARE_FLAGS(States, State)

  enum StartOption {

    /**
     * The plugin start operation is transient and the persistent autostart
     * setting of the plugin is not modified.
     *
     * <p>
     * This option may be set when calling {@link #start(const StartOptions&)} to notify the
     * framework that the autostart setting of the plugin must not be modified.
     * If this option is not set, then the autostart setting of the plugin is
     * modified.
     *
     * @see #start(const StartOptions&)
     */
    START_TRANSIENT = 0x00000001,

    /**
     * The plugin start operation must activate the plugin according to the
     * plugin's declared
     * {@link HMPPluginConstants#PLUGIN_ACTIVATIONPOLICY activation policy}.
     *
     * <p>
     * This bit may be set when calling {@link #start(const StartOptions&)} to notify the
     * framework that the plugin must be activated using the plugin's declared
     * activation policy.
     *
     * @see HMPPluginConstants#PLUGIN_ACTIVATIONPOLICY
     * @see #start(const StartOptions&)
     */
    START_ACTIVATION_POLICY = 0x00000002

  };

  /**
   * Represents an ORed combination of start options.
   *
   * @see #StartOption
   */
  Q_DECLARE_FLAGS(StartOptions, StartOption)

  enum StopOption {
    /**
     * The plugin stop is transient and the persistent autostart setting of the
     * plugin is not modified.
     *
     * <p>
     * This option may be set when calling {@link #stop(const StopOptions&)} to notify the
     * framework that the autostart setting of the plugin must not be modified.
     * If this option is not set, then the autostart setting of the plugin is
     * modified.
     *
     * @see #stop(const StopOptions&)
     */
    STOP_TRANSIENT = 0x00000001
  };

  /**
   * Represents an ORed combination of stop options.
   *
   * @see #StopOption
   */
  Q_DECLARE_FLAGS(StopOptions, StopOption)

  virtual ~HMPPlugin();

  /**
   * Returns this plugin's current state.
   *
   * <p>
   * A plugin can be in only one state at any time.
   *
   * @return An element of <code>UNINSTALLED</code>,<code>INSTALLED</code>,
   *         <code>RESOLVED</code>,<code>STARTING</code>,
   *         <code>STOPPING</code>,<code>ACTIVE</code>.
   */
  State getState() const;

  /**
   * Starts this plugin.
   *
   * <p>
   * If this plugin's state is <code>UNINSTALLED</code> then an
   * <code>HMPIllegalStateException</code> is thrown.
   * 如果这个插件的状态是<code>UNINSTALLED</code>
   * 那么则抛出一个<code>HMPIllegalStateException</code>
   * <p>
   * The following steps are required to start this bundle:
   * 启动这个bundle需要以下步骤:
   * <ol>
   * <li>If this plugin is in the process of being activated or deactivated
   * then this method must wait for activation or deactivation to complete
   * before continuing. If this does not occur in a reasonable time, a
   * <code>HMPPluginException</code> is thrown to indicate this plugin was unable
   * to be started.
   * 如果这个插件正在被激活或停用的过程中然后此方法必须等待激活或停用完成后才能继续。
   * <li>If this plugin's state is <code>ACTIVE</code> then this method
   * returns immediately.
   *
   * <li>If the {@link #START_TRANSIENT} option is not set then set this
   * plugin's autostart setting to <em>Started with declared activation</em>
   * if the {@link #START_ACTIVATION_POLICY} option is set or
   * <em>Started with lazy activation</em> if not set. When the Framework is
   * restarted and this plugin's autostart setting is not <em>Stopped</em>,
   * this plugin must be automatically started.
   *
   * <li>If this plugin's state is not <code>RESOLVED</code>, an attempt is
   * made to resolve this plugin. If the Framework cannot resolve this plugin,
   * a <code>HMPPluginException</code> is thrown.
   *
   * <li>If the {@link #START_ACTIVATION_POLICY} option is not set then:
   * <ul>
   * <li>If this plugin's state is <code>STARTING</code> then this method
   * returns immediately.
   * <li>This plugin's state is set to <code>STARTING</code>.
   * <li>A plugin event of type {@link HMPPluginEvent::LAZY_ACTIVATION} is fired.
   * <li>This method returns immediately and the remaining steps will be
   * followed when this plugin's activation is later triggered.
   * </ul>
   * If the {@link #START_ACTIVATION_POLICY} option is set and this
   * plugin's declared activation policy is {@link HMPPluginConstants#ACTIVATION_EAGER
   * eager} then:
   * <i></i>
   * <li>This plugin's state is set to <code>STARTING</code>.
   *
   * <li>A plugin event of type {@link HMPPluginEvent::STARTING} is fired.
   *
   * <li>The {@link HMPPluginActivator::start} method of this plugin's
   * <code>HMPPluginActivator</code>, is called. If the
   * <code>HMPPluginActivator</code> throws an exception then:
   * <ul>
   * <li>This plugin's state is set to <code>STOPPING</code>.
   * <li>A plugin event of type {@link HMPPluginEvent::STOPPING} is fired.
   * <li>Any services registered by this plugin must be unregistered.
   * <li>Any services used by this plugin must be released.
   * <li>Any listeners registered by this plugin must be removed.
   * <li>This plugin's state is set to <code>RESOLVED</code>.
   * <li>A plugin event of type {@link HMPPluginEvent::STOPPED} is fired.
   * <li>A <code>HMPPluginException</code> is then thrown.
   * </ul>
   * <i></i>
   * <li>If this plugin's state is <code>UNINSTALLED</code>, because this
   * plugin was uninstalled while the <code>HMPPluginActivator::start</code>
   * method was running, a <code>HMPPluginException</code> is thrown.
   *
   * <li>This plugin's state is set to <code>ACTIVE</code>.
   *
   * <li>A plugin event of type {@link HMPPluginEvent::STARTED} is fired.
   * </ol>
   *
   * <b>Preconditions </b>
   * <ul>
   * <li><code>getState()</code> in { <code>INSTALLED</code>,
   * <code>RESOLVED</code>, <code>STARTING</code> }
   * or { <code>INSTALLED</code>, <code>RESOLVED</code> }
   * if this plugin has a eager activation policy.
   * </ul>
   * <b>Postconditions, no exceptions thrown </b>
   * <ul>
   * <li>Plugin autostart setting is modified unless the
   * {@link #START_TRANSIENT} option was set.
   * <li><code>getState()</code> in { <code>ACTIVE</code> }
   * if the eager activation policy was used.
   * <li><code>HMPPluginActivator::start()</code> has been called and did not
   * throw an exception if the eager policy was used.
   * </ul>
   * <b>Postconditions, when an exception is thrown </b>
   * <ul>
   * <li>Depending on when the exception occurred, plugin autostart setting is
   * modified unless the {@link #START_TRANSIENT} option was set.
   * <li><code>getState()</code> not in { <code>STARTING</code>,
   * <code>ACTIVE</code> }.
   * </ul>
   *
   * @param options The options for starting this plugin. See
   *        {@link #START_TRANSIENT} and {@link #START_ACTIVATION_POLICY}. The
   *        Framework must ignore unrecognized options.
   * @throws HMPPluginException If this plugin could not be started. This could
   *         be because a code dependency could not be resolved or the
   *         <code>HMPPluginActivator</code> could not be loaded or
   *         threw an exception.
   * @throws HMPIllegalStateException If this plugin has been uninstalled or this
   *         plugin tries to change its own state.
   */
  virtual void start(const StartOptions& options = START_ACTIVATION_POLICY);

  /**
   * Stops this plugin.
   *
   * <p>
   * The following steps are required to stop a plugin:
   * <ol>
   * <li>If this plugin's state is <code>UNINSTALLED</code> then an
   * <code>HMPIllegalStateException</code> is thrown.
   *
   * <li>If this plugin is in the process of being activated or deactivated
   * then this method must wait for activation or deactivation to complete
   * before continuing. If this does not occur in a reasonable time, a
   * <code>HMPPluginException</code> is thrown to indicate this plugin was unable
   * to be stopped.
   * <li>If the {@link #STOP_TRANSIENT} option is not set then then set this
   * plugin's persistent autostart setting to <em>Stopped</em>. When the
   * Framework is restarted and this plugin's autostart setting is
   * <em>Stopped</em>, this bundle must not be automatically started.
   *
   * <li>If this plugin's state is not <code>STARTING</code> or
   * <code>ACTIVE</code> then this method returns immediately.
   *
   * <li>This plugin's state is set to <code>STOPPING</code>.
   *
   * <li>A plugin event of type {@link HMPPluginEvent::STOPPING} is fired.
   *
   * <li>If this plugin's state was <code>ACTIVE</code> prior to setting the
   * state to <code>STOPPING</code>, the {@link HMPPluginActivator#stop} method
   * of this plugin's <code>HMPPluginActivator</code> is
   * called. If that method throws an exception, this method must continue to
   * stop this plugin and a <code>HMPPluginException</code> must be thrown after
   * completion of the remaining steps.
   *
   * <li>Any services registered by this plugin must be unregistered.
   * <li>Any services used by this plugin must be released.
   * <li>Any listeners registered by this plugin must be removed.
   *
   * <li>If this plugin's state is <code>UNINSTALLED</code>, because this
   * plugin was uninstalled while the <code>HMPPluginActivator::stop</code> method
   * was running, a <code>HMPPluginException</code> must be thrown.
   *
   * <li>This plugin's state is set to <code>RESOLVED</code>.
   *
   * <li>A plugin event of type {@link HMPPluginEvent::STOPPED} is fired.
   * </ol>
   *
   * <b>Preconditions </b>
   * <ul>
   * <li><code>getState()</code> in { <code>ACTIVE</code> }.
   * </ul>
   * <b>Postconditions, no exceptions thrown </b>
   * <ul>
   * <li>Plugin autostart setting is modified unless the
   * {@link #STOP_TRANSIENT} option was set.
   * <li><code>getState()</code> not in &#123; <code>ACTIVE</code>,
   * <code>STOPPING</code> &#125;.
   * <li><code>HMPPluginActivator::stop</code> has been called and did not throw
   * an exception.
   * </ul>
   * <b>Postconditions, when an exception is thrown </b>
   * <ul>
   * <li>Plugin autostart setting is modified unless the
   * {@link #STOP_TRANSIENT} option was set.
   * </ul>
   *
   * @param options The options for stoping this bundle. See
   *        {@link #STOP_TRANSIENT}.
   * @throws HMPPluginException If this plugin's <code>HMPPluginActivator</code>
   *         threw an exception.
   * @throws HMPIllegalStateException If this plugin has been uninstalled or this
   *         plugin tries to change its own state.
   */
  virtual void stop(const StopOptions& options = 0);

  /**
   * Updates this plugin from a <code>QUrl</code>.
   *
   * <p>
   * If the specified <code>QURl</code> is <code>empty</code>, the
   * Framework creates the <code>QUrl</code> from which to read the
   * updated plugin by interpreting, in an implementation dependent manner,
   * this plugin's {@link HMPPluginConstants#PLUGIN_UPDATELOCATION
   * Plugin-UpdateLocation} Manifest header, if present, or this plugin's
   * original location.
   *
   * <p>
   * If this plugin's state is <code>ACTIVE</code>, it must be stopped before
   * the update and started after the update successfully completes.
   *
   * <p>
   * If this plugin has exported any classes that are used by another
   * plugin, these classes remain available until the Framework is relaunched.
   *
   * <p>
   * The following steps are required to update a plugin:
   * <ol>
   * <li>If this plugin's state is <code>UNINSTALLED</code> then an
   * <code>HMPIllegalStateException</code> is thrown.
   *
   * <li>If this plugin's state is <code>ACTIVE</code>, <code>STARTING</code>
   * or <code>STOPPING</code>, this plugin is stopped as described in the
   * <code>HMPPlugin::stop()</code> method. If <code>HMPPlugin::stop()</code> throws an
   * exception, the exception is rethrown terminating the update.
   *
   * <li>The updated version of this plugin is read from the URL and
   * installed. If the Framework is unable to install the updated version of
   * this plugin, the original version of this plugin is restored and a
   * <code>HMPPluginException</code> is thrown after completion of the
   * remaining steps.
   *
   * <li>This plugin's state is set to <code>INSTALLED</code>.
   *
   * <li>If the updated version of this plugin was successfully installed, a
   * plugin event of type {@link HMPPluginEvent#UPDATED} is fired.
   *
   * <li>If this plugin's state was originally <code>ACTIVE</code>, the
   * updated plugin is started as described in the <code>HMPPlugin::start()</code>
   * method. If <code>HMPPlugin::start()</code> throws an exception, a Framework
   * event of type {@link HMPPluginFrameworkEvent#PLUGIN_ERROR} is fired containing the
   * exception.
   * </ol>
   *
   * <b>Preconditions </b>
   * <ul>
   * <li><code>getState()</code> not in &#x007B; <code>UNINSTALLED</code>
   * &#x007D;.
   * </ul>
   * <b>Postconditions, no exceptions thrown </b>
   * <ul>
   * <li><code>getState()</code> in &#x007B; <code>INSTALLED</code>,
   * <code>RESOLVED</code>, <code>ACTIVE</code> &#x007D;.
   * <li>This plugin has been updated.
   * </ul>
   * <b>Postconditions, when an exception is thrown </b>
   * <ul>
   * <li><code>getState()</code> in &#x007B; <code>INSTALLED</code>,
   * <code>RESOLVED</code>, <code>ACTIVE</code> &#x007D;.
   * <li>Original plugin is still used; no update occurred.
   * </ul>
   *
   * @param updateLocation The <code>QUrl</code> from which to read the new
   *        plugin or <code>null</code> to indicate the Framework must create
   *        the URL from this plugin's
   *        {@link HMPPluginConstants#PLUGIN_UPDATELOCATION Plugin-UpdateLocation}
   *        Manifest header, if present, or this plugin's original location.
   * @throws HMPPluginException If the update location cannot be read or the update
   *         fails.
   * @throws HMPIllegalStateException If this plugin has been uninstalled or this
   *         plugin tries to change its own state.
   * @see #stop()
   * @see #start()
   */
  void update(const QUrl &updateLocation = QUrl());

  /**
   * 卸载此插件
   *
   * <p>
   * 这个方法让插件框架通知其他插件这个插件正在被卸载，
   * 然后插件框架将这个插件置于卸载状态。
   * 框架必须删除它能够删除的任何与这个插件相关的资源。
   * <p>
   *
   * 如果其他已经解析的插件需要这个插件，框架必须一直加载这个插件，直到框架重新启动。
   *
   * <p>
   * 卸载插件需要以下步骤:
   * <ol>
   *		<li>
   *			如果正在卸载的这个插件状态为 <code>UNINSTALLED</code> 
   *        则抛出一个异常<code>HMPIllegalStateException</code>
   *				<li>如果这个插件的状态是 <code>ACTIVE</code>, <code>STARTING</code> 或 <code>STOPPING</code>, 
   *				调用 <code>HMPPlugin::stop</code> 则会正常关闭。
   *				如果HMPPlugin::stop抛出异常，则触发一个HMPPluginFrameworkEvent::PLUGIN_ERROR类型的框架事件，其中包含该异常。
   *			<li>这个插件的状态会被设置为 <code>UNINSTALLED</code>.
   *
   * <li>一个插件事件会被触发 HMPPluginEvent::UNINSTALLED
   *
   * <li>这个插件何为这个插件提供持久化的存储区域都会被释放
   * </ol>
   *
   * <b>如果 先判断状态 </b>
   * <ul>
   *		<li> <code>getState()</code>不是 <code>UNINSTALLED</code> 状态
   * </ul>
   * <b>然后判断 状态变为uninstall，且不抛出异常</b>
   * <ul>
   *		<li><code>getState()</code> in &#123; <code>UNINSTALLED</code>
   * &#125;.
   * <li>则此插件已被卸载。
   * </ul>
   * <b>如果抛出异常</b>
   * <ul>
   * <li><code>getState()</code> not in &#123; <code>UNINSTALLED</code>
   * &#125;.
   * <li>这个插件还没有被卸载。
   * </ul>
   *
   * @throws HMPPluginException If the uninstall failed. This can occur if
   *         another thread is attempting to change this plugin's state and
   *         does not complete in a timely manner.
   * @throws HMPIllegalStateException If this plugin has been uninstalled or this
   *         plugin tries to change its own state.
   * @see #stop()
   */
  virtual void uninstall();

  /**
   * Returns this plugin's {@link HMPPluginContext}. The returned
   * <code>HMPPluginContext</code> can be used by the caller to act on behalf
   * of this plugin.
   *
   * <p>
   * If this plugin is not in the {@link #STARTING}, {@link #ACTIVE}, or
   * {@link #STOPPING} states, then this
   * plugin has no valid <code>HMPPluginContext</code>. This method will
   * return <code>0</code> if this plugin has no valid
   * <code>HMPPluginContext</code>.
   *
   * @return A <code>HMPPluginContext</code> for this plugin or
   *         <code>0</code> if this plugin has no valid
   *         <code>HMPPluginContext</code>.
   */
  HMPPluginContext* getPluginContext() const;

  /**
   * Returns this plugin's unique identifier. This plugin is assigned a unique
   * identifier by the Framework when it was installed in the plugin
   * environment.
   *
   * <p>
   * A plugin's unique identifier has the following attributes:
   * <ul>
   * <li>Is unique and persistent.
   * <li>Is a <code>long</code>.
   * <li>Its value is not reused for another plugin, even after a plugin is
   * uninstalled.
   * <li>Does not change while a plugin remains installed.
   * <li>Does not change when a plugin is updated.
   * </ul>
   *
   * <p>
   * This method must continue to return this plugin's unique identifier while
   * this plugin is in the <code>UNINSTALLED</code> state.
   *
   * @return The unique identifier of this plugin.
   */
  long getPluginId() const;

  /**
   * Returns this plugin's location identifier.
   *
   * <p>
   * The location identifier is the location passed to
   * <code>HMPPluginContext::installPlugin</code> when a plugin is installed.
   * The location identifier does not change while this plugin remains
   * installed, even if this plugin is updated.
   *
   * <p>
   * This method must continue to return this plugin's location identifier
   * while this plugin is in the <code>UNINSTALLED</code> state.
   *
   * @return The string representation of this plugin's location identifier.
   */
  QString getLocation() const;

  /**
   * Returns this plugin's Manifest headers and values. This method returns
   * all the Manifest headers and values from the main section of this
   * bundle's Manifest file; that is, all lines prior to the first named section.
   *
   * TODO: documentation about manifest value internationalization
   *
   * <p>
   * For example, the following Manifest headers and values are included if
   * they are present in the Manifest file:
   *
   * <pre>
   *     Plugin-Name
   *     Plugin-Vendor
   *     Plugin-HMPVersion
   *     Plugin-Description
   *     Plugin-DocURL
   *     Plugin-ContactAddress
   * </pre>
   *
   * <p>
   * This method must continue to return Manifest header information while
   * this plugin is in the <code>UNINSTALLED</code> state.
   *
   * @return A <code>QHash<Qstring, QString></code> object containing this plugin's
   *         Manifest headers and values.
   */
  virtual QHash<QString, QString> getHeaders();

  /**
   * Returns the symbolic name of this plugin as specified by its
   * <code>Plugin-SymbolicName</code> manifest header. The plugin symbolic
   * name together with a version must identify a unique plugin. The plugin
   * symbolic name should be based on the reverse domain name naming
   * convention like that used for java packages.
   *
   * <p>
   * This method must continue to return this plugin's symbolic name while
   * this plugin is in the <code>UNINSTALLED</code> state.
   *
   * @return The symbolic name of this plugin or a null QString if this
   *         plugin does not have a symbolic name.
   */
  QString getSymbolicName() const;

  /**
   * Returns a list of all the files and directories
   * within this plugin whose longest sub-path matches the
   * specified path.
   * <p>
   * The specified path is always relative to the root of this plugin
   * (the plugins symbolic name) and may begin with a &quot;/&quot;.
   * A path value of &quot;/&quot; indicates the root of this plugin.
   * <p>
   * Returned paths indicating subdirectory paths end with a &quot;/&quot;.
   * The returned paths are all relative to the root of this plugin and must
   * not begin with &quot;/&quot;.
   * <p>
   *
   * @param path The path name for which to return resource paths.
   * @return A list of the resource paths (<code>QString</code>
   *         objects) or an empty list if no entry could be found.

   * @throws HMPIllegalStateException If this plugin has been
   *         uninstalled.
   */
  virtual QStringList getResourceList(const QString& path) const;

  /**
   * Returns a list of resources in this plugin.
   *
   * <p>
   * This method is intended to be used to obtain configuration, setup,
   * localization and other information from this plugin. This method can
   * either return only entries in the specified path or recurse into
   * subdirectories returning entries in the directory tree beginning at the
   * specified path.
   *
   * <p>
   * Examples:
   *
   * \code
   * // List all XML files in the OSGI-INF directory and below
   * QStringList r = b->findResources(&quot;OSGI-INF&quot;, &quot;*.xml&quot;, true);
   *
   * // Find a specific localization file
   * QStringList r = b->findResources(&quot;OSGI-INF/l10n&quot;, &quot;plugin_nl_DU.tm&quot;, false);
   * \endcode
   *
   * @param path The path name in which to look. The path is always relative
   *        to the root of this plugin and may begin with &quot;/&quot;. A
   *        path value of &quot;/&quot; indicates the root of this plugin.
   * @param filePattern The file name pattern for selecting entries in the
   *        specified path. The pattern is only matched against the last
   *        element of the entry path. Substring matching is supported, as
   *        specified in the Filter specification, using the wildcard
   *        character (&quot;*&quot;). If a null QString is specified, this
   *        is equivalent to &quot;*&quot; and matches all files.
   * @param recurse If <code>true</code>, recurse into subdirectories.
   *        Otherwise only return entries from the specified path.
   * @return A list of QString objects for each matching entry, or
   *         an empty list if an entry could not be found or if the caller
   *         does not have the appropriate
   *         <code>AdminPermission[this,RESOURCE]</code>, and the Plugin
   *         Framework supports permissions.
   * @throws HMPIllegalStateException If this plugin has been uninstalled.
   */
  virtual QStringList findResources(const QString& path, const QString& filePattern, bool recurse) const;

  /**
   * Returns a QByteArray containing a Qt resource located at the
   * specified path in this plugin.
   * <p>
   * The specified path is always relative to the root of this plugin
   * (the plugins symbolic name) and may
   * begin with &quot;/&quot;. A path value of &quot;/&quot; indicates the
   * root of this plugin.
   * <p>
   *
   * @param path The path name of the resource.
   * @return A QByteArray to the resource, or a null QByteArray if no resource could be
   *         found.
   * @throws HMPIllegalStateException If this plugin has been
   *         uninstalled.
   */
  virtual QByteArray getResource(const QString& path) const;

  /**
   * Returns a <code>HMPPluginLocalization</code> object for the
   * specified <code>locale</code>. The translations are loaded from a
   * .qm file starting with <code>base</code>.
   *
   * You can use the returned <code>HMPPluginLocalization</code>
   * object to dynamically translate text without changing the current
   * locale of the application. This can be used for example to
   * provide localized messages to multiple users which use the application
   * (maybe some kind of server) simultaneously but require different
   * localizations.
   *
   * @param locale The locale to be used by the returned
   *        <code>HMPPluginLocalization</code> object.
   * @param base The base name of the .qm message file which contains
   *        translated messages. Defaults to
   *        <code>HMPPluginConstants::PLUGIN_LOCALIZATION_DEFAULT_BASENAME</code>.
   * @return A locale specific <code>HMPPluginLocalization</code> instance.
   */
  HMPPluginLocalization getPluginLocalization(const QLocale& locale,
                                              const QString& base = HMPPluginConstants::PLUGIN_LOCALIZATION_DEFAULT_BASENAME) const;

  /**
   * Returns the version of this plugin as specified by its
   * <code>Plugin-Version</code> manifest header. If this plugin does not have a
   * specified version then {@link HMPVersion#emptyVersion} is returned.
   *
   * <p>
   * This method must continue to return this plugin's version while
   * this plugin is in the <code>UNINSTALLED</code> state.
   *
   * @return The version of this plugin.
   */
  HMPVersion getVersion() const;

protected:

  friend class HMPPluginFramework;
  friend class HMPPluginFrameworkLauncherPrivate;
  friend class HMPPluginFrameworkPrivate;
  friend class HMPPluginFrameworkContext;
  friend class HMPPlugins;
  friend class HMPServiceReferencePrivate;

  // Do NOT change this to QScopedPointer<HMPPluginPrivate>!
  // We would need to include HMPPlugin.h (and HMPPluginPrivate_p.h)
  // at a lot of places...
  HMPPluginPrivate* d_ptr;

  HMPPlugin();
  void init(HMPPluginPrivate* dd);
  void init(const QWeakPointer<HMPPlugin>& self, HMPPluginFrameworkContext* fw, QSharedPointer<HMPPluginArchive> ba);

private:
  Q_DECLARE_PRIVATE(HMPPlugin)
  Q_DISABLE_COPY(HMPPlugin)
};

/**
 * \ingroup PluginFramework
 * @{
 */

Q_DECLARE_METATYPE(HMPPlugin*)
Q_DECLARE_METATYPE(QSharedPointer<HMPPlugin>)

Q_DECLARE_OPERATORS_FOR_FLAGS(HMPPlugin::States)
Q_DECLARE_OPERATORS_FOR_FLAGS(HMPPlugin::StartOptions)
Q_DECLARE_OPERATORS_FOR_FLAGS(HMPPlugin::StopOptions)

HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug debug, HMPPlugin::State state);
HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug debug, const HMPPlugin& plugin);
HMP_PLUGINFW_EXPORT QDebug operator<<(QDebug debug, HMPPlugin const * plugin);

HMP_PLUGINFW_EXPORT HMPLogStream& operator<<(HMPLogStream& stream, HMPPlugin const * plugin);
HMP_PLUGINFW_EXPORT HMPLogStream& operator<<(HMPLogStream& stream, const QSharedPointer<HMPPlugin>& plugin);

/** @}*/

#endif // HMPPLUGIN_H
