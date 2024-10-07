#ifndef FACEATTENDANCE_H
#define FACEATTENDANCE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FaceAttendance; }
QT_END_NAMESPACE

class FaceAttendance : public QMainWindow
{
    Q_OBJECT

public:
    FaceAttendance(QWidget *parent = nullptr);
    ~FaceAttendance();

private:
    Ui::FaceAttendance *ui;
};
#endif // FACEATTENDANCE_H
