#ifndef CALLPROCESSPARAMETER_H
#define CALLPROCESSPARAMETER_H

#include <QWidget>

namespace Ui {
class CallProcessParameter;
}

class CallProcessParameter : public QWidget
{
    Q_OBJECT

public:
    explicit CallProcessParameter(QWidget *parent = nullptr);
    ~CallProcessParameter();

private:
    Ui::CallProcessParameter *ui;
};

#endif // CALLPROCESSPARAMETER_H
