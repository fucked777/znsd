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

#ifndef __HMPErrorLogAbstractModel_h
#define __HMPErrorLogAbstractModel_h

// Qt includes
#include <QSortFilterProxyModel>

// HMP includes
//#include "HMPCoreExport.h"
#include "core_global.h"
#include "HMPErrorLogLevel.h"
#include "HMPErrorLogTerminalOutput.h"

//------------------------------------------------------------------------------
class HMPErrorLogAbstractMessageHandler;
class HMPErrorLogAbstractModelPrivate;
struct HMPErrorLogContext;

//------------------------------------------------------------------------------
/// \ingroup Widgets
class HMP_CORE_EXPORT HMPErrorLogAbstractModel : public QSortFilterProxyModel
{
  Q_OBJECT
  Q_PROPERTY(bool logEntryGrouping READ logEntryGrouping WRITE setLogEntryGrouping)
  Q_PROPERTY(HMPErrorLogTerminalOutput::TerminalOutputs terminalOutputs READ terminalOutputs WRITE setTerminalOutputs)
  Q_PROPERTY(bool asynchronousLogging READ asynchronousLogging WRITE  setAsynchronousLogging)
  Q_PROPERTY(QString filePath READ filePath WRITE  setFilePath)
  Q_PROPERTY(int numberOfFilesToKeep READ numberOfFilesToKeep WRITE  setNumberOfFilesToKeep)
  Q_PROPERTY(bool fileLoggingEnabled READ fileLoggingEnabled WRITE  setFileLoggingEnabled)
  Q_PROPERTY(QString fileLoggingPattern READ fileLoggingPattern WRITE setFileLoggingPattern)
public:
  typedef QSortFilterProxyModel Superclass;
  typedef HMPErrorLogAbstractModel Self;
  explicit HMPErrorLogAbstractModel(QAbstractItemModel* itemModel, QObject* parentObject = 0);
  virtual ~HMPErrorLogAbstractModel();

  enum ColumnsIds
    {
    TimeColumn = 0,
    ThreadIdColumn,
    LogLevelColumn,
    OriginColumn,
    DescriptionColumn,
    MaxColumn = DescriptionColumn
    };

  enum ItemDataRole{
    DescriptionTextRole = Qt::UserRole + 1
    };

  /// Register a message handler.
  bool registerMsgHandler(HMPErrorLogAbstractMessageHandler * msgHandler);

  QStringList msgHandlerNames()const;

  /// Return True if the handler identified by \a handlerName is enabled
  bool msgHandlerEnabled(const QString& handlerName) const;

  /// Enable a specific handler given its name
  void setMsgHandlerEnabled(const QString& handlerName, bool enabled);

  /// Return names of the enabled message handlers
  QStringList msgHandlerEnabled()const;

  /// Enable handler identified by their names
  void setMsgHandlerEnabled(const QStringList& handlerNames);

  void enableAllMsgHandler();
  void disableAllMsgHandler();
  void setAllMsgHandlerEnabled(bool enabled);

  /// Return if messages are both printed into the terminal and added to HMPErrorLogAbstractModel.
  /// \note If TerminalOutput::None is returned, message will only be added to the model.
  HMPErrorLogTerminalOutput::TerminalOutputs terminalOutputs()const;

  /// Set terminal output mode
  /// \sa terminalOutputs()
  /// \sa TerminalOutput
  void setTerminalOutputs(const HMPErrorLogTerminalOutput::TerminalOutputs& terminalOutput);

  HMPErrorLogLevel::LogLevels logLevelFilter()const;

  void filterEntry(const HMPErrorLogLevel::LogLevels& logLevel = HMPErrorLogLevel::Unknown, bool disableFilter = false);

  bool logEntryGrouping()const;
  void setLogEntryGrouping(bool value);

  bool asynchronousLogging()const;
  void setAsynchronousLogging(bool value);

  QString filePath()const;
  void setFilePath(const QString& filePath);

  int numberOfFilesToKeep()const;
  void setNumberOfFilesToKeep(int value);

  bool fileLoggingEnabled()const;
  void setFileLoggingEnabled(bool value);

  QString fileLoggingPattern()const;
  void setFileLoggingPattern(const QString& value);

  /// Return log entry information associated with \a row and \a column.
  /// \internal
  QVariant logEntryData(int row,
                        int column = HMPErrorLogAbstractModel::DescriptionColumn,
                        int role = Qt::DisplayRole) const;

  /// Return log entry information associated with Description column.
  /// \sa HMPErrorLogAbstractModel::DescriptionColumn, logEntryData()
  Q_INVOKABLE QString logEntryDescription(int row) const;

  /// Return current number of log entries.
  /// \sa clear()
  Q_INVOKABLE int logEntryCount() const;

public Q_SLOTS:

  /// Remove all log entries from model
  void clear();

  /// \sa logEntryGrouping(), asynchronousLogging()
  void addEntry(const QDateTime& currentDateTime, const QString& threadId,
                HMPErrorLogLevel::LogLevel logLevel, const QString& origin,
                const HMPErrorLogContext &context, const QString& text);

Q_SIGNALS:
  void logLevelFilterChanged();

  /// \sa addEntry()
  void entryAdded(HMPErrorLogLevel::LogLevel logLevel);

protected:
  QScopedPointer<HMPErrorLogAbstractModelPrivate> d_ptr;

  virtual void addModelEntry(const QString& currentDateTime, const QString& threadId,
                             const QString& logLevel, const QString& origin, const QString& descriptionText) = 0;

private:
  Q_DECLARE_PRIVATE(HMPErrorLogAbstractModel)
  Q_DISABLE_COPY(HMPErrorLogAbstractModel)
};

#endif
