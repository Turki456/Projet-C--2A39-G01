#include "video.h"
#include "ui_video.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QTextStream"
#include "QSlider"
#include "QList"
#include<iostream>
#include "QDebug"


#include "QDebug"
using std::to_string;
using std::string;
video::video(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::video)
{
  ui->setupUi(this);
    // create new objects
       mediaPlayer = new QMediaPlayer(this);
       videoWidget = new QVideoWidget(this);
       layout = new QGridLayout(this);

       // add videoWidget to the layout and set it in the UI
       layout->addWidget(videoWidget);
       ui->videoPlayerBox->setLayout(layout);
       mediaPlayer->setVideoOutput(videoWidget);

       // open settings dialog
       connect(ui->settingsBtn, &QToolButton::clicked, this, &video::settingBtn);
       connect(ui->actionEdit, &QAction::triggered, this, &video::settingBtn);

       // connect the media player and slider:
       // NOTE: need to drag the slider to position instead of clicking
       connect(mediaPlayer, &QMediaPlayer::durationChanged, ui->videoSlider, &QSlider::setMaximum);
       connect(mediaPlayer, &QMediaPlayer::positionChanged, ui->videoSlider, &QSlider::setValue);
       connect(ui->videoSlider, &QSlider::sliderMoved, mediaPlayer, &QMediaPlayer::setPosition);

       // connect the menu signals with slots
       connect(ui->actionStop, SIGNAL(triggered()), mediaPlayer, SLOT(stop()));

       // clear and hide playlist
       ui->playListView->clear();
       ui->playlistBox->hide();

       // set the initial volumet to 50
       this->on_soundSlider_valueChanged(50);
}

video::~video()
{
    delete ui;
}
void video::setTimeLabel()
{
    // convert duration into HH:MM:SS format and set the lable
    string timeLbl;
    long milli = mediaPlayer->duration();
    long hr = milli / 3600000;
    milli = milli - 3600000 * hr;
    long min = milli / 60000;
    milli = milli - 60000 * min;
    long sec = milli / 1000;

    if (hr > 9) {
        timeLbl = to_string(hr) + ":";
    } else {
        timeLbl = "0" + to_string(hr) + ":";
    }
    if(min > 9){
        timeLbl += to_string(min) + ":";
    }else{
        timeLbl += "0" + to_string(min) + ":";
    }
    if(sec > 9){
        timeLbl += to_string(sec);
    }else{
        timeLbl += "0" + to_string(sec);
    }

    ui->timeLabel->setText(QString::fromStdString(timeLbl));

}
void video::on_actionOpen_triggered()
{
    // open the media file and get the pathname
    QString name = QFileDialog::getOpenFileName(this, "Open Media", QDir::homePath(), "*.mpg;*.mp4");

        // if the above format doesn't work the below must work on both linux and mac
//    QString name = QFileDialog::getOpenFileName(this, "Open Media", QDir::homePath(), "Video File (*.*)");

    // get the file name from the file information
    QFile f(name);
    QFileInfo fileInfo(f.fileName());
    QString fileName = fileInfo.fileName();

    // set the window to file name
    setWindowTitle(fileName);
    ui->statusbar->showMessage("Playing " + fileName);

    // set the time label
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, [&]() {
        setTimeLabel();
    });

    // add the path of the media file to the QMediaPlayer and play
    on_stopBtn_clicked();
    mediaPlayer->setMedia(QUrl::fromLocalFile(name));
    playVideo();
}

void video::on_actionPlaylist_triggered()
{
    playlist = new QMediaPlaylist;

    ui->playListView->clear();

    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Select multiple media files", QDir::homePath(), "*.mpg;*.mp4");

    // if the above format doesn't work the below must work on linux and mac
//    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Select multiple media files", QDir::homePath(), "Video File (*.*)");

    for (auto& file: fileNames) {
        QFile f(file);
        QFileInfo fileInfo(f.fileName());
        QString fileName = fileInfo.fileName();

        // set the time label
        connect(mediaPlayer, &QMediaPlayer::durationChanged, this, [&]() {
            setTimeLabel();
        });

        playlist->addMedia(QUrl::fromLocalFile(file));
        playlist->setCurrentIndex(1);

        ui->playListView->addItem(fileName);
    }

    mediaPlayer->setPlaylist(playlist);
    playVideo();

}

void video::playVideo()
{
    // play the media file and change the icon
    mediaPlayer->play();
    ui->playPauseBtn->setIcon(QIcon(":/images/images/pause.png"));
}

void video::pauseVideo()
{
    // pause the media file and change the icon
    mediaPlayer->pause();
    ui->playPauseBtn->setIcon(QIcon(":/images/images/play.png"));
}

void video::on_playPauseBtn_clicked()
{
    // get the current state of the media player
    QMediaPlayer::State stt = mediaPlayer->state();

    // if the state is pause the play and the button is clicked then play. If not in paused state pause the video.
    if (stt == mediaPlayer->PausedState) {
        playVideo();
    } else {
        pauseVideo();
    }
}

void video::on_stopBtn_clicked()
{
    mediaPlayer->stop();
}

