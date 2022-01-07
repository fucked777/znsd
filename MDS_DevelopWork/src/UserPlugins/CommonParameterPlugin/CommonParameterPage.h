#ifndef COMMONPARAMETERPAGE_H
#define COMMONPARAMETERPAGE_H

#include <QWidget>

namespace Ui
{
    class CommonParameterPage;
}
class CommonParameterTableView;
class CommonParameterDetailTable;
class CommonParameterPage : public QWidget
{
    Q_OBJECT

public:
    explicit CommonParameterPage(QWidget* parent = nullptr);
    ~CommonParameterPage();
    void initMember();

private slots:
    void on_pushButton_clicked();
    void dataSendSlot(const QStringList& data);

private:
    Ui::CommonParameterPage* ui;
    CommonParameterTableView* m_commonParameterTableView;
    CommonParameterDetailTable* m_commonParameterDetailTable;
};

#endif  // COMMONPARAMETERPAGE_H
