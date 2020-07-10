#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <customerlogin.h>
#include <restaurantlogin.h>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_customer_clicked();

    void on_pushButton_restaurant_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::MainWindow *ui;
    CustomerLogin *clogin;
    RestaurantLogin *rlogin;
};

#endif // MAINWINDOW_H
