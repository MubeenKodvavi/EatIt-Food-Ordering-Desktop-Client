#include "addmenu.h"
#include "ui_addmenu.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

AddMenu::AddMenu(QWidget *parent, restaurant &r) :
    QDialog(parent),
    ui(new Ui::AddMenu)
{
    ui->setupUi(this);
    r1.setname(r.getname());
    r1.setpass(r.getpass());
    r1.settype(r.gettype());
}

AddMenu::~AddMenu()
{
    delete ui;
}

void AddMenu::on_pushButton_clicked()
{
    QString name = r1.getname();
    QFile file("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\restaurants\\" + name + " menu.txt");
    if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text)){
        qDebug() << "Error opening file!";
    }
    QTextStream w(&file);
    w << ui -> lineEdit -> text() << "_" << ui -> lineEdit_2 -> text() << endl;
    file.close();
    QMessageBox::information(this, "Menu updated", "Your new item has been added to the menu");
}

void AddMenu::on_pushButton_2_clicked()
{
    parentWidget() -> show();
    hide();
}

