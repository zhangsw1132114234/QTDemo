#include "qfaceobject.h"

QFaceObject::QFaceObject(QObject *parent) : QObject(parent)
{
    // 初始化
    seeta::ModelSetting FDMode("F:/lib/SeetaFace/bin/model/fd_2_00.dat", seeta::ModelSetting::CPU, 0);
    seeta::ModelSetting PDMode("F:/lib/SeetaFace/bin/model/pd_2_00_pts5.dat", seeta::ModelSetting::CPU, 0);
    seeta::ModelSetting FRMode("F:/lib/SeetaFace/bin/model/fr_2_10.dat", seeta::ModelSetting::CPU, 0);
    this->faceineptr = new seeta::FaceEngine(FDMode, PDMode, FRMode);

}

QFaceObject::~QFaceObject()
{
    delete faceineptr;
}

int64_t QFaceObject::face_register(cv::Mat faceImage)
{
    // 将 mat 数据转化为SeetaImageData
    SeetaImageData simage;
    simage.data = faceImage.data;
    simage.width = faceImage.rows;
    simage.height = faceImage.cols;
    simage.channels = faceImage.channels();

    int64_t faceid = this->faceineptr->Register(simage);

    return faceid;
}

int QFaceObject::face_query(cv::Mat faceImage)
{
    SeetaImageData simage;
    simage.data = faceImage.data;
    simage.width = faceImage.rows;
    simage.height = faceImage.cols;
    simage.channels = faceImage.channels();

    float similarty = 0;
    int faceid = this->faceineptr->Query(simage, &similarty);

    return faceid;
}
