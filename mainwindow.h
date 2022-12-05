#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"logement.h"
#include "arduino.h"
#include <QMainWindow>
//
#include"mission.h"
#include<QtSql>
#include<QPrinter>


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
     void on_comboBox_2_activated(const QString &arg1);
     void on_stats_clicked();
      void on_PDF_clicked();
      void on_cb_id_QR_currentIndexChanged(const QString &arg1);
       void on_cb_id_supp_currentIndexChanged();



      void on_video_clicked();
     void update_label();
      //void on_upload_clicked();


     void on_Gestion1_clicked();

     //mission
     void on_pushButton_clicked();

     void on_SUPPRIMER_clicked();

     void on_MODIFIER_clicked();

     void on_CHERCHER_clicked();

     void on_pushButton_ANNULER_clicked();

     void on_pushButton_ANNULER2_clicked();

     void on_ANNULER3_clicked();


     void on_pushButton_10_clicked();

     void on_tab_Mission_activated(const QModelIndex &index);

     void on_pushButton_7_clicked();

     void on_pushButton_8_clicked();

     void on_execl_clicked();

     void on_calendarWidget_clicked(const QDate &date);

     void on_pushButton_3_clicked();

     void on_tableCALEN_activated(const QModelIndex &index);
     void afficherMissionArduino();


     void on_Gestion2_clicked();

private:
    Ui::MainWindow *ui;
    logement Dtmp;

    QByteArray data; // variable contenant les données reçues
    QByteArray data1;
Mission m;
    Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H
