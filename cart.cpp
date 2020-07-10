#include "cart.h"
#include "ui_cart.h"
#include <QFile>
#include <QDebug>

Cart::Cart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cart)
{
    ui->setupUi(this);
    ui -> pushButton_2 -> hide();
    float total = 0;
    ui -> textBrowser -> setPlainText("");
    QFile file("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\cart.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Error opening file!";
    }
    QTextStream r(&file);
    int count = 0;
    while (!file.atEnd()){
        count++;
        QString line = file.readLine();
        QStringList item = line.split("_");
        item[3] = item[3].simplified();
        ui -> textBrowser ->append(QString::number(count) + ". " + item[0] + "\t" + item[1] + "\t Rs. " + item[2] + "\t " + item [3]);
        total += (item[2].toFloat() * item[3].toFloat());
    }
    ui -> textBrowser -> append("Total =" + QString::number(total));
    file.close();
}

Cart::~Cart()
{
    delete ui;
}

void Cart::on_pushButton_clicked()
{
    ch = new Checkout;
    ch -> show();
    hide();
}

void Cart::on_pushButton_2_clicked()
{
    parentWidget() -> show();
    hide();
}
