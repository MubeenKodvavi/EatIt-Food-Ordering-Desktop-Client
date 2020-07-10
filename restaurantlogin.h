#ifndef RESTAURANTLOGIN_H
#define RESTAURANTLOGIN_H

#include <QDialog>
#include "menu.h"

namespace Ui {
class RestaurantLogin;
}

class RestaurantLogin : public QDialog
{
    Q_OBJECT

public:
    explicit RestaurantLogin(QWidget *parent = nullptr);
    ~RestaurantLogin();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::RestaurantLogin *ui;
    Menu *menu;
    static int wcount;
};

#endif // RESTAURANTLOGIN_H
