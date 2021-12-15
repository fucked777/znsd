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


#ifndef HMPPLUGINTRACKER_H
#define HMPPLUGINTRACKER_H

#include <QScopedPointer>

#include "HMPPluginFrameworkExport.h"

#include "HMPPlugin.h"
#include "HMPPluginTrackerCustomizer.h"

template<class T> class HMPTrackedPlugin;
template<class T> class HMPPluginTrackerPrivate;

/**
 * \ingroup PluginFramework
 *
 * The <code>HMPPluginTracker</code> class simplifies tracking plugins much like
 * the <code>HMPServiceTracker</code> simplifies tracking services.
 * <p>
 * A <code>HMPPluginTracker</code> is constructed with state criteria and a
 * <code>HMPPluginTrackerCustomizer</code> object. A <code>HMPPluginTracker</code> can
 * use the <code>HMPPluginTrackerCustomizer</code> to select which plugins are
 * tracked and to create a customized object to be tracked with the plugin. The
 * <code>HMPPluginTracker</code> can then be opened to begin tracking all plugins
 * whose state matches the specified state criteria.
 * <p>
 * The <code>getPlugins</code> method can be called to get the
 * <code>HMPPlugin</code> objects of the plugins being tracked. The
 * <code>getObject</code> method can be called to get the customized object for
 * a tracked plugin.
 * <p>
 * The <code>HMPPluginTracker</code> class is thread-safe. It does not call a
 * <code>HMPPluginTrackerCustomizer</code> while holding any locks.
 * <code>HMPPluginTrackerCustomizer</code> implementations must also be
 * thread-safe.
 *
 * \tparam T The type of the tracked object. The type must be an assignable
 *         datatype, provide a boolean conversion function, and provide
 *         a constructor and an assignment operator which can handle 0 as an argument.
 * \remarks This class is thread safe.
 */
template<class T = QSharedPointer<HMPPlugin> >
class HMPPluginTracker : protected HMPPluginTrackerCustomizer<T>
{
public:

  ~HMPPluginTracker();

  /**
   * Create a <code>HMPPluginTracker</code> for plugins whose state is present in
   * the specified state mask.
   *
   * <p>
   * Plugins whose state is present on the specified state mask will be
   * tracked by this <code>HMPPluginTracker</code>.
   *
   * @param context The <code>HMPPluginContext</code> against which the tracking
   *        is done.
   * @param stateMask The bit mask of the <code>OR</code>ing of the plugin
   *        states to be tracked.
   * @param customizer The customizer object to call when plugins are added,
   *        modified, or removed in this <code>HMPPluginTracker</code>. If
   *        customizer is <code>null</code>, then this
   *        <code>HMPPluginTracker</code> will be used as the
   *        <code>HMPPluginTrackerCustomizer</code> and this
   *        <code>HMPPluginTracker</code> will call the
   *        <code>HMPPluginTrackerCustomizer</code> methods on itself. If the
   *        customizer is not <code>null</code>, this <code>HMPPluginTracker</code>
   *        takes ownership of the customizer.
   * @see HMPPlugin#getState()
   */
  HMPPluginTracker(HMPPluginContext* context, HMPPlugin::States stateMask,
                   HMPPluginTrackerCustomizer<T>* customizer = 0);

  /**
   * Open this <code>HMPPluginTracker</code> and begin tracking plugins.
   *
   * <p>
   * HMPPlugin's which match the state criteria specified when this
   * <code>HMPPluginTracker</code> was created are now tracked by this
   * <code>HMPPluginTracker</code>.
   *
   * @throws HMPIllegalStateException If the <code>HMPPluginContext</code>
   *         with which this <code>HMPPluginTracker</code> was created is no
   *         longer valid.
   */
  virtual void open();

  /**
   * Close this <code>HMPPluginTracker</code>.
   *
   * <p>
   * This method should be called when this <code>HMPPluginTracker</code> should
   * end the tracking of plugins.
   *
   * <p>
   * This implementation calls getPlugins() to get the list of
   * tracked plugins to remove.
   */
  virtual void close();

  /**
   * Return a list of <code>HMPPlugin</code>s for all plugins being tracked by
   * this <code>HMPPluginTracker</code>.
   *
   * @return A list of <code>HMPPlugin</code>s.
   */
  virtual QList<QSharedPointer<HMPPlugin> > getPlugins() const;

  /**
   * Returns the customized object for the specified <code>HMPPlugin</code> if
   * the specified plugin is being tracked by this <code>HMPPluginTracker</code>.
   *
   * @param plugin The <code>HMPPlugin</code> being tracked.
   * @return The customized object for the specified <code>HMPPlugin</code> or
   *         <code>null</code> if the specified <code>HMPPlugin</code> is not
   *         being tracked.
   */
  virtual T getObject(QSharedPointer<HMPPlugin> plugin) const;

  /**
   * Remove a plugin from this <code>HMPPluginTracker</code>.
   *
   * The specified plugin will be removed from this <code>HMPPluginTracker</code>.
   * If the specified plugin was being tracked then the
   * <code>HMPPluginTrackerCustomizer::removedPlugin</code> method will be called
   * for that plugin.
   *
   * @param plugin The <code>HMPPlugin</code> to be removed.
   */
  virtual void remove(QSharedPointer<HMPPlugin> plugin);

  /**
   * Return the number of plugins being tracked by this
   * <code>HMPPluginTracker</code>.
   *
   * @return The number of plugins being tracked.
   */
  virtual int size() const;

