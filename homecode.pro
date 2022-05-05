    QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    change_password.cpp \
    dialog1.cpp \
    forgotpassword.cpp \
    main.cpp \
    mainwindow.cpp \
    music.cpp \
    notes.cpp \
    signup.cpp\
    todo.cpp

HEADERS += \
    change_password.h \
    dialog1.h \
    forgotpassword.h \
    mainwindow.h \
    music.h \
    notes.h \
    signup.h\
    todo.h

FORMS += \
    change_password.ui \
    dialog1.ui \
    forgotpassword.ui \
    mainwindow.ui \
    music.ui \
    notes.ui \
    signup.ui\
    todo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc \
    profile.qrc \
    songs.qrc
