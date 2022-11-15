#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"logement.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_Confirmer_clicked();
    void on_supprimer_clicked();
    void on_Modifier_clicked();
    void on_pushButton_2_clicked();
    void on_Annuler_clicked();
    void on_Chercher_clicked();
     void on_Refresh_clicked();
     void on_comboBox_activated(const QString &arg1);
     void on_stats_clicked();
      void on_PDF_clicked();
      void on_cb_id_QR_currentIndexChanged(const QString &arg1);
       void on_cb_id_supp_currentIndexChanged();


      void on_video_clicked();

private:
    Ui::MainWindow *ui;
    logement Dtmp;
    QByteArray data;
};
#endif // MAINWINDOW_H