  /**
   * Returns the tracking count for this <code>HMPPluginTracker</code>.
   *
   * The tracking count is initialized to 0 when this
   * <code>HMPPluginTracker</code> is opened. Every time a plugin is added,
   * modified or removed from this <code>HMPPluginTracker</code> the tracking
   * count is incremented.
   *
   * <p>
   * The tracking count can be used to determine if this
   * <code>HMPPluginTracker</code> has added, modified or removed a plugin by
   * comparing a tracking count value previously collected with the current
   * tracking count value. If the value has not changed, then no plugin has
   * been added, modified or removed from this <code>HMPPluginTracker</code>
   * since the previous tracking count was collected.
   *
   * @return The tracking count for this <code>HMPPluginTracker</code> or -1 if
   *         this <code>HMPPluginTracker</code> is not open.
   */
  virtual int getTrackingCount() const;

  /**
   * Return a <code>QMap</code> with the <code>HMPPlugin</code>s and customized
   * objects for all plugins being tracked by this <code>HMPPluginTracker</code>.
   *
   * @return A <code>QMap</code> with the <code>HMPPlugin</code>s and customized
   *         objects for all services being tracked by this
   *         <code>HMPPluginTracker</code>. If no plugins are being tracked, then
   *         the returned map is empty.
   */
  virtual QMap<QSharedPointer<HMPPlugin>, T> getTracked() const;

  /**
   * Return if this <code>HMPPluginTracker</code> is empty.
   *
   * @return <code>true</code> if this <code>HMPPluginTracker</code> is not tracking any
   *         plugins.
   */
  virtual bool isEmpty() const;

protected:

  /**
   * Default implementation of the
   * <code>HMPPluginTrackerCustomizer::addingPlugin</code> method.
   *
   * <p>
   * This method is only called when this <code>HMPPluginTracker</code> has been
   * constructed with a <code>null</code> HMPPluginTrackerCustomizer argument.
   *
   * <p>
   * This implementation simply returns the specified <code>HMPPlugin*</code> in
   * a QVariant.
   *
   * <p>
   * This method can be overridden in a subclass to customize the object to be
   * tracked for the plugin being added.
   *
   * @param plugin The <code>HMPPlugin</code> being added to this
   *        <code>HMPPluginTracker</code> object.
   * @param event The plugin event which caused this customizer method to be
   *        called or an invalid event if there is no plugin event associated
   *        with the call to this method.
   * @return The specified plugin.
   * @see HMPPluginTrackerCustomizer::addingPlugin(HMPPlugin*, const HMPPluginEvent&)
   */
  T addingPlugin(QSharedPointer<HMPPlugin> plugin, const HMPPluginEvent& event);

  /**
   * Default implementation of the
   * <code>HMPPluginTrackerCustomizer::modifiedPlugin</code> method.
   *
   * <p>
   * This method is only called when this <code>HMPPluginTracker</code> has been
   * constructed with a <code>null</code> HMPPluginTrackerCustomizer argument.
   *
   * <p>
   * This implementation does nothing.
   *
   * @param plugin The <code>HMPPlugin</code> whose state has been modified.
   * @param event The plugin event which caused this customizer method to be
   *        called or an invalid event if there is no plugin event associated
   *        with the call to this method.
   * @param object The customized object for the specified HMPPlugin.
   * @see HMPPluginTrackerCustomizer::modifiedPlugin(HMPPlugin*, const HMPPluginEvent&, QVariant)
   */
  void modifiedPlugin(QSharedPointer<HMPPlugin> plugin, const HMPPluginEvent& event, T object);

  /**
   * Default implementation of the
   * <code>HMPPluginTrackerCustomizer::removedPlugin</code> method.
   *
   * <p>
   * This method is only called when this <code>HMPPluginTracker</code> has been
   * constructed with a <code>null</code> HMPPluginTrackerCustomizer argument.
   *
   * <p>
   * This implementation does nothing.
   *
   * @param plugin The <code>HMPPlugin</code> being removed.
   * @param event The plugin event which caused this customizer method to be
   *        called or an invalid event if there is no plugin event associated
   *        with the call to this method.
   * @param object The customized object for the specified plugin.
   * @see HMPPluginTrackerCustomizer::removedPlugin(HMPPlugin*, const HMPPluginEvent&, QVariant)
   */
  void removedPlugin(QSharedPointer<HMPPlugin> plugin, const HMPPluginEvent& event, T object);

private:

  typedef HMPPluginTracker<T> PluginTracker;
  typedef HMPTrackedPlugin<T> TrackedPlugin;
  typedef HMPPluginTrackerPrivate<T> PluginTrackerPrivate;
  typedef HMPPluginTrackerCustomizer<T> PluginTrackerCustomizer;

  friend class HMPTrackedPlugin<T>;
  friend class HMPPluginTrackerPrivate<T>;

  inline PluginTrackerPrivate* d_func()
  {
    return reinterpret_cast<PluginTrackerPrivate*>(qGetPtrHelper(d_ptr));
  }

  inline const PluginTrackerPrivate* d_func() const
  {
    return reinterpret_cast<const PluginTrackerPrivate*>(qGetPtrHelper(d_ptr));
  }

  const QScopedPointer<PluginTrackerPrivate> d_ptr;
};


#include "HMPPluginTracker.tpp"

#endif // HMPPLUGINTRACKER_H
