QT       += core gui

QT += sql

QT += core gui sql widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

CONFIG += sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buttons.cpp \
    database_logic.cpp \
    db_add.cpp \
    db_get.cpp \
    db_get_all.cpp \
    db_mapping.cpp \
    main.cpp \
    main_pushbuttons.cpp \
    main_window.cpp \
    pdf_creator.cpp \
    populates.cpp \
    refresh_tables.cpp

HEADERS += \
    database_logic.h \
    main_window.h

FORMS += \
    main_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    bg_images.qrc \
    db_conf.qrc \
    page1_bg.qrc

DISTFILES += \
    .gitignore
