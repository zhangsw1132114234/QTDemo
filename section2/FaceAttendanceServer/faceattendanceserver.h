#ifndef FACEATTENDANCESERVER_H
#define FACEATTENDANCESERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class FaceAttendanceServer; }
QT_END_NAMESPACE

class FaceAttendanceServer : public QMainWindow
{
    Q_OBJECT

public:
    FaceAttendanceServer(QWidget *parent = nullptr);
    ~FaceAttendanceServer();

private slots:
    void accept_client();
    void read_data();
private:
    Ui::FaceAttendanceServer *ui;

    /* TCP服务器*/
    QTcpServer mserver;
    QTcpSocket *msocket;
    quint64 bsize;

};
#endif // FACEATTENDANCESERVER_H
