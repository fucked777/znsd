#ifndef LOADFILEPAGE_H
#define LOADFILEPAGE_H

#include <QWidget>

namespace Ui
{
    class LoadFilePage;
}
class LoadFilePageWidget;
class SqlLoadFileManager;
class LoadFilePage : public QWidget
{
    Q_OBJECT

public:
    explicit LoadFilePage(QWidget* parent = nullptr);
    ~LoadFilePage();
    void initMember();
    void initView();
    void setArrayDataInterface();

private:
    void processExport(const QString& fileName);
    void queryBtnClicked();
    void exportStatus();
    void searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                    const QDateTime& start_time, const QDateTime& end_time);

public:
    void slotUpdataTable();

private:
    Ui::LoadFilePage* ui;
    LoadFilePageWidget* m_pageNavigator;
    SqlLoadFileManager* m_sqlLoadFileManager;
};

#endif  // LOADFILEPAGE_H
