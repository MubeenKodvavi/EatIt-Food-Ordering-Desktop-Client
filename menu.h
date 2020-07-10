#ifndef MENU_H
#define MENU_H

#include "restaurant.h"
#include <addmenu.h>
#include <adddeals.h>
#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

protected:
    restaurant r1;

public:
    explicit Menu(QWidget *parent);
    explicit Menu(QWidget *parent, restaurant &r);
    ~Menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Menu *ui;
    AddMenu *addm;
    AddDeals *addd;
};

#endif // MENU_H
