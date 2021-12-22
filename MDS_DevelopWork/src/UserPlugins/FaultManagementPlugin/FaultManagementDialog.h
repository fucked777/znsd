#ifndef REPORTTABLEPAGE_H
#define REPORTTABLEPAGE_H

#include <QButtonGroup>
#include <QWidget>
namespace Ui
{
    class FaultManagementDialog;
}
class FaultPageFream;
class FaultManagementDialog : public QWidget
{
    Q_OBJECT

public:
    explicit FaultManagementDialog(QWidget* parent = nullptr);
    ~FaultManagementDialog();
    void initMember();

private:
    Ui::FaultManagementDialog* ui;

    //    FaultPageFream* m_faultPageFream;
};

#endif  // REPORTTABLEPAGE_H
