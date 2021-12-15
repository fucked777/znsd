#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
//该类为测试类，表示插件生成后，就可以根据需求开发了。生成的插件原本不带这个类。
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
