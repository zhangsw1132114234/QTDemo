QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#win32{
#    INCLUDEPATH += D:\Embedded\lib\opencv452\include
#    INCLUDEPATH += D:\Embedded\lib\opencv452\include\opencv2
#    INCLUDEPATH += D:\Embedded\lib\SeetaFace\include
#    INCLUDEPATH += D:\Embedded\lib\SeetaFace\include\seeta

#    LIBS += D:\Embedded\lib\opencv452\x64\mingw\lib\libopencv*
#    LIBS += D:\Embedded\lib\SeetaFace\lib\libSeeta*
#}
win32{
    INCLUDEPATH += F:\lib\opencv452\include
    INCLUDEPATH += F:\lib\opencv452\include\opencv2
    INCLUDEPATH += F:\lib\SeetaFace\include
    INCLUDEPATH += F:\lib\SeetaFace\include\seeta

    LIBS += F:\lib\opencv452\x64\mingw\lib\libopencv*
    LIBS += F:\lib\SeetaFace\lib\libSeeta*
}


SOURCES += \
    main.cpp \
    faceattendanceserver.cpp \
    qfaceobject.cpp \
    registerwin.cpp

HEADERS += \
    faceattendanceserver.h \
    qfaceobject.h \
    registerwin.h

FORMS += \
    faceattendanceserver.ui \
    registerwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
