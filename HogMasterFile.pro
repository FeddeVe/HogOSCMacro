QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    myosc.cpp \
    osc_button.cpp \
    osc_commandlinebutton.cpp \
    osc_common.cpp \
    osc_interface.cpp \
    osc_led_btn.cpp \
    pagehelper.cpp

HEADERS += \
    mainwindow.h \
    myosc.h \
    osc_button.h \
    osc_commandlinebutton.h \
    osc_common.h \
    osc_interface.h \
    osc_led_btn.h \
    pagehelper.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



