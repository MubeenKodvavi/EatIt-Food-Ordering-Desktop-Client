#ifndef RESTAURANTMENU_H
#define RESTAURANTMENU_H

#include "restaurant.h"
#include <cart.h>
#include <QDialog>

namespace Ui {
class RestaurantMenu;
}

class RestaurantMenu : public QDialog
{
    Q_OBJECT

protected:
    restaurant r1;
    int choice;
public:
    explicit RestaurantMenu(QWidget *parent, restaurant &r);
    ~RestaurantMenu();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::RestaurantMenu *ui;
    Cart *cart;
};

#endif // RESTAURANTMENU_H
