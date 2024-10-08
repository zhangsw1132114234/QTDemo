#include "faceattendence.h"
#include "ui_faceattendence.h"
#include <QImage>
#include <QPainter>
#include <QDebug>
#include <ui_faceattendence.h>
FaceAttendence::FaceAttendence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FaceAttendence)
{
    ui->setupUi(this);
    /* 打开摄像头*/
    cap.open(0);    // /dev/video1
    /* 打开定时器*/
    startTimer(100);

    /* 导入级联分类器*/
    cascade.load("D:/Embedded/lib/opencv452/etc/haarcascades/haarcascade_frontalface_alt2.xml");
    //cascade.load("D:/Embedded/lib/opencv452/etc/haarcascades/haarcascade_frontalcatface_extended.xml");

    /* 定时器连接服务器*/
    connect(&mtimer, &QTimer::timeout, this, &FaceAttendence::timer_connect);
    mtimer.start(1000);

    /* 实现断线重新连接*/
    msocket = new QTcpSocket(this);
    connect(msocket, &QTcpSocket::disconnected, this, &FaceAttendence::start_connect);
    connect(msocket, &QTcpSocket::connected, this, &FaceAttendence::stop_connect);
}

FaceAttendence::~FaceAttendence()
{
    delete ui;
}

void FaceAttendence::stop_connect()
{
    mtimer.stop();
    qDebug()<<"连接成功";
}

void FaceAttendence::start_connect()
{
    mtimer.start(5000);
    qDebug()<<"断开连接";
}

void FaceAttendence::timer_connect()
{
    /* 连接服务器*/
    msocket->connectToHost("127.0.0.1", 8888);
    qDebug()<<"正在连接服务器"<<msocket->state();
}

void FaceAttendence::timerEvent(QTimerEvent *e)
{
    /* 采集数据*/
    Mat srcImage;
    if (cap.grab())
    {
        cap.read(srcImage);
    }
    /* 转换灰度图像*/
    Mat grayImage;
    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

    /* 检测人脸数据*/
    std::vector<Rect> faceRects;
    cascade.detectMultiScale(grayImage, faceRects);
    if (faceRects.size() > 0)
    {
        Rect rect = faceRects.at(0);
        rectangle(srcImage,rect,Scalar(0,0,255));
        //ui->headpicLb->move(rect.x, rect.y);
        // 打包发送数据
        {
            // 将Mat数据编码为jpg格式，然后转换为字节流发送
            std::vector<uchar> buf;
            cv::imencode(".jpg",srcImage,buf);
            QByteArray byte((const char*)buf.data(), buf.size());

            quint64 backsize = byte.size();
            QByteArray sendData;
            QDataStream stream(&sendData, QIODevice::WriteOnly);
            stream.setVersion(QDataStream::Qt_4_1);
            stream << backsize << byte;
            // 发送
            msocket->write(sendData);

        }

    }else
    {
        ui->headpicLb->move(100,60);
    }
    /* 转化格式*/
    if(srcImage.data == nullptr) return;
    cvtColor(srcImage, srcImage, COLOR_BGR2RGB);
    QImage image(srcImage.data, srcImage.cols, srcImage.rows, srcImage.step1(), QImage::Format_RGB888);
    /* 显示图像*/
    QPixmap mmp = QPixmap::fromImage(image);
    ui->videolb->setPixmap(mmp);
}
