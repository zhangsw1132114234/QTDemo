#include "faceattendanceserver.h"
#include "ui_faceattendanceserver.h"

FaceAttendanceServer::FaceAttendanceServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FaceAttendanceServer)
{
    ui->setupUi(this);

    /* 客户端连接槽函数*/
    connect(&mserver, &QTcpServer::newConnection, this, &FaceAttendanceServer::accept_client);
    mserver.listen(QHostAddress::Any, 8888);
    bsize = 0;
}

void FaceAttendanceServer::accept_client()
{
    msocket = mserver.nextPendingConnection();
    // 关联接收函数
    connect(msocket, &QTcpSocket::readyRead, this, &FaceAttendanceServer::read_data);
}

void FaceAttendanceServer::read_data()
{
    // 读取数据
    QDataStream stream(msocket);
    stream.setVersion(QDataStream::Qt_4_1);
    if (bsize == 0)
    {
        if (msocket->bytesAvailable() < (qint64)sizeof(bsize)) return;
        stream >> bsize;
    }

    if (msocket->bytesAvailable() < bsize) return;

    QByteArray data;
    stream >> data;
    bsize = 0;
    if (data.size() == 0) return;
    //显示图片
    QPixmap mmp;
    mmp.loadFromData(data, ".jpg");
    mmp = mmp.scaled(ui->videoLB->size());
    ui->videoLB->setPixmap(mmp);


}

FaceAttendanceServer::~FaceAttendanceServer()
{
    delete ui;
}

