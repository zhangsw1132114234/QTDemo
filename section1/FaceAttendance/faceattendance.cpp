#include "faceattendance.h"
#include "ui_faceattendance.h"

FaceAttendance::FaceAttendance(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FaceAttendance)
{
    ui->setupUi(this);
}

FaceAttendance::~FaceAttendance()
{
    delete ui;
}

