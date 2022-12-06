#ifndef VIDEO_H
#define VIDEO_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMessageBox>
#include <QSlider>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QToolButton>
#include <QDialog>
#include <QMediaPlaylist>
#include <QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui {
class video;
}

class video : public QDialog
{
    Q_OBJECT

public:
    explicit video(QWidget *parent = nullptr);
    ~video();

private slots:
    void on_actionAbout_Qt_triggered();

    void on_actionAbout_MediaPlayer_triggered();

    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_stopBtn_clicked();

    void on_soundSlider_valueChanged(int value);

    void on_soundBtn_clicked();

    void on_actionSound_triggered();

    void on_playPauseBtn_clicked();

    void on_speedBtn_clicked();

    void on_actionPlayAndPause_triggered();

    void on_actionSpeed_triggered();

    void on_actionNew_triggered();

    void on_playlistBtn_clicked();

    void on_actionPlaylist_triggered();

    void on_removeVideo_clicked();

    void on_clearBtn_clicked();
private:
    Ui::video *ui;
    // main pointers
        QMediaPlayer *mediaPlayer;
        QVideoWidget *videoWidget;
        QMediaPlayer player;
        QGridLayout *layout;
        QMainWindow *newWindow;
        QMediaPlaylist *playlist;

        void setTimeLabel();
        void playVideo();
        void pauseVideo();
        double speed;

        QStringList bla;

        // edit settings
        QDialog *settingsDialog;
        QFormLayout *settingsLayout;
        QSlider *brightnessSlider;

        void settingBtn();
};

#endif // VIDEO_H
