#ifndef FILTERRESTAURANTS_H
#define FILTERRESTAURANTS_H

#include <QDialog>
#include <restaurantmenu.h>

namespace Ui {
class FilterRestaurants;
}

class FilterRestaurants : public QDialog
{
    Q_OBJECT

public:
    explicit FilterRestaurants(QWidget *parent = nullptr);
    ~FilterRestaurants();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FilterRestaurants *ui;
    RestaurantMenu *rmenu;
};

#endif // FILTERRESTAURANTS_H
