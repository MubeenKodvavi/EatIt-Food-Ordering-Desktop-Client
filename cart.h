#ifndef CART_H
#define CART_H

#include <QDialog>
#include <checkout.h>

namespace Ui {
class Cart;
}

class Cart : public QDialog
{
    Q_OBJECT

public:
    explicit Cart(QWidget *parent = nullptr);
    ~Cart();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Cart *ui;
    Checkout *ch;
};

#endif // CART_H
