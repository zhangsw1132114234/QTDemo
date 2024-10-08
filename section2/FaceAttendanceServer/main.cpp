#include "faceattendanceserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FaceAttendanceServer w;
    w.show();
    return a.exec();
}
