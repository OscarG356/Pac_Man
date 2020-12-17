QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    anuncios.cpp \
    cuerpo.cpp \
    enemy.cpp \
    live.cpp \
    main.cpp \
    mainwindow.cpp \
    moneda.cpp \
    pared.cpp \
    score.cpp

HEADERS += \
    anuncios.h \
    cuerpo.h \
    enemy.h \
    live.h \
    mainwindow.h \
    moneda.h \
    pared.h \
    score.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Disenho.qrc
