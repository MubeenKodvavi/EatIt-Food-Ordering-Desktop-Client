#-------------------------------------------------
#
# Project created by QtCreator 2019-05-02T21:31:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FoodOrderingSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        adddeals.cpp \
        addmenu.cpp \
        cart.cpp \
        checkout.cpp \
        customerlogin.cpp \
        customerregister.cpp \
        filterrestaurants.cpp \
        main.cpp \
        mainwindow.cpp \
        menu.cpp \
        restaurant.cpp \
        restaurantlogin.cpp \
        restaurantmenu.cpp \
        user.cpp

HEADERS += \
        adddeals.h \
        addmenu.h \
        cart.h \
        checkout.h \
        customerlogin.h \
        customerregister.h \
        filterrestaurants.h \
        mainwindow.h \
        menu.h \
        restaurant.h \
        restaurantlogin.h \
        restaurantmenu.h \
        user.h

FORMS += \
        adddeals.ui \
        addmenu.ui \
        cart.ui \
        checkout.ui \
        customerlogin.ui \
        customerregister.ui \
        filterrestaurants.ui \
        mainwindow.ui \
        menu.ui \
        restaurantlogin.ui \
        restaurantmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rescources.qrc
