QT       += core gui
QT += core
QT += widgets
QT += network
QT += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    egalepage.cpp \
    enterpage.cpp \
    gameboard.cpp \
    loserpage.cpp \
    main.cpp \
    mainwindow.cpp \
    multiplequstion.cpp \
    numberquestion.cpp \
    shortquestion.cpp \
    signinpagge.cpp \
    signuppage.cpp \
    waitingpage.cpp \
    waittingfunc.cpp \
    welcomepage.cpp \
    winnerpage.cpp

HEADERS += \
    client.h \
    egalepage.h \
    enterpage.h \
    gameboard.h \
    loserpage.h \
    mainwindow.h \
    multiplequstion.h \
    numberquestion.h \
    shortquestion.h \
    signinpagge.h \
    signuppage.h \
    waitingpage.h \
    waittingfunc.h \
    welcomepage.h \
    winnerpage.h

FORMS += \
    egalepage.ui \
    gameboard.ui \
    loserpage.ui \
    mainwindow.ui \
    multiplequstion.ui \
    numberquestion.ui \
    shortquestion.ui \
    signuppage.ui \
    winnerpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Tic_tac_toe.svg.jpg \
    Tic_tac_toe.svg.png
