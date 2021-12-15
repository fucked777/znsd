#ifndef REPORTTABLEPAGE_H
#define REPORTTABLEPAGE_H

#include <QButtonGroup>
#include <QWidget>
namespace Ui
{
    class ProductManagementDialog;
}
class ImagerPage;
class FastImagerPage;
class DetectorPage;
class StellarPredictionPage;
class QButtonGroup;
class ProductManagementDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManagementDialog(QWidget* parent = nullptr);
    ~ProductManagementDialog();
    void initMember();
    void showSwitchPage(const int& index);

private:
    Ui::ProductManagementDialog* ui;
    ImagerPage* m_imagerPage;
    FastImagerPage* m_fastImagerPage;
    DetectorPage* m_detectorPage;
    StellarPredictionPage* m_stellarPredictionPage;
    QButtonGroup* m_buttonGroup;
};

#endif  // REPORTTABLEPAGE_H