void video::on_soundSlider_valueChanged(int value)
{
    // set the volume of the media player. If the volume is 0 icon changes to mute and change the slide position and vice versa.
    mediaPlayer->setVolume(value);

    if(value == 0) {
        ui->soundBtn->setIcon(QIcon(":/images/images/mute.png"));
    } else {
        ui->soundBtn->setIcon(QIcon(":/images/images/sound.png"));
    }

    ui->soundSlider->setSliderPosition(value);
}

void video::on_soundBtn_clicked()
{
    // change the slider position and the volume if the sound button is clicked
    if (ui->soundSlider->value() == 0) {
        mediaPlayer->setVolume(20);
        ui->soundSlider->setSliderPosition(20);
    } else {
        mediaPlayer->setVolume(0);
        ui->soundSlider->setSliderPosition(0);
    }
}

void video::on_speedBtn_clicked()
{
    speed = ui->speedLbl->text().toDouble();
    qreal playbackRate = 0;

    if (speed == 1.0) {
        playbackRate = 1.5;
    } else if (speed == 1.5) {
        playbackRate = 2.0;
    } else if (speed == 2.0) {
        playbackRate = 0.2;
    } else if (speed == 0.2) {
        playbackRate = 0.5;
    } else {
        playbackRate = 1.0;
    }

    ui->speedLbl->setText(QString::number(playbackRate));
    mediaPlayer->setPlaybackRate(playbackRate);
}

// menu bar

void video::on_actionSound_triggered()
{
    on_soundBtn_clicked();
}

void video::on_actionPlayAndPause_triggered()
{
    on_playPauseBtn_clicked();
}

void video::on_actionSpeed_triggered()
{
    on_speedBtn_clicked();
}

void video::on_actionNew_triggered()
{
   // newWindow = new video;
    newWindow->show();
}

void video::on_actionAbout_Qt_triggered()
{
    // message box about qt
    QMessageBox::aboutQt(this, "About Qt");
}

void video::on_actionAbout_MediaPlayer_triggered()
{
    // mesage box about the QtMediaPlayer
    QMessageBox::about(this, "Qt Media Player", "This is a simple player made using Qt and C++. "
                                                "This application performs functions such as play, pause, stop, change video speed, "
                                                "sound changing. The media player supports mp4, mpg video formats");
}

void video::on_actionExit_triggered()
{
    // exit the app
    QApplication::exit(0);
}

// settings

void video::settingBtn() {
    settingsDialog = new QDialog();

    brightnessSlider = new QSlider(Qt::Horizontal);
    brightnessSlider->setRange(-100, 100);
    brightnessSlider->setValue(videoWidget->brightness());
    connect(brightnessSlider, &QSlider::sliderMoved, videoWidget, &QVideoWidget::setBrightness);
    connect(videoWidget, &QVideoWidget::brightnessChanged, brightnessSlider, &QSlider::setValue);

    QSlider *contrastSlider = new QSlider(Qt::Horizontal);
    contrastSlider->setRange(-100, 100);
    contrastSlider->setValue(videoWidget->contrast());
    connect(contrastSlider, &QSlider::sliderMoved, videoWidget, &QVideoWidget::setContrast);
    connect(videoWidget, &QVideoWidget::contrastChanged, contrastSlider, &QSlider::setValue);

    QSlider *hueSlider = new QSlider(Qt::Horizontal);
    hueSlider->setRange(-100, 100);
    hueSlider->setValue(videoWidget->hue());
    connect(hueSlider, &QSlider::sliderMoved, videoWidget, &QVideoWidget::setHue);
    connect(videoWidget, &QVideoWidget::hueChanged, hueSlider, &QSlider::setValue);

    QSlider *saturationSlider = new QSlider(Qt::Horizontal);
    saturationSlider->setRange(-100, 100);
    saturationSlider->setValue(videoWidget->saturation());
    connect(saturationSlider, &QSlider::sliderMoved, videoWidget, &QVideoWidget::setSaturation);
    connect(videoWidget, &QVideoWidget::saturationChanged, saturationSlider, &QSlider::setValue);

    settingsLayout = new QFormLayout();
    settingsLayout->addRow(tr("Brightness"), brightnessSlider);
    settingsLayout->addRow(tr("Contrast"), contrastSlider);
    settingsLayout->addRow(tr("Hue"), hueSlider);
    settingsLayout->addRow(tr("Saturaation"), saturationSlider);

    settingsDialog->setWindowTitle("Settings");
    settingsDialog->setLayout(settingsLayout);
    settingsDialog->show();

}

// playlist

void video::on_playlistBtn_clicked()
{
    if(ui->playlistBox->isHidden()) {
        ui->playlistBox->show();
    } else {
        ui->playlistBox->hide();
    }
}

void video::on_removeVideo_clicked()
{
    ui->playListView->setSelectionMode(QAbstractItemView::SingleSelection);
    QList<QListWidgetItem*> selectedItems = ui->playListView->selectedItems();

    // remove selected item from listview and playlist
    playlist->removeMedia(ui->playListView->row(selectedItems.last()));
    delete ui->playListView->takeItem(ui->playListView->row(selectedItems.last()));

}

void video::on_clearBtn_clicked()
{
    // clear all items from listview and playlist
    ui->playListView->clear();
    playlist->clear();
}

