QT       += core gui
QT += core
QT += widgets
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    gameboard.cpp \
    main.cpp \
    mainwindow.cpp \
    signuppage.cpp

HEADERS += \
    client.h \
    gameboard.h \
    mainwindow.h \
    signuppage.h

FORMS += \
    gameboard.ui \
    mainwindow.ui \
    signuppage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
