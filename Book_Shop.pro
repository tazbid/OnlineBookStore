#-------------------------------------------------
#
# Project created by QtCreator 2019-02-17T21:00:34
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Book1
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
        main.cpp \
        mainwindow.cpp \
    admin.cpp \
    adsuccess.cpp \
    user_book_list.cpp \
    admin_add_book.cpp \
    database.cpp \
    admin_book_list.cpp \
    user_buy_book.cpp \
    admin_add_existing_book.cpp \
    user_search_book.cpp \
    admin_see_statistics.cpp \
    admin_delete_book.cpp

HEADERS += \
        mainwindow.h \
    admin.h \
    adsuccess.h \
    user_book_list.h \
    admin_add_book.h \
    database.h \
    admin_book_list.h \
    user_buy_book.h \
    admin_add_existing_book.h \
    user_search_book.h \
    admin_see_statistics.h \
    admin_delete_book.h

FORMS += \
        mainwindow.ui \
    admin.ui \
    adsuccess.ui \
    user_book_list.ui \
    admin_add_book.ui \
    database.ui \
    admin_book_list.ui \
    user_buy_book.ui \
    admin_add_existing_book.ui \
    user_search_book.ui \
    admin_see_statistics.ui \
    admin_delete_book.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
