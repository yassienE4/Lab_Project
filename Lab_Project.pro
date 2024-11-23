QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminmainpage.cpp \
    adminmanageitems.cpp \
    adminmanagerentals.cpp \
    adminmanageusers.cpp \
    allaccounts.cpp \
    centerflow.cpp \
    item.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    registerwindow.cpp \
    reserveitems.cpp \
    userbrowseitems.cpp \
    usermainpage.cpp \
    users.cpp \
    userviewrentalhistory.cpp \
    userviewreservations.cpp

HEADERS += \
    admin.h \
    adminmainpage.h \
    adminmanageitems.h \
    adminmanagerentals.h \
    adminmanageusers.h \
    allaccounts.h \
    centerflow.h \
    item.h \
    loginwindow.h \
    mainwindow.h \
    registerwindow.h \
    reserveitems.h \
    userbrowseitems.h \
    usermainpage.h \
    users.h \
    userviewrentalhistory.h \
    userviewreservations.h

FORMS += \
    adminmainpage.ui \
    adminmanageitems.ui \
    adminmanagerentals.ui \
    adminmanageusers.ui \
    loginwindow.ui \
    mainwindow.ui \
    registerwindow.ui \
    reserveitems.ui \
    userbrowseitems.ui \
    usermainpage.ui \
    userviewrentalhistory.ui \
    userviewreservations.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
RESOURCES += \
    resources.qrc
