#ifndef REPORTTABLEPAGE_H
#define REPORTTABLEPAGE_H

#include <QButtonGroup>
#include <QWidget>
namespace Ui
{
    class FaultManagementDialog;
}
class ImagerPage;
class FastImagerPage;
class DetectorPage;
class StellarPredictionPage;
class QButtonGroup;
class FaultManagementDialog : public QWidget
{
    Q_OBJECT

public:
    explicit FaultManagementDialog(QWidget* parent = nullptr);
    ~FaultManagementDialog();
    void initMember();
    void showSwitchPage(const int& index);

private:
    Ui::FaultManagementDialog* ui;
    ImagerPage* m_imagerPage;
    FastImagerPage* m_fastImagerPage;
    DetectorPage* m_detectorPage;
    StellarPredictionPage* m_stellarPredictionPage;
    QButtonGroup* m_buttonGroup;
};

#endif  // REPORTTABLEPAGE_H
