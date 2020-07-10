#ifndef CUSTOMERLOGIN_H
#define CUSTOMERLOGIN_H

#include <QDialog>
#include <customerregister.h>
#include <filterrestaurants.h>

namespace Ui {
class CustomerLogin;
}

class CustomerLogin : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerLogin(QWidget *parent = nullptr);
    ~CustomerLogin();

private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_clicked();

private:
    Ui::CustomerLogin *ui;
    CustomerRegister *cregister;
    FilterRestaurants *filterr;
    static int wcount;
};

#endif // CUSTOMERLOGIN_H
