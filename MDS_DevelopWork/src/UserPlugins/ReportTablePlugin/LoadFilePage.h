#ifndef LOADFILEPAGE_H
#define LOADFILEPAGE_H

#include <QWidget>

namespace Ui
{
    class LoadFilePage;
}

class LoadFilePage : public QWidget
{
    Q_OBJECT

public:
    explicit LoadFilePage(QWidget* parent = nullptr);
    ~LoadFilePage();
    void initMember();

private:
    Ui::LoadFilePage* ui;
};

#endif  // LOADFILEPAGE_H
