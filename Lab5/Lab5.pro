QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coloredqtextbrowser.cpp \
    csvreader.cpp \
    csvwriter.cpp \
    jsonreader.cpp \
    main.cpp \
    mainwindow.cpp \
    research_associate.cpp \
    student.cpp \
    teacher.cpp \
    university_man.cpp

HEADERS += \
    abstract_reader.h \
    coloredqtextbrowser.h \
    csvreader.h \
    csvwriter.h \
    jsonreader.h \
    mainwindow.h \
    nlohmann/json.hpp \
    parse_error_exeption.h \
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
