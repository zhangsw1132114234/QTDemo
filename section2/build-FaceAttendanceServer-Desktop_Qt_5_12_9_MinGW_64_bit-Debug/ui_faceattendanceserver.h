/********************************************************************************
** Form generated from reading UI file 'faceattendanceserver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEATTENDANCESERVER_H
#define UI_FACEATTENDANCESERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceAttendanceServer
{
public:
    QWidget *centralwidget;
    QLabel *videoLB;

    void setupUi(QMainWindow *FaceAttendanceServer)
    {
        if (FaceAttendanceServer->objectName().isEmpty())
            FaceAttendanceServer->setObjectName(QString::fromUtf8("FaceAttendanceServer"));
        FaceAttendanceServer->resize(800, 600);
        centralwidget = new QWidget(FaceAttendanceServer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        videoLB = new QLabel(centralwidget);
        videoLB->setObjectName(QString::fromUtf8("videoLB"));
        videoLB->setGeometry(QRect(60, 90, 400, 400));
        videoLB->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        FaceAttendanceServer->setCentralWidget(centralwidget);

        retranslateUi(FaceAttendanceServer);

        QMetaObject::connectSlotsByName(FaceAttendanceServer);
    } // setupUi

    void retranslateUi(QMainWindow *FaceAttendanceServer)
    {
        FaceAttendanceServer->setWindowTitle(QApplication::translate("FaceAttendanceServer", "FaceAttendanceServer", nullptr));
        videoLB->setText(QApplication::translate("FaceAttendanceServer", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceAttendanceServer: public Ui_FaceAttendanceServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEATTENDANCESERVER_H
