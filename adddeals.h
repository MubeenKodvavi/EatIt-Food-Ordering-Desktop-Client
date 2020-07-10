#ifndef ADDDEALS_H
#define ADDDEALS_H

#include "restaurant.h"
#include <QDialog>

namespace Ui {
class AddDeals;
}

class AddDeals : public QDialog
{
    Q_OBJECT

protected:
    restaurant r1;

public:
    explicit AddDeals(QWidget *parent, restaurant &r);
    ~AddDeals();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::AddDeals *ui;
};

#endif // ADDDEALS_H
