QT = core
QT += network
CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        bottom.cpp \
        main.cpp \
        multiple_question.cpp \
        number_question.cpp \
        questions.cpp \
        respondreqest.cpp \
        server.cpp \
        short_question.cpp \
        user_info.cpp \
        user_w_r.cpp
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    bottom.h \
    multiple_question.h \
    number_question.h \
    questions.h \
    respondreqest.h \
    server.h \
    short_question.h \
    user_info.h\
    user_w_r.h
