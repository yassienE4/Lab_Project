QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogin.cpp \
    adminmanageitems.cpp \
    adminmanagerentals.cpp \
    adminmanageusers.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    registerwindow.cpp \
    reserveitems.cpp \
    userbrowseitems.cpp \
    userlogin.cpp \
    userviewrentalhistory.cpp \
    userviewreservations.cpp

HEADERS += \
    adminlogin.h \
    adminmanageitems.h \
    adminmanagerentals.h \
    adminmanageusers.h \
    loginwindow.h \
    mainwindow.h \
    registerwindow.h \
    reserveitems.h \
    userbrowseitems.h \
    userlogin.h \
    userviewrentalhistory.h \
    userviewreservations.h

FORMS += \
    adminlogin.ui \
    adminmanageitems.ui \
    adminmanagerentals.ui \
    adminmanageusers.ui \
    loginwindow.ui \
    mainwindow.ui \
    registerwindow.ui \
    reserveitems.ui \
    userbrowseitems.ui \
    userlogin.ui \
    userviewrentalhistory.ui \
    userviewreservations.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
