QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    colored_qtextbrowser.cpp \
    csvreader.cpp \
    csvwriter.cpp \
    main.cpp \
    mainwindow.cpp \
    research_associate.cpp \
    student.cpp \
    teacher.cpp \
    university_man.cpp

HEADERS += \
    colored_qtextbrowser.h \
    csvreader.h \
    csvwriter.h \
    mainwindow.h \
    research_associate.h \
    student.h \
    teacher.h \
    university_man.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
