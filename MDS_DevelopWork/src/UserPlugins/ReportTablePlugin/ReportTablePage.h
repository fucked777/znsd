#ifndef REPORTTABLEPAGE_H
#define REPORTTABLEPAGE_H

#include <QButtonGroup>
#include <QWidget>
namespace Ui
{
    class ReportTablePage;
}
class FaultMsgPage;
class LogMsgPage;
class LoadFilePage;
class QButtonGroup;
class ReportTablePage : public QWidget
{
    Q_OBJECT

public:
    explicit ReportTablePage(QWidget* parent = nullptr);
    ~ReportTablePage();
    void initMember();
    void showSwitchPage(const int& index);

private:
    Ui::ReportTablePage* ui;
    FaultMsgPage* m_faultMsgPage;
    LogMsgPage* m_logMsgPage;
    LoadFilePage* m_loadFilePage;
    QButtonGroup* m_buttonGroup;
};

#endif  // REPORTTABLEPAGE_H
