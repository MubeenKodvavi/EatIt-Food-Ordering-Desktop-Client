#ifndef ADDMENU_H
#define ADDMENU_H

#include "restaurant.h"
#include <QDialog>

namespace Ui {
class AddMenu;
}

class AddMenu : public QDialog
{
    Q_OBJECT

protected:
    restaurant r1;

public:
    explicit AddMenu(QWidget *parent, restaurant &r);
    ~AddMenu();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::AddMenu *ui;
};

#endif // ADDMENU_H
