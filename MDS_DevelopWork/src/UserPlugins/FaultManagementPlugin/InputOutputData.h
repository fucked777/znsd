#ifndef INPUTOUTPUTDATA_H
#define INPUTOUTPUTDATA_H

#include <QWidget>

namespace Ui {
class InputOutputData;
}

class InputOutputData : public QWidget
{
    Q_OBJECT

public:
    explicit InputOutputData(QWidget *parent = nullptr);
    ~InputOutputData();

private:
    Ui::InputOutputData *ui;
};

#endif // INPUTOUTPUTDATA_H
