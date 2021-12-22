#ifndef REPORTTABLEPAGE_H
#define REPORTTABLEPAGE_H
#include <QWidget>
namespace Ui
{
    class ProductManagementDialog;
}
class ImagerPage;
class FastImagerPage;
class DetectorPage;
class StellarPredictionPage;
class ProductManagementDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManagementDialog(QWidget* parent = nullptr);
    ~ProductManagementDialog();

private:
    Ui::ProductManagementDialog* ui;
    ImagerPage* m_imagerPage;
    FastImagerPage* m_fastImagerPage;
    DetectorPage* m_detectorPage;
    StellarPredictionPage* m_stellarPredictionPage;
};

#endif  // REPORTTABLEPAGE_H
