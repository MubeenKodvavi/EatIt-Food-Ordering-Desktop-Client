#include "adddeals.h"
#include "ui_adddeals.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

AddDeals::AddDeals(QWidget *parent, restaurant &r) :
    QDialog(parent),
    ui(new Ui::AddDeals)
{
    ui->setupUi(this);
    r1.setname(r.getname());
    r1.setpass(r.getpass());
    r1.settype(r.gettype());
}

AddDeals::~AddDeals()
{
    delete ui;
}

void AddDeals::on_pushButton_clicked()
{
    QString name = r1.getname();
    QFile file("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\restaurants\\" + name + " deals.txt");
    if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text)){
        qDebug() << "Error opening file!";
    }
    QTextStream w(&file);
    w << ui -> lineEdit -> text() << "_" << ui -> lineEdit_2 -> text() << endl;
    file.close();
    QMessageBox::information(this, "Menu updated", "Your new ite has been added to the menu");
}


void AddDeals::on_pushButton_2_clicked()
{
    parentWidget() -> show(); // goes to parent class
    hide();
}
