QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstract_reader.cpp \
    coloredqtextbrowser.cpp \
    csv_parse_error_exeption.cpp \
    csvreader.cpp \
    csvwriter.cpp \
    json_parse_error_exception.cpp \
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
    csv_parse_error_exeption.h \
    csvreader.h \
    csvwriter.h \
    json_parse_error_exception.h \
    jsonreader.h \
    mainwindow.h \
    nlohmann/json.hpp \
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
