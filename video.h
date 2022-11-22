#ifndef VIDEO_H
#define VIDEO_H

#include <QMainWindow>
#include <QMdiArea>
#include <QMainWindow>
#include <QMediaRecorder>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QPushButton>

namespace Ui {
class video;
}

class video : public QMainWindow
{
    Q_OBJECT

public:
    explicit video(QWidget *parent = nullptr);
    ~video();
    void record();
        void stop_record();
private:
    Ui::video *ui;
    //void setCentralWidget( QWidget *_central_widget);
    void set_camera(const QCameraInfo &camera_info);
        void set_camera_action(QAction *camera_action);
        void _setup_camera_devices();
        void _setup_ui();
        void update_recorder_state(QMediaRecorder::State media_state);
        //void update_recorder_state(QMediaRecorder::State media_state );
        QScopedPointer<QCamera>_camera;
        QScopedPointer<QMediaRecorder>_media_recorder;
        QCameraViewfinder*_camera_view;
        QWidget *_central_widget;
        QPushButton *_record_button;
        QPushButton *_stop_record_button;


};

#endif // VIDEO_H
