#ifndef USER_H
#define USER_H

#include <QMainWindow>

class user{
    protected:
        QString uname;
        QString pass;
        QString address;
    public:
        user(){}
        user(QString, QString, QString);
        void setuname(QString);
        void setpass(QString);
        void setaddress(QString);
        QString getuname();
        QString getpass();
        QString getaddress();
};

#endif // USER_H
