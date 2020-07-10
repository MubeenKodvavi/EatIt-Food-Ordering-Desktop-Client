#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QDialog>

namespace Ui {
class Checkout;
}

class Checkout : public QDialog
{
    Q_OBJECT

protected:
    static int count;

public:
    explicit Checkout(QWidget *parent = nullptr);
    ~Checkout();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_radioButton_toggled(bool checked);

private:
    Ui::Checkout *ui;
};

#endif // CHECKOUT_H
