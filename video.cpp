#include "video.h"
#include "ui_video.h"
#include<QActionGroup>
#include<QMenuBar>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<iostream>

video::video(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::video)
{

    ui->setupUi(this);
    _camera_view=new QCameraViewfinder();
        _record_button=new QPushButton("Record");
        _stop_record_button=new QPushButton("Stop Recording");
        _central_widget=new QWidget();
        setCentralWidget(_central_widget);
        //_setup_ui();
        //_setup_camera_devices();
        set_camera(QCameraInfo::defaultCamera());
        connect(_record_button,&QPushButton::clicked,this,& video::record);
        connect(_stop_record_button,&QPushButton::clicked,this,& video::stop_record);
        connect(_media_recorder.data(),&QMediaRecorder::stateChanged,this,& video::update_recorder_state);
    if(_camera.data()->isCaptureModeSupported(QCamera::CaptureVideo))
    {
      _camera.data()->setCaptureMode(QCamera::CaptureVideo);
    }else{
      qFatal("capture video not supported by this camera !");
    }
}

video::~video()
{
    delete ui;
}
void video::set_camera(const QCameraInfo &camera_info)
{
    _camera.reset(new QCamera(camera_info));
    _media_recorder.reset(new QMediaRecorder(_camera.data()));
    _camera.data()->setViewfinder(_camera_view);
    _camera.data()->start();

}
void video::record()
{
  _media_recorder.data()->record();
}
void  video::stop_record()
{
    _media_recorder.data()->stop();
}
void  video::update_recorder_state(QMediaRecorder::State media_state )
{
switch(media_state)
{case QMediaRecorder::RecordingState:
    _record_button->setEnabled(false);
    _stop_record_button->setEnabled(true);
            break;
case QMediaRecorder::StoppedState:
    _record_button->setEnabled(true);
    _stop_record_button->setEnabled(false);
    break;
}}
