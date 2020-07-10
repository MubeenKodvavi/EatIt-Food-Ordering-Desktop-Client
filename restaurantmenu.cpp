#include "restaurantmenu.h"
#include "ui_restaurantmenu.h"
#include "restaurant.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

RestaurantMenu::RestaurantMenu(QWidget *parent, restaurant &r) :
    QDialog(parent),
    ui(new Ui::RestaurantMenu)
{
    ui->setupUi(this);
    r1.setname(r.getname());
    r1.setpass(r.getpass());
    r1.settype(r.gettype());
    QPixmap pix (":/resources/logos/" + r1.getname() + ".png");
    ui -> label_3 -> setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
    on_pushButton_3_clicked();

    ui -> comboBox -> addItem("Quantity");
    for(int i = 1; i <= 10; i++){
        ui -> comboBox -> addItem(QString::number(i));
    }
}

RestaurantMenu::~RestaurantMenu()
{
    delete ui;
}

void RestaurantMenu::on_pushButton_3_clicked()
{
    ui -> textBrowser -> setPlainText("");
    QString name = r1.getname();
    QFile file("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\restaurants\\" + name + " menu.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Error opening file!";
    }
    QTextStream r(&file);
    int count = 0;
    while (!file.atEnd()){
        count++;
        QString line = file.readLine();
        QStringList item = line.split("_");
        item[1] = item[1].simplified();
        ui -> textBrowser ->append(QString::number(count) + ". " + item[0] + "\t Rs. " + item[1]);
    }
    choice = 0;
    file.close();
    ui -> pushButton_3 -> hide();
    ui -> pushButton -> show();
}

void RestaurantMenu::on_pushButton_clicked()
{
    ui -> textBrowser -> setPlainText("");
    QString name = r1.getname();
    QFile file("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\restaurants\\" + name + " deals.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Error opening file!";
    }
    QTextStream r(&file);
    int count = 0;
    while (!file.atEnd()){
        count++;
        QString line = file.readLine();
        QStringList item = line.split("_");
        item[1] = item[1].simplified();
        ui -> textBrowser ->append(QString::number(count) + ". " + item[0] + "\t Rs. " + item[1]);
    }
    choice = 1;
    file.close();
    ui -> pushButton_3 -> show();
    ui -> pushButton -> hide();
}

void RestaurantMenu::on_pushButton_2_clicked()
{
    if (ui -> comboBox -> currentText() == "Quantity"){
        QMessageBox::critical(this, "No quantity selected", "Please enter quantity of item, you want to order");
        return;
    }
    QString name = r1.getname();
    QString path;
    if(choice == 0){
        path = "C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\restaurants\\" + name + " menu.txt";
    }
    else{
        path = "C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\restaurants\\" + name + " deals.txt";
    }
    QFile file(path);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Error opening file";
    }
    QFile bill("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\cart.txt");
    if(!bill.open(QFile::WriteOnly | QFile::Append)){
        qDebug() << "Error opening file bill";
    }
    QTextStream w(&bill);
    QTextStream r(&file);

    int count = 0;
    while (!file.atEnd()){
        count++;
        QString line = file.readLine();
        QStringList item = line.split("_");
        item[1] = item[1].simplified();
        QString ch = ui -> lineEdit -> text();
        QString quantity = ui -> comboBox -> currentText();
        if(count == ch.toInt()){
            w << r1.getname() << "_" << item[0] << "_" << item[1] << "_" << quantity     << endl;
           //Message Box function overloaded to show options.
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Item added to cart","Item successfully added to cart. Do you want to continue to cart?", QMessageBox::Yes | QMessageBox::No );
            if(reply == QMessageBox::Yes){
                cart = new Cart;
                cart -> show();
                hide();
            }
        }
    }
    file.close();
    bill.close();
}

void RestaurantMenu::on_pushButton_4_clicked()
{
    parentWidget() -> show();
    hide();
}
