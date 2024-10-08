#ifndef FACEATTENDENCE_H
#define FACEATTENDENCE_H

#include <QGridLayout>
#include <QMainWindow>
#include <opencv.hpp>

#include <QTcpSocket>
#include <QTimer>

using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class FaceAttendence; }
QT_END_NAMESPACE

class FaceAttendence : public QMainWindow
{
    Q_OBJECT

public:
    FaceAttendence(QWidget *parent = nullptr);
    ~FaceAttendence();

    /* 定时器时间函数*/
    void timerEvent(QTimerEvent *e);

private slots:
    void timer_connect();

    void start_connect();
    void stop_connect();
private:
    Ui::FaceAttendence *ui;

    /* 摄像头*/
    VideoCapture cap;
    /* 级联分类器*/
    cv::CascadeClassifier cascade;
    /* 创建网络套接字*/
    QTcpSocket *msocket;
    QTimer mtimer;

};
#endif // FACEATTENDENCE_H
