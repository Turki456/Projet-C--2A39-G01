#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"logement.h"
#include "arduino.h"
#include <QMainWindow>
//
#include"mission.h"
#include<QtSql>
#include<QPrinter>
#include<Partenaire.h>
#include "client.h"


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

     //void on_tab_Mission_activated(const QModelIndex &index);

     void on_pushButton_7_clicked();

     void on_pushButton_8_clicked();

     void on_execl_clicked();

     void on_calendarWidget_clicked(const QDate &date);

     void on_pushButton_3_clicked();

     void on_tableCALEN_activated(const QModelIndex &index);
     void afficherMissionArduino();


     void on_Gestion2_clicked();

     void on_todolistBUTTON_clicked();

     void on_pushButton_quitter_admin_crud_clicked();
//partenaire

     void on_Gestion3_clicked();

     void on_pushButton_partenaire_ajouter_clicked();

     void on_pushButton_partenaire_supprimer_clicked();


     void on_pushButton_partenaire_modifier_clicked();

     void on_pushButton_partenaire_pdf_clicked();

     void on_pushButton_partenaire_stats_clicked();

     void on_pushButton_partenaire_tri_clicked();

     void on_pushButton_partenaire_rechercher_clicked();

     void on_pushButton_partenaire_reset_clicked();

     //void on_pushButton_Arduino_clicked();
    // void afficherMissionArduino();





     void on_Gestion4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_9_clicked();

     void on_TRI_nom_clicked();

     void on_TRI_clicked();

     void on_pb_recherche_clicked();

     void on_pb_pdf_clicked();

     void on_pushButton_12_clicked();

     void on_pushButton_14_clicked();

     void on_pushButton_15_clicked();

     void on_Gestion6_clicked();

private:
    Ui::MainWindow *ui;
    logement Dtmp;
    Partenaire partenaire;
     // Ui::statistique_partenaire *st;
    QByteArray data; // variable contenant les données reçues
    QByteArray data1;
Mission m;
    Arduino A; // objet temporaire
    Client c;
};
#endif // MAINWINDOW_H
