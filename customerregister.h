#ifndef CUSTOMERREGISTER_H
#define CUSTOMERREGISTER_H

#include <QDialog>

namespace Ui {
class CustomerRegister;
}

class CustomerRegister : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerRegister(QWidget *parent = nullptr);
    ~CustomerRegister();

private slots:
    void on_pushButton_register_clicked();

private:
    Ui::CustomerRegister *ui;

};

#endif // CUSTOMERREGISTER_H
