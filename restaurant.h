#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <QString>

class restaurant
{
protected:
    QString name;
    QString pass;
    QString type;
public:
    restaurant();
    restaurant(QString, QString, QString type);
    void setname(QString);
    void setpass(QString);
    void settype(QString);
    QString getname();
    QString getpass();
    QString gettype();
};

#endif // RESTAURANT_H
