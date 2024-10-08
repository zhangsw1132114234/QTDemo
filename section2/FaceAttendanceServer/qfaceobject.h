#ifndef QFACEOBJECT_H
#define QFACEOBJECT_H

#include <QObject>
#include <seeta/FaceEngine.h>
#include <opencv.hpp>

// 人脸注册，识别，存储
class QFaceObject : public QObject
{
    Q_OBJECT
public:
    explicit QFaceObject(QObject *parent = nullptr);
    ~QFaceObject();

public slots:


    int64_t face_register(cv::Mat faceImage);
    int face_query(cv::Mat faceImage);
signals:

private:
    seeta::FaceEngine *faceineptr;

};

#endif // QFACEOBJECT_H
