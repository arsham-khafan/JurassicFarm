QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aghol.cpp \
    animals_place.cpp \
    aval.cpp \
    gandom.cpp \
    gavdari.cpp \
    khata.cpp \
    main.cpp \
    Data.cpp \
    mainwindow.cpp \
    morghdari.cpp \
    msg.cpp \
    ranking.cpp \
    signupp.cpp \
    siloo.cpp \
    storage.cpp \
    store.cpp \
    widget.cpp \
    yonje.cpp

HEADERS += \
    Data.h \
    aghol.h \
    animals_place.h \
    aval.h \
    gandom.h \
    gavdari.h \
    khata.h \
    mainwindow.h \
    morghdari.h \
    msg.h \
    ranking.h \
    signupp.h \
    siloo.h \
    storage.h \
    store.h \
    widget.h \
    yonje.h

FORMS += \
    Data.ui \
    aval.ui \
    gandom.ui \
    khata.ui \
    mainwindow.ui \
    ranking.ui \
    signupp.ui \
    store.ui \
    widget.ui \
    yonje.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc \
    resources2.qrc

DISTFILES += \
    icons/1.ico \
    icons/2.ico \
    icons/3.ico \
    icons/Bill.png \
    icons/Gandom.jfif \
    icons/Hen _osaurus.png \
    icons/Mikh.png \
    icons/Pashm.jfif \
    icons/Sheep_osaurus.png \
    icons/back.png \
    icons/back2.png \
    icons/back22.png \
    icons/coins.png \
    icons/egg.png \
    icons/egg2.png \
    icons/egg_.png \
    icons/forward.png \
    icons/images (10).jfif \
    icons/milk.png \
    icons/milk2.png \
    icons/milk_.png \
    icons/nail.png \
    icons/shovel.png \
    icons/talk1.png \
    icons/time.png \
    icons/up.png \
    icons/upgrade.png \
    icons/upgrade2.png \
    icons/uplevel.png \
    icons/whool.png \
    icons/whool2.png \
    icons/xp.png \
    icons/yonje.png
