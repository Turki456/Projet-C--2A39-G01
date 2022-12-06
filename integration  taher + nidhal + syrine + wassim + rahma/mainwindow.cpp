#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logement.h"
#include "dialoglogin.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QPdfWriter>
#include <QValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QPixmap>
#include "statistique.h"
#include "video.h"
#include <QGraphicsView>
#include "QZXing.h"
#include <QGraphicsScene>
#include <QTextDocument>
#include <QTimer>
#include <QString>
#include <QTextCodec>
//MISSION
#include"mission.h"
#include <QTextDocument>
#include<QDate>
#include<QDateEdit>
#include <iostream>
#include<QPrinter>
#include<QDialog>
#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include "exportexcel.h"
#include<QPrintDialog>
//employe
#include "todolist.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

     ui->setupUi(this);
      ui->tab_clients->setModel(c.afficher());
    ui->tableView->setModel(Dtmp.afficher());
    ui->cb_id_supp->setModel(Dtmp.getAllId());

             ui->cb_id_alarme->setModel(Dtmp.getAllId());
        ui->cb_id_modiff->setModel(Dtmp.getAllId());
        ui->cb_id_QR->setModel(Dtmp.getAllId());
    QRegExp reg("^([a-zA-Z.]+)$ ");
           QValidator *validator = new QRegExpValidator(reg, this);
           QRegExp reg1("^([a-zA-Z0-9_\-\.]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$ ");
           QRegExp reg2("^([a-zA-Z0-9_\-\.]+)\.([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$ ");
           QValidator *validator1 = new QRegExpValidator(reg1, this);
           QValidator *validator2 = new QRegExpValidator(reg2, this);
    ui->ID->setValidator(new QIntValidator(0, 99999999,this));;

    ui->adresse->setValidator(validator);
    ui->Mail->setValidator(validator1);
    ui->Prix->setValidator(new QIntValidator(0, 99999999,this));
    ui->Tel->setValidator(new QIntValidator(0, 99999999,this));




    ui->adresse_M->setValidator(validator);
    ui->mail_M->setValidator(validator1);
    ui->prix_M->setValidator(new QIntValidator(0, 99999999,this));
    ui->Tel_M->setValidator(new QIntValidator(0, 99999999,this));



    ui->le_chercher->setValidator(validator2);
    QTimer *t = new QTimer(this);
        t->setInterval(1000);
        connect(t, &QTimer::timeout, [&]() {
           QString time1 = QTime::currentTime().toString();
           ui->label_clock->setText(time1);
        } );
        t->start();
        //MISSION
        ui->lineEdit_ID->setValidator(new QIntValidator(0,9999999,this));
        ui->lineEdit_BUD->setValidator(new QIntValidator(0,9999999,this));
        ui->lineEdit_BUD_N->setValidator(new QIntValidator(0,9999999,this));
        ui->lineEdit_NBR->setValidator(new QIntValidator(0,999,this));
         ui->lineEdit_NBR_N->setValidator(new QIntValidator(0,999,this));
        ui->lineEdit_DES->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,255}"), this ));
      //  ui->lineEdit_TM->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,255}"), this ));
        ui->lineEdit_DES_N->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,255}"), this ));
        ui->lineEdit_N_ID->setValidator(new QIntValidator(0,9999999,this));
        //ui->lineEdit_ID1->setValidator(new QIntValidator(0,9999999,this));
        //ui->lineEdit_TY_N->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,255}"), this ));
        ui->tab_Mission->setModel(m.afficher());
        ui->comboBox_3->addItem("tri par id");
        ui->comboBox_3->addItem("tri par numP");
        ui->comboBox_3->addItem("tri par bud");
        ui->combotype->addItem("stage_vol");
        ui->combotype->addItem("formation");
        ui->combotype->addItem("stage_pro");
        ui->combomod->addItem("stage_vol");
        ui->combomod->addItem("formation");
        ui->combomod->addItem("stage_pro");
        ui->comboBox_cher->addItem("par TYPE");
        ui->comboBox_cher->addItem("par NB_per");
        ui->comboBox_cher->addItem("par ID");

        //partenaire

        ui->tableView_partenaire->setModel(partenaire.afficher());
        ui->lineEdit_ID_ajouter_partenaire->setValidator(new QIntValidator(0,20,this));
        ui->lineEdit_ID_modifier_partenaire->setValidator(new QIntValidator(0,20,this));
        ui->lineEdit_ID_supprimer_partenaire->setValidator(new QIntValidator(0,20,this));
        ui->lineEdit_NumTel_ajouter_partenaire->setValidator(new QIntValidator(0,99999999,this));
        ui->lineEdit_NumTel_modifier_partenaire->setValidator(new QIntValidator(0,99999999,this));
        ui->lineEdit_Dureecontrat_ajouter_partenaire->setValidator(new QIntValidator(0,10,this));
        ui->lineEdit_Dureecontrat_modifier_partenaire->setValidator(new QIntValidator(0,10,this));
        ui->lineEdit_Remise_ajouter_partenaire->setValidator(new QIntValidator(0,99,this));
        ui->lineEdit_Remise_modifier_partenaire->setValidator(new QIntValidator(0,99,this));

        ui->comboBox_tri_partenaire->addItem("Tri par ordre croissant");
        ui->comboBox_tri_partenaire->addItem("Tri par ordre decroissant");
        ui->comboBox_tri_partenaire->addItem("Tri par ordre Remise");
        ui->comboBox_type_partenaire->addItem("Hotel");
        ui->comboBox_type_partenaire->addItem("Airline");
        ui->comboBox_type_partenaire->addItem("Location");
        ui->comboBox_type2_partenaire->addItem("Hotel");
        ui->comboBox_type2_partenaire->addItem("Airline");
        ui->comboBox_type2_partenaire->addItem("Location");

        ui->comboBox_recherche_partenaire->addItem("ID");
        ui->comboBox_recherche_partenaire->addItem("Type");
        ui->comboBox_recherche_partenaire->addItem("Nom");



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Confirmer_clicked()
{
    int id=ui->ID->text().toInt();
     QString type=ui->comboBox_A->currentText();
    QString adresse=ui->adresse->text();
    QString email=ui->Mail->text();
    int prix=ui->Prix->text().toInt();
    int tel=ui->Tel->text().toInt();
    QString alerte="";
    logement Dtmp(id,type,prix,adresse,email,tel,alerte);
     bool valid=true;
   if((Dtmp.Verif_id()==true) or (Dtmp.Verif_ads()==true) or (Dtmp.Verif_prix()==true) or  (Dtmp.Verif_email()==true) or (Dtmp.controlTel(tel)==true))
   {
       if(Dtmp.Verif_id())
                     { ui->verifier1->clear();
             ui->verifier1->setText(QString("Le id doit etre non vide"));


    }
       if(Dtmp.Verif_ads())
                     { ui->verifier3->clear();
           ui->verifier3->setText(QString("L'adresse doit etre non vide"));



      }
       if(Dtmp.Verif_prix())
                     { ui->verifier6->clear();
            ui->verifier6->setText(QString("Le prix doit etre non vide"));



     }

       if(Dtmp.Verif_email())
                     { ui->verifier5->clear();
           ui->verifier5->setText(QString("Email doit être valide : @exemple.ex"));


      }
       if (Dtmp.controlTel(tel))
       {
           ui->verifier4_2->clear();
           ui->verifier4_2->setText(QString("Le nombre des chiffres du tel doit etre egale a 8"));

       }
      valid=false;
       }




    if (valid){
        bool test=Dtmp.ajouter();
       QMessageBox::information(nullptr, QObject::tr("Succès"),
    QObject::tr("Ajout effectué.\n"
      "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
      }
       else
          QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                                QObject::tr("Ajouter non effectué !\n"
                                  "Cliquer sur Cancel to exit."), QMessageBox::Cancel);

    ui->ID->clear();
   ui->adresse->clear();
  ui->Mail->clear();
   ui->Prix->clear();
    ui->Tel->clear();
    ui->verifier1->clear();
   ui->verifier3->clear();
   ui->verifier4_2->clear();
   ui->verifier5->clear();
    ui->verifier6->clear();
    ui->tableView->setModel(Dtmp.afficher());
    ui->cb_id_supp->setModel(Dtmp.getAllId());
    ui->cb_id_modiff->setModel(Dtmp.getAllId());
    ui->cb_id_QR->setModel(Dtmp.getAllId());
    ui->cb_id_alarme->setModel(Dtmp.getAllId());


}
void MainWindow::on_Modifier_clicked()
{
    //QString  recherche=ui->ID__M->text();
    //int id=ui->ID__M->text().toInt();
   QString  recherche=ui->cb_id_modiff->currentText();
     int id=ui->cb_id_modiff->currentText().toInt();
    QString type=ui->comboBox_M->currentText();
    QString adresse=ui->adresse_M->text();
    QString email=ui->mail_M->text();
    int prix=ui->prix_M->text().toInt();
    int tel=ui->Tel_M->text().toInt();
    QString alerte="";
    logement Dtmp(id,type,prix,adresse,email,tel,alerte);
    bool valid=true;
  if((Dtmp.Verif_ads()==true) or (Dtmp.Verif_prix()==true)  or (Dtmp.Verif_email()==true) or (Dtmp.controlTel(tel)==true))
  {


      if(Dtmp.Verif_ads())
                    { ui->verifier9->clear();
          ui->verifier9->setText(QString("L'adresse doit etre non vide"));



     }
      if(Dtmp.Verif_prix())
                    { ui->verifier12->clear();
           ui->verifier12->setText(QString("Le prix doit etre non vide"));



    }
      if(Dtmp.controlTel(tel))
                    { ui->verifier10->clear();
          ui->verifier10->setText(QString("Le nombre des chiffres du tel doit etre egale a 8"));


     }
      if(Dtmp.Verif_email())
                    { ui->verifier11->clear();
          ui->verifier11->setText(QString("Email doit être valide : @exemple.ex"));


     }
     valid=false;
      }





        if (Dtmp.rechercherID(recherche)->rowCount()!=0 and recherche.length()!=0 and valid)
        {
       bool test = Dtmp.modifier(id);

            QMessageBox::information(nullptr, QObject::tr("Succès"),
         QObject::tr("Modifier effectué.\n"
           "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
           }

       else
          {QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                                QObject::tr("Modifier non effectué !\n"
                                  "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}


   ui->adresse_M->clear();
  ui->mail_M->clear();
   ui->prix_M->clear();
    ui->Tel_M->clear();
   ui->verifier9->clear();
  ui->verifier10->clear();
   ui->verifier11->clear();
    ui->verifier12->clear();
    ui->tableView->setModel(Dtmp.afficher());
    ui->cb_id_supp->setModel(Dtmp.getAllId());
    ui->cb_id_modiff->setModel(Dtmp.getAllId());
     ui->cb_id_QR->setModel(Dtmp.getAllId());
     ui->cb_id_alarme->setModel(Dtmp.getAllId());


}
/*
void MainWindow::on_pb_modifier_clicked()
{
    int NUMAFF=ui->mod_NUMAFF->text().toInt();
    QString TYPEAFF=ui->mod_TYPEAFF->text();
    QString DATEAFF=ui->mod_DATEAFF->text();

    Aff_juridique AFF(NUMAFF,TYPEAFF,DATEAFF);

    bool test=AFF.modifier(NUMAFF);
        if(test)
        {
            //refrech
            ui->tab_affaire->setModel(AFF.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    }else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);
}
*/
void MainWindow::on_supprimer_clicked()
{   //int id=ui->le_id_Supp->text().toInt();
    int id=ui->cb_id_supp->currentText().toInt();
    QString recherche=ui->cb_id_supp->currentText();

    if (Dtmp.rechercherID(recherche)->rowCount()!=0 and recherche.length()!=0)
    {
        bool test=Dtmp.supprimer(id);
       QMessageBox::information(nullptr, QObject::tr("Succès"),
    QObject::tr("Suppression effectué.\n"
      "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
      }
      else
          {QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                                QObject::tr("Suppression non effectué !\n"
                                  "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}

    ui->tableView->setModel(Dtmp.afficher());
    ui->cb_id_supp->setModel(Dtmp.getAllId());
    ui->cb_id_modiff->setModel(Dtmp.getAllId());
     ui->cb_id_QR->setModel(Dtmp.getAllId());
     ui->cb_id_alarme->setModel(Dtmp.getAllId());

}
void MainWindow::on_pushButton_2_clicked()
{
    ui->ID->clear();
   ui->adresse->clear();
  ui->Mail->clear();
   ui->Prix->clear();
    ui->Tel->clear();
}
void MainWindow::on_Annuler_clicked()
{
     ui->adresse_M->clear();
     ui->mail_M->clear();
      ui->prix_M->clear();
       ui->Tel_M->clear();
}
void MainWindow::on_Chercher_clicked()
{
    QString recherche = ui->le_chercher->text();
    if(recherche.length()!=0){

        if(ui->comboBox_recherche->currentText()=="ID")
          ui->tableView->setModel(Dtmp.rechercherID(recherche));
        else if(ui->comboBox_recherche->currentText()=="Type")
            ui->tableView->setModel(Dtmp.rechercherType(recherche));

        else if (ui->comboBox_recherche->currentText()=="Adresse")
            ui->tableView->setModel(Dtmp.rechercheAdresse(recherche));
    }

    else
    {
       ui->tableView->setModel(Dtmp.afficher());
    }
}
void MainWindow::on_Refresh_clicked()
{   ui->le_chercher->clear();
    ui->tableView->setModel(Dtmp.afficher());

}
void MainWindow::on_comboBox_activated(const QString &arg1)
{     if(ui->comboBox_2->currentText()=="Tous Les Logements")
       {      if(ui->comboBox->currentText()=="selon ID par ordre croissant")
            ui->tableView->setModel(Dtmp.Trier_ID_A());
        else if (ui->comboBox->currentText()=="selon ID par ordre decroissant")
            ui->tableView->setModel(Dtmp.Trier_ID_D());
        else if (ui->comboBox->currentText()=="selon Prix  par ordre croissant")
            ui->tableView->setModel(Dtmp.Trier_PRIX_A());
        else if (ui->comboBox->currentText()=="selon Prix  par ordre decroissant")
            ui->tableView->setModel(Dtmp.Trier_PRIX_D());
        else if (ui->comboBox->currentText()=="selon Adresse  par ordre croissant")
            ui->tableView->setModel(Dtmp.Trier_adresse_A());
        else if (ui->comboBox->currentText()=="selon Adresse  par ordre decroissant")
            ui->tableView->setModel(Dtmp.Trier_adresse_D());
    }
    else if(ui->comboBox_2->currentText()=="Tous Les Hotels")
           {      if(ui->comboBox->currentText()=="selon ID par ordre croissant")
                ui->tableView->setModel(Dtmp.Trier_Hotel_ID_A());
            else if (ui->comboBox->currentText()=="selon ID par ordre decroissant")
                ui->tableView->setModel(Dtmp.Trier_Hotel_ID_D());
            else if (ui->comboBox->currentText()=="selon Prix  par ordre croissant")
                ui->tableView->setModel(Dtmp.Trier_Hotel_PRIX_A());
            else if (ui->comboBox->currentText()=="selon Prix  par ordre decroissant")
                ui->tableView->setModel(Dtmp.Trier_Hotel_PRIX_D());
            else if (ui->comboBox->currentText()=="selon Adresse  par ordre croissant")
                ui->tableView->setModel(Dtmp.Trier_Hotel_adresse_A());
            else if (ui->comboBox->currentText()=="selon Adresse  par ordre decroissant")
                ui->tableView->setModel(Dtmp.Trier_Hotel_adresse_D());
        }
    else if(ui->comboBox_2->currentText()=="Tous Les Maisons")
           {      if(ui->comboBox->currentText()=="selon ID par ordre croissant")
                ui->tableView->setModel(Dtmp.Trier_Maison_ID_A());
            else if (ui->comboBox->currentText()=="selon ID par ordre decroissant")
                ui->tableView->setModel(Dtmp.Trier_Maison_ID_D());
            else if (ui->comboBox->currentText()=="selon Prix  par ordre croissant")
                ui->tableView->setModel(Dtmp.Trier_Maison_PRIX_A());
            else if (ui->comboBox->currentText()=="selon Prix  par ordre decroissant")
                ui->tableView->setModel(Dtmp.Trier_Maison_PRIX_D());
            else if (ui->comboBox->currentText()=="selon Adresse  par ordre croissant")
                ui->tableView->setModel(Dtmp.Trier_Maison_adresse_A());
            else if (ui->comboBox->currentText()=="selon Adresse  par ordre decroissant")
                ui->tableView->setModel(Dtmp.Trier_Maison_adresse_D());
        }
    else if(ui->comboBox_2->currentText()=="Tous Les Appartements")
           {      if(ui->comboBox->currentText()=="selon ID par ordre croissant")
                ui->tableView->setModel(Dtmp.Trier_Appartement_ID_A());
            else if (ui->comboBox->currentText()=="selon ID par ordre decroissant")
                ui->tableView->setModel(Dtmp.Trier_Appartement_ID_D());
            else if (ui->comboBox->currentText()=="selon Prix  par ordre croissant")
                ui->tableView->setModel(Dtmp.Trier_Appartement_PRIX_A());
            else if (ui->comboBox->currentText()=="selon Prix  par ordre decroissant")
                ui->tableView->setModel(Dtmp.Trier_Appartement_PRIX_D());
            else if (ui->comboBox->currentText()=="selon Adresse  par ordre croissant")
                ui->tableView->setModel(Dtmp.Trier_Appartement_adresse_A());
            else if (ui->comboBox->currentText()=="selon Adresse  par ordre decroissant")
                ui->tableView->setModel(Dtmp.Trier_Appartement_adresse_D());
        }


}
 void MainWindow::on_comboBox_2_activated(const QString &arg1)
 {
     if(ui->comboBox_2->currentText()=="Tous Les Logements")
            {      if(ui->comboBox->currentText()=="selon ID par ordre croissant")
                 ui->tableView->setModel(Dtmp.Trier_ID_A());
             else if (ui->comboBox->currentText()=="selon ID par ordre decroissant")
                 ui->tableView->setModel(Dtmp.Trier_ID_D());
             else if (ui->comboBox->currentText()=="selon Prix  par ordre croissant")
                 ui->tableView->setModel(Dtmp.Trier_PRIX_A());
             else if (ui->comboBox->currentText()=="selon Prix  par ordre decroissant")
                 ui->tableView->setModel(Dtmp.Trier_PRIX_D());
             else if (ui->comboBox->currentText()=="selon Adresse  par ordre croissant")
                 ui->tableView->setModel(Dtmp.Trier_adresse_A());
             else if (ui->comboBox->currentText()=="selon Adresse  par ordre decroissant")
                 ui->tableView->setModel(Dtmp.Trier_adresse_D());
         }
         else if(ui->comboBox_2->currentText()=="Tous Les Hotels")
                {      if(ui->comboBox->currentText()=="selon ID par ordre croissant")
                     ui->tableView->setModel(Dtmp.Trier_Hotel_ID_A());
                 else if (ui->comboBox->currentText()=="selon ID par ordre decroissant")
                     ui->tableView->setModel(Dtmp.Trier_Hotel_ID_D());
                 else if (ui->comboBox->currentText()=="selon Prix  par ordre croissant")
                     ui->tableView->setModel(Dtmp.Trier_Hotel_PRIX_A());
                 else if (ui->comboBox->currentText()=="selon Prix  par ordre decroissant")
                     ui->tableView->setModel(Dtmp.Trier_Hotel_PRIX_D());
                 else if (ui->comboBox->currentText()=="selon Adresse  par ordre croissant")
                     ui->tableView->setModel(Dtmp.Trier_Hotel_adresse_A());
                 else if (ui->comboBox->currentText()=="selon Adresse  par ordre decroissant")
                     ui->tableView->setModel(Dtmp.Trier_Hotel_adresse_D());
             }
         else if(ui->comboBox_2->currentText()=="Tous Les Maisons")
                {      if(ui->comboBox->currentText()=="selon ID par ordre croissant")
                     ui->tableView->setModel(Dtmp.Trier_Maison_ID_A());
                 else if (ui->comboBox->currentText()=="selon ID par ordre decroissant")
                     ui->tableView->setModel(Dtmp.Trier_Maison_ID_D());
                 else if (ui->comboBox->currentText()=="selon Prix  par ordre croissant")
                     ui->tableView->setModel(Dtmp.Trier_Maison_PRIX_A());
                 else if (ui->comboBox->currentText()=="selon Prix  par ordre decroissant")
                     ui->tableView->setModel(Dtmp.Trier_Maison_PRIX_D());
                 else if (ui->comboBox->currentText()=="selon Adresse  par ordre croissant")
                     ui->tableView->setModel(Dtmp.Trier_Maison_adresse_A());
                 else if (ui->comboBox->currentText()=="selon Adresse  par ordre decroissant")
                     ui->tableView->setModel(Dtmp.Trier_Maison_adresse_D());
             }
         else if(ui->comboBox_2->currentText()=="Tous Les Appartements")
                {      if(ui->comboBox->currentText()=="selon ID par ordre croissant")
                     ui->tableView->setModel(Dtmp.Trier_Appartement_ID_A());
                 else if (ui->comboBox->currentText()=="selon ID par ordre decroissant")
                     ui->tableView->setModel(Dtmp.Trier_Appartement_ID_D());
                 else if (ui->comboBox->currentText()=="selon Prix  par ordre croissant")
                     ui->tableView->setModel(Dtmp.Trier_Appartement_PRIX_A());
                 else if (ui->comboBox->currentText()=="selon Prix  par ordre decroissant")
                     ui->tableView->setModel(Dtmp.Trier_Appartement_PRIX_D());
                 else if (ui->comboBox->currentText()=="selon Adresse  par ordre croissant")
                     ui->tableView->setModel(Dtmp.Trier_Appartement_adresse_A());
                 else if (ui->comboBox->currentText()=="selon Adresse  par ordre decroissant")
                     ui->tableView->setModel(Dtmp.Trier_Appartement_adresse_D());
             }






 }

void MainWindow::on_stats_clicked()
{
    statistique s;

     s.exec();


}
void MainWindow::on_PDF_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                       const int rowCount = ui->tableView->model()->rowCount();
                       const int columnCount = ui->tableView->model()->columnCount();
                       QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                       out <<"<html>\n"
                             "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           << "<title> LISTE DES PRODUITS<title>\n "
                           << "</head>\n"
                           "<body bgcolor=#ffffff link=#5000A0>\n"
                           "<h1 style=\"text-align: center;\"><strong> **LISTE DES LOGEMENTS ** "+TT+"</strong></h1>"
                           "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                             "</br> </br>";
                       // headers
                       out << "<thead><tr bgcolor=#d6e5ff>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->tableView->isColumnHidden(column))
                               out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";

                       // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView->isColumnHidden(column)) {
                                   QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";

                       QTextDocument *document = new QTextDocument();
                       document->setHtml(strStream);

                       QPrinter printer;

                       QPrintDialog *test = new QPrintDialog(&printer, NULL);
                       if (test->exec() == QDialog::Accepted) {
                           document->print(&printer);
                       }

                       delete document;
}
void MainWindow::on_cb_id_QR_currentIndexChanged(const QString &arg1)
{     ui->label_8->clear();
      ui->label_10->clear();
      ui->label_24->clear();
      ui->label_25->clear();
      ui->label_26->clear();




     QString recherche=ui->cb_id_QR->currentText();
     QSqlQuery qr;
 qr.prepare("SELECT * FROM LOGEMENT where ID_L LIKE '"+recherche+"'");

//QString id,nb,type,poids,dimension;
QString id,type,prix,adresse,email,tel;

           if(qr.exec())  {
         while (qr.next()) {
         id = qr.value(0).toString();
             type = qr.value(1).toString();
             prix = qr.value(2).toString();
              adresse= qr.value(3).toString();
               email= qr.value(4).toString();
               tel= qr.value(5).toString();

         }

     }


 QString data="Les information : ID de Logement : "+id+", type du logement : "+type+" , prix du logement : "+prix+" , adresse du logement : "+adresse+",mail du logement: "+email+", tel du logement :"+ tel;
QImage barcode = QZXing::encodeData(data);
           QGraphicsScene *graphic = new QGraphicsScene(this);
           graphic->addPixmap( QPixmap::fromImage(barcode));
           ui->graphicsView->setScene(graphic);


             ui->label_8->setText(QString(type));
             ui->label_10->setText(QString(adresse));
             ui->label_24->setText(QString(tel));
             ui->label_25->setText(QString(email));
             ui->label_26->setText(QString(prix));

}


void MainWindow::on_video_clicked()
{
    video w;
    w.exec();
}
void MainWindow::on_cb_id_supp_currentIndexChanged()
{

    QString recherche=ui->cb_id_supp->currentText();
    QSqlQuery query;
    query.prepare("SELECT * FROM LOGEMENT where ID_L LIKE '"+recherche+"'");
    QString id,type,prix,adresse,email,tel;
    if(query.exec())
    {
        while(query.next())
        {
            id = query.value(0).toString();
                type = query.value(1).toString();
                prix = query.value(2).toString();
                 adresse= query.value(3).toString();
                  email= query.value(4).toString();
                  tel= query.value(5).toString();
        }
    }
    ui->label_s_1->setText(QString(type));
    ui->label_s_2->setText(QString(adresse));
    ui->label_s_3->setText(QString(tel));
    ui->label_s_4->setText(QString(email));
    ui->label_s_5->setText(QString(prix));

}
/*
void MainWindow::update_label()
{

    data1=A.read_from_arduino1();
    int t=0;
    if (data1=="1")
     {int x = ui->tableView->model()->rowCount();
    A.write_to_arduino("x");
    ui->label_34->setText("il y a un feu");

      data1=A.read_from_arduino1();
      if (data1=="999")
      {   ui->label_35->setText(" En Cours d envoyer les donnés");
          while (data1!="x"){
              data1=A.read_from_arduino1();
 QString d =ui->tableView->model()->data(ui->tableView->model()->index(t,5)).toString().simplified();
              t++;
              data="d";
              A.write_to_arduino(data);}
          ui->label_35->setText(" Tous les donneés ont été envoyé");}}
    else
    {   ui->label_34->setText("il n y a pas de feu");
        ui->label_35->clear();

    }




}
*/
/*
void MainWindow::update_label()
{
    QString ido;
           string conv;   QByteArray data2;
           const char *data; QByteArray q_b;
ui->tableView->setModel(Dtmp.MAIL_L());

QVariant value =ui->tableView->model()->data(ui->tableView->model()->index(0,0)).toString().simplified();
QString mail = value.toString();
ui->label_34->setText(mail);

    data1=A.read_from_arduino();
    //int t=0;
    if (data1=="1")
     {int x = ui->tableView->model()->rowCount();

         data2.setNum(x);
    A.write_to_arduino(data2);
    ui->label_34->setText("il y a un feu");

      if (data1=="999")
      {   ui->label_35->setText("En Cours d envoyer les donnés");
           int t=0;
           q_b.setNum(t);
          while (data1!=data2){
              data1=A.read_from_arduino();
QVariant value =ui->tableView->model()->data(ui->tableView->model()->index(t,0)).toString().simplified();
t++;
//q_b.setNum(t);
              ido=value.toString();

                      conv = ido.toStdString();
                        ui->label_34->setText(ido);
                      data=conv.c_str();
                  A.write_to_arduino(data);
             }
          ui->label_35->setText("Tous les donneés ont été envoyé");}}
    else
    {   ui->label_34->setText("il n y a pas de feu");
        ui->label_35->clear();

    }




}
*/


/*
void MainWindow::on_upload_clicked()
{
    QString  recherche=ui->cb_id_alarme->currentText();
    qDebug() << "this is the TEXT we want to send";
     qDebug() << recherche;
     qDebug() << "this is the text as data";
      QByteArray text=recherche.toUtf8();

      A.write_to_arduino(text);
      qDebug() << text;
}*/

void MainWindow::update_label()
{
    data=A.read_from_arduino();
     //QString text = QTextCodec::codecForMib(106)->toUnicode(data);
      QString  text=ui->cb_id_alarme->currentText();
    if (data=="0"){
        ui->alarme1->clear();
        ui->alarme2->clear();
        ui->alarme3->clear();
        ui->alarme4->clear();
        ui->alarme5->clear();
        ui->alarme6->clear();
        ui->alarme7->clear();
        ui->label_34->clear();
        ui->label_34->setText("il n y a pas un feu");

     }
     else
     {    //qDebug() << "this is the received data";
         //qDebug() << data;
         //qDebug() << "this is the  data transformed into a text";
         //qDebug() << text;
        ui->alarme1->clear();
        ui->alarme2->clear();
        ui->alarme3->clear();
        ui->alarme4->clear();
        ui->alarme5->clear();
        ui->alarme6->clear();
        ui->alarme7->clear();
        ui->label_34->clear();
        ui->label_34->setText("il ya un feu dans le logement ");
        QSqlQuery qr;
    qr.prepare("SELECT * FROM LOGEMENT where ID_L LIKE '"+text+"'");
    QString type,adresse,email;
    int id,prix,tel;

               if(qr.exec())  {
             while (qr.next()) {
             id = qr.value(0).toInt();
                 type = qr.value(1).toString();
                 prix = qr.value(2).toInt();
                  adresse= qr.value(3).toString();
                   email= qr.value(4).toString();
                   tel= qr.value(5).toInt();


             }


     }
               QDateTime date = QDateTime::currentDateTime();
               QString formattedTime = "Date:"+date.toString("dd.MM.yyyy hh:mm:ss");
             logement Dtmp(id,type,prix,adresse,email,tel,formattedTime);
              bool test = Dtmp.modifier(id);


              QString id1 = QString::number(id);
              QString  prix1 =  QString::number(prix);
              QString  tel1=  QString::number(tel);





               ui->alarme1->setText(QString(id1));
               ui->alarme2->setText(QString(type));
               ui->alarme3->setText(QString(adresse));
               ui->alarme4->setText(QString(tel1));
               ui->alarme5->setText(QString(email));
               ui->alarme6->setText(QString(prix1));
                ui->alarme7->setText(QString(formattedTime));
                ui->tableView->setModel(Dtmp.afficher());



}



}
//misson

void MainWindow::on_pushButton_clicked()//ajouter
{
// QSqlQuery query;
 int ID=ui->lineEdit_ID->text().toInt();
// QString ETAT=ui->comboetat->currentText();
 //QDate DATE_DEBUT_M=ui->
 QDate inputDATE_DEBUT_M= ui->dateD->date();
  QString DATE_DEBUT_M = inputDATE_DEBUT_M.toString("dd.MM.yyyy");
  QDate inputDATE_FIN_M= ui->dateF->date();
   QString DATE_FIN_M = inputDATE_FIN_M.toString("dd.MM.yyyy");


 QString DESTINATION=ui->lineEdit_DES->text();
 float BUDGET=ui->lineEdit_BUD->text().toInt();
 int NBR_DE_PERSSONES=ui->lineEdit_NBR->text().toInt();
QString TYPE_DE_MISSION=ui->combotype->currentText();
        Mission m(ID,NBR_DE_PERSSONES,BUDGET,DATE_DEBUT_M,DATE_FIN_M,DESTINATION,TYPE_DE_MISSION);


         bool test= m.ajouter();
                        if(test){
                            MainWindow w;
                        w.show();
                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                    QObject::tr("Ajout effectué.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                           ui->tab_Mission->setModel(m.afficher());
                    }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                    QObject::tr("Ajout non effectué.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_SUPPRIMER_clicked()
{
    Mission M1;

int id=ui->lineEdit_ID_S->text().toInt();
  QString recherche=ui->lineEdit_ID_S->text();

  if (M1.rechercherID(recherche)->rowCount()!=0 and recherche.length()!=0)
  {
      /*********************/
      /*********************/

      bool test=M1.supprimer(id);
     QMessageBox::information(nullptr, QObject::tr("Succès"),
  QObject::tr("Suppression effectué.\n"
    "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
    }
    else
        {QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                              QObject::tr("Suppression non effectué !\n"
                                "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}

  ui->tab_Mission->setModel(M1.afficher());



}


void MainWindow::on_MODIFIER_clicked()
{

    int ID=ui->lineEdit_N_ID->text().toInt();
    QString recherche=ui->lineEdit_N_ID->text();
    //QString DATE_DEBUT_M=ui->lineEdit_DD_N->text();
    //QString DATE_FIN_M=ui->lineEdit_DF_N->text();
    QDate inputDATE_DEBUT_M= ui->dateD_2->date();
     QString DATE_DEBUT_M = inputDATE_DEBUT_M.toString("dd.MM.yyyy");
     QDate inputDATE_FIN_M= ui->dateF_2->date();
      QString DATE_FIN_M = inputDATE_FIN_M.toString("dd.MM.yyyy");
    QString DESTINATION=ui->lineEdit_DES_N->text();
    float BUDGET=ui->lineEdit_BUD_N->text().toInt();
    int NBR_DE_PERSSONES=ui->lineEdit_NBR_N->text().toInt();
    QString TYPE_DE_MISSION=ui->combomod->currentText();
  // QString TYPE_DE_MISSION=ui->lineEdit_TY_N->text();
  // int RID=ui->lineEdit_ID1->text().toInt();
            Mission m(ID,NBR_DE_PERSSONES,BUDGET,DATE_DEBUT_M,DATE_FIN_M,DESTINATION,TYPE_DE_MISSION);
            bool valid=true;
          if((m.Verif_id()==true) or (m.Verif_nbr()==true) or (m.Verif_type()==true) or (m.Verif_dateD()==true) or (m.Verif_dateF()==true) or (m.Verif_budget()==true)or (m.Verif_destination()==true))
          {
        if(m.Verif_id())
                     { ui->ver1->clear();
              ui->ver1->setText(QString("!"));


        }

              if(m.Verif_nbr())
                            { ui->ver6->clear();
                    ui->ver6->setText(QString("!"));

                                    }
              if(m.Verif_destination())
                            { ui->ver5->clear();
                  ui->ver5->setText(QString("!"));

             }
              if(m.Verif_type())
                            { ui->ver2->clear();
                   ui->ver2->setText(QString("!"));

            }
              if(m.Verif_dateD())
                            { ui->ver3->clear();
                  ui->ver3->setText(QString("!"));

             }
              if(m.Verif_dateF())
                            { ui->ver4->clear();
                  ui->ver4->setText(QString("!"));
             }
              if(m.Verif_budget())
            { ui->ver7->clear();
                  ui->ver7->setText(QString("!"));

              }
             valid=false;
              }
if (m.rechercherID(recherche)->rowCount()!=0 and recherche.length()!=0)
{
            bool test= m.modifier(ID);
                           if(test){
                               MainWindow w;
                           w.show();
                           QMessageBox::information(nullptr, QObject::tr("database is open"),
                                       QObject::tr("Modification effectué.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                              ui->tab_Mission->setModel(m.afficher());
                       }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                       QObject::tr("Modification non effectué.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
}
else
{QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
               QObject::tr("Modification non effectué !\n"
                 "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}

ui->tab_Mission->setModel(m.afficher());


 }





void MainWindow::on_CHERCHER_clicked()
{
    Mission M1;
    QString recherche = ui->lineEdit_cher->text();
    if(recherche.length()!=0)
{
       //ui->tab_Mission->setModel(M1.rechercherType(recherche));
    // ui->tab_Mission->setModel(M1.rechercherID(recherche));
        if(ui->comboBox_cher->currentIndex()==0){
            ui->tab_Mission->setModel(M1.rechercherType(recherche));
           // ui->tab_Mission->setModel(m.triID());

        }
        else if (ui->comboBox_cher->currentIndex()==1)
        {
             ui->tab_Mission->setModel(M1.rechercherNBP(recherche));
           // ui->tab_Mission->setModel(m.triNBP());

        }
        else if(ui->comboBox_cher->currentIndex()==2)
        {
            ui->tab_Mission->setModel(M1.rechercherID(recherche));


    }
    else
    {
       ui->tab_Mission->setModel(M1.afficher());
    }
}
}

void MainWindow::on_pushButton_ANNULER_clicked()
{
         ui->lineEdit_ID->clear();
         ui->lineEdit_BUD->clear();
        // ui->lineEdit_DD->clear();
        //ui->lineEdit_DF->clear();
         ui->lineEdit_DES->clear();
         ui->lineEdit_NBR->clear();
         ui->combotype->clear();
}

void MainWindow::on_pushButton_ANNULER2_clicked()
{
     ui->lineEdit_N_ID->clear();
     ui->lineEdit_BUD_N->clear();
    // ui->lineEdit_DD_N->clear();
    //ui->lineEdit_DF_N->clear();
     ui->lineEdit_DES_N->clear();
     ui->lineEdit_NBR_N->clear();
     ui->combomod->clear();
     ui->ver1->clear();
     ui->ver2->clear();
     ui->ver3->clear();
     ui->ver4->clear();
     ui->ver5->clear();
     ui->ver6->clear();
     ui->ver7->clear();
}

void MainWindow::on_ANNULER3_clicked()
{
   ui->lineEdit_ID_S->clear();
}


void MainWindow::on_pushButton_10_clicked() //tri
{
    Mission m;
    if(ui->comboBox_3->currentIndex()==0){
        ui->tab_Mission->setModel(m.triID());
       cout << "tri id" << endl;
    }
    else if (ui->comboBox_3->currentIndex()==1)
    {
        ui->tab_Mission->setModel(m.triNBP());
        cout << "tri nbp" << endl;
    }
    else if(ui->comboBox_3->currentIndex()==2)
    {
        ui->tab_Mission->setModel(m.triBUD());
        cout << "tri bud" << endl;
    }
    else
        cout << "no combobox" << endl;
}



/*void MainWindow::on_tab_Mission_activated(const QModelIndex &index)
{

}*/

void MainWindow::on_pushButton_7_clicked() //PDF
{
    QString strStream;
                       QTextStream out(&strStream);

                       const int rowCount = ui->tab_Mission->model()->rowCount();
                       const int columnCount = ui->tab_Mission->model()->columnCount();
                       QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                       out <<"<html>\n"
                             "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           << "<title> LISTE DES PRODUITS<title>\n "
                           << "</head>\n"
                           "<body bgcolor=#ffffff link=#5000A0>\n"
                           "<h1 style=\"text-align: center;\"><strong> **LISTE DES MISSIONS ** "+TT+"</strong></h1>"
                           "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                             "</br> </br>";
                       // headers
                       out << "<thead><tr bgcolor=#d6e5ff>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->tab_Mission->isColumnHidden(column))
                               out << QString("<th>%1</th>").arg(ui->tab_Mission->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";

                       // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tab_Mission->isColumnHidden(column)) {
                                   QString data =ui->tab_Mission->model()->data(ui->tab_Mission->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";

                       QTextDocument *document = new QTextDocument();
                       document->setHtml(strStream);

                       QPrinter printer;

                       QPrintDialog *test = new QPrintDialog(&printer, NULL);
                       if (test->exec() == QDialog::Accepted) {
                           document->print(&printer);
                       }

                       delete document;
}

void MainWindow::on_pushButton_3_clicked() //ref
{
    Mission M1;

 ui->tab_Mission->setModel(M1.afficher());
 ui->lineEdit_cher->clear();
}

void MainWindow::on_pushButton_8_clicked()//stat
{
    Dialog d;
    d.stats();
    d.setWindowTitle("statistique");
    d.exec();
}


void MainWindow::on_execl_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tab_Mission);

    //colums to export
    obj.addField(0,"IDENTIFIANT", "char(20)");
    obj.addField(1,"DATE_DEBUT_M", "char(20)");
    obj.addField(2,"NBR_PERSONES", "char(20)");
    obj.addField(3,"DESTINATION", "char(20)");
    obj.addField(4,"BUDGET", "char(20)");
    obj.addField(5,"DATE_FIN_M", "char(20)");
    obj.addField(6,"TYPE_MISSION", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}


void MainWindow::on_calendarWidget_clicked(const QDate &date)
{

    qInfo()<<date;

       ui->tableCALEN->setModel(m.recherche_DATED(date));


}




void MainWindow::on_tableCALEN_activated(const QModelIndex &index)
{
   QString val=ui->tableCALEN->model()->data(index).toString();

  QSqlQuery qry;
  qry.prepare("select * FROM MISSION where ID=:ID" );
  qry.bindValue(":ID",val);
  if(qry.exec())

      while (qry.next()) {


  {
      ui->lineEdit_ID_S->setText(qry.value(0).toString());//supprimer
      ui->lineEdit_N_ID->setText(qry.value(0).toString());
      ui->lineEdit_NBR_N->setText(qry.value(2).toString());
      ui->lineEdit_DES_N->setText(qry.value(3).toString());
      ui->lineEdit_BUD_N->setText(qry.value(4).toString());
      //ui->lineEdit_->setText(qry.value(3).toString());
}
  }
  }



void MainWindow::afficherMissionArduino(){
    QString dateRDV,message;
    data = A.read_from_arduino();
    QString DataAsString = QTextCodec::codecForMib(106)->toUnicode(data);
    if(data == "0"){
        A.write_to_arduino("ms n'existe pas");
    }
    else{
        QSqlQuery query,query1;
             query.prepare("select * from MISSION where ID =:ID ");
             query.bindValue(":ID", DataAsString);
             query.exec();
             while(query.next()){
                 dateRDV = query.value(0).toString();
                 if(query.value(7).toInt() == 0){
                     query1.prepare("update MISSION set ETAT =:ETAT where ID=:ID");
                     query1.bindValue(":ETAT","1");
                     query1.bindValue(":ID", DataAsString);
                     query1.exec();

                     message = "mission "+ dateRDV + "terminé";
                 }
                 else{
                        message ="mis deja fait";
                     }
                 }
             A.write_to_arduino(message.toUtf8());
             }
}







//
void MainWindow::on_Gestion1_clicked()
{
<<<<<<< HEAD:mainwindow.cpp
 ui->stackedWidget->setCurrentIndex(1);
=======
 ui->stackedWidget->setCurrentIndex(2);
>>>>>>> 279b53c37b357bc694b3239812a2b7ebc148bca2:integration  taher + nidhal + syrine + wassim + rahma/mainwindow.cpp
}

void MainWindow::on_Gestion2_clicked()
{
<<<<<<< HEAD:mainwindow.cpp
  ui->stackedWidget->setCurrentIndex(2);
}
=======
  ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_Gestion6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

>>>>>>> 279b53c37b357bc694b3239812a2b7ebc148bca2:integration  taher + nidhal + syrine + wassim + rahma/mainwindow.cpp


void MainWindow::on_todolistBUTTON_clicked()
{
    TodoList *app;
    app = new TodoList();
    app->show();
    //this->close();
}

void MainWindow::on_pushButton_quitter_admin_crud_clicked()
{
    Dialoglogin *l;

    l = new Dialoglogin();

        l->show();
        this->close();
}
//gestion partenaire
void MainWindow::on_Gestion3_clicked()
{
<<<<<<< HEAD:mainwindow.cpp
    ui->stackedWidget->setCurrentIndex(3);
}

=======
    ui->stackedWidget->setCurrentIndex(4);
}
//gestion clients
void MainWindow::on_Gestion4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}
>>>>>>> 279b53c37b357bc694b3239812a2b7ebc148bca2:integration  taher + nidhal + syrine + wassim + rahma/mainwindow.cpp

// Partenaire_ajout
void MainWindow::on_pushButton_partenaire_ajouter_clicked()
{
 Partenaire p ;
 p.set_id(ui->lineEdit_ID_ajouter_partenaire->text());
 p.set_nom(ui->lineEdit_Nom_ajouter_partenaire->text());
 p.set_mail(ui->lineEdit_Mail_ajouter_partenaire->text());
 p.set_numtel(ui->lineEdit_NumTel_ajouter_partenaire->text());
 p.set_dureecontrat(ui->lineEdit_Dureecontrat_ajouter_partenaire->text());
 p.set_remise(ui->lineEdit_Remise_ajouter_partenaire->text());
 p.set_type(ui->comboBox_type_partenaire->currentText());
 bool ajout= p.ajouter(p);
 if(ajout)
    {
        ui->tableView_partenaire->setModel(partenaire.afficher());
        QMessageBox::information(nullptr, QObject::tr("PARTENAIRE ajouter"),
                    QObject::tr("PARTENAIRE ajouter.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else

        QMessageBox::critical(nullptr, QObject::tr("PARTENAIRE non ajouter"),
                    QObject::tr("PARTENAIRE non ajouter.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

//Partenaire_supprimer
void MainWindow::on_pushButton_partenaire_supprimer_clicked()
{
    Partenaire p ;
    int id=ui->lineEdit_ID_supprimer_partenaire->text().toInt();
    bool supprime= p.supprimer(id);
    if(supprime)
       {

           QMessageBox::information(nullptr, QObject::tr("PARTENAIRE supprimer"),
                       QObject::tr("PARTENAIRE supprimer.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_partenaire->setModel(partenaire.afficher());

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("PARTENAIRE non supprimer"),
                       QObject::tr("PARTENAIRE non supprimer.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}




//Partenaire_modifier

void MainWindow::on_pushButton_partenaire_modifier_clicked()
{
    Partenaire p ;
    p.set_id(ui->lineEdit_ID_modifier_partenaire->text());
    p.set_nom(ui->lineEdit_Nom_modifier_partenaire->text());
    p.set_mail(ui->lineEdit_Mail_modifier_partenaire->text());
    p.set_numtel(ui->lineEdit_NumTel_modifier_partenaire->text());
    p.set_dureecontrat(ui->lineEdit_Dureecontrat_modifier_partenaire->text());
    p.set_remise(ui->lineEdit_Remise_modifier_partenaire->text());
    p.set_type(ui->comboBox_type2_partenaire->currentText());
    bool modif= p.modifier(p);
    if(modif)
       {
           ui->tableView_partenaire->setModel(partenaire.afficher());
           QMessageBox::information(nullptr, QObject::tr("PARTENAIRE modifier"),
                       QObject::tr("PARTENAIRE modifier.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("PARTENAIRE non modifier"),
                       QObject::tr("PARTENAIRE non modifier.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}


//Partenaire_pdf
void MainWindow::on_pushButton_partenaire_pdf_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tableView_partenaire->model()->rowCount();
                    const int columnCount =ui->tableView_partenaire->model()->columnCount();


                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("eleve")
                            <<  "</head>\n"
                            "<body bgcolor=#F2E7D5 link=#393E46>\n"
                                "<h1>Liste des Partenaires</h1>"

                                "<table border=0 cellspacing=5 cellpadding=5>\n";

                    // headers
                        out << "<thead><tr bgcolor=#F2E7D5>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableView_partenaire->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tableView_partenaire->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tableView_partenaire->isColumnHidden(column)) {
                                       QString data = ui->tableView_partenaire->model()->data(ui->tableView_partenaire->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n"
                               "</body>\n"
                               "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);
            //QTextDocument document;
            //document.setHtml(html);
            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:\\Users\\Asus TUF\\Desktop\\pdf_output\\pdf.pdf");
            document->print(&printer);

}
//Partenaire_tri
void MainWindow::on_pushButton_partenaire_tri_clicked()
{
  if (ui->comboBox_tri_partenaire->currentText()=="Tri par ordre croissant")
  {
  ui->tableView_partenaire->setModel(partenaire.triercroissant());
  }
  else if (ui->comboBox_tri_partenaire->currentText()=="Tri par ordre decroissant")
  {
    ui->tableView_partenaire->setModel(partenaire.trierdecroissant());
  }
  else
  ui->tableView_partenaire->setModel(partenaire.trierref());
}
//Partenaire_stat
void MainWindow::on_pushButton_partenaire_stats_clicked()
{
/*statistique_partenaire *s = new statistique_partenaire(this);
s->show();


*/
}

//Partenaire_rechercher
void MainWindow::on_pushButton_partenaire_rechercher_clicked()
{
    Partenaire p ;
     if (ui->comboBox_recherche_partenaire->currentText()=="ID")
     {
         int id=ui->lineEdit_R_partenaire->text().toInt();
          ui->tableView_partenaire->setModel(partenaire.Rechercher_ID(id));
     }
     else if (ui->comboBox_recherche_partenaire->currentText()=="Type")
     {
         QString type=ui->lineEdit_R_partenaire->text();
         ui->tableView_partenaire->setModel(partenaire.Rechercher_TYPE(type));
     }
     else
     {
         QString nom = ui->lineEdit_R_partenaire->text();
         ui->tableView_partenaire->setModel(partenaire.Rechercher_NOM(nom));
     }

}







//Partenaire_Reset
void MainWindow::on_pushButton_partenaire_reset_clicked()
{
   ui->tableView_partenaire->setModel(partenaire.afficher());
}

/*void MainWindow::afficherMissionArduino(){
    QString dateRDV,message;
    data = A.read_from_arduino();
    QString DataAsString = QTextCodec::codecForMib(106)->toUnicode(data);
    if(data == "0"){
        A.write_to_arduino("ms n'existe pas");
    }
    else{
        QSqlQuery query,query1;
             query.prepare("select * from MISSION where ID =:ID ");
             query.bindValue(":ID", DataAsString);
             query.exec();
             while(query.next()){
                 dateRDV = query.value(0).toString();
                 if(query.value(7).toInt() == 0){
                     query1.prepare("update MISSION set ETAT =:ETAT where ID=:ID");
                     query1.bindValue(":ETAT","1");
                     query1.bindValue(":ID", DataAsString);
                     query1.exec();

                     message = "mission "+ dateRDV + "terminé";
                 }
                 else{
                        message ="mis deja fait";
                     }
                 }
             A.write_to_arduino(message.toUtf8());
             }
}*/

<<<<<<< HEAD:mainwindow.cpp
=======



void MainWindow::on_pushButton_5_clicked()
{
    //bouton ajouter client
    QString id= ui->ID->text();
   QString nom= ui->NAME->text();
   QString prenom= ui->PRENOM->text();
   QString Adresse= ui->ADRESSE->text();
   QString statut = ui->comboBox_4->currentText();
   int Tel = ui->TEL->text().toInt();
   int CIN = ui->CIN->text().toInt();

   Client c (CIN,Tel , nom , prenom , Adresse , statut) ;


   bool test= c.ajouter();

   QMessageBox msgBox ;
   if (test)
     {  msgBox.setText("ajout avec succes");
      ui->tab_clients->setModel(c.afficher());
      ui->CIN->clear();
      ui->NAME->clear();
      ui->PRENOM->clear();
      ui->ADRESSE->clear();
      ui->TEL->clear();
   }
   else
       msgBox.setText("echec d'ajout");
   msgBox.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
    // afficher tableau client
    ui->tab_clients->setModel(c.afficher());
}

void MainWindow::on_TRI_nom_clicked()
{//trier le tableau client par nom
   ui->tab_clients->setModel(c.tri_nom());

}

void MainWindow::on_TRI_clicked()
{//trier le tableau client par iD
    ui->tab_clients->setModel(c.tri());
}

void MainWindow::on_pb_recherche_clicked()
{
    //rechercher client par id
    if (ui->lineEdit->text().isEmpty())
        {
            QMessageBox::information(nullptr,QObject::tr("ERREUR"),QObject::tr("INFORMATIONS MANQUANTES\n""click to Cancel to exit."), QMessageBox::Cancel);

        }
        else {
        QString val = ui->lineEdit->text();
       ui->tab_clients->setModel(c.recherche(val));
       ui->lineEdit->clear();
}
}

void MainWindow::on_pb_pdf_clicked()
{

   //generer un pdf file pour clients
    QPdfWriter pdf("C:/Users/WIN10PRO/Desktop/rahma.pdf");

           QPainter painter(&pdf);
          painter.setPen(Qt::green);
          painter.setFont(QFont("Times New Roman", 40));
          painter.drawText(1500,1500,"LISTE DES CLIENTS");
          painter.drawRect(3800,1200,1700,500);
          painter.drawRect(0,3000,9600,500);
          painter.setPen(Qt::blue);
          painter.setFont(QFont("Arial Black", 11));
          painter.drawText(500,3300,"ID");
          painter.drawText(2000,3300,"CIN");
          painter.drawText(3500,3300,"TEL");
          painter.drawText(5000,3300,"NOM");
          painter.drawText(6500,3300,"PRENOM");
          painter.drawText(8000,3300,"ADRESSE");
          painter.drawText(10000,3300,"STATUT");



          QSqlQuery query;
          int i = 4000;

           query.prepare("select * from CLIENT");
           query.exec();
        while (query.next())
          {
          painter.setPen(Qt::black);
          painter.setFont(QFont("Arial", 15));
          painter.drawText(500,i,query.value(0).toString());
          painter.drawText(2000,i,query.value(1).toString());
          painter.drawText(3500,i,query.value(2).toString());
          painter.drawText(5000,i,query.value(3).toString());
          painter.drawText(6500,i,query.value(4).toString());
          painter.drawText(8000,i,query.value(5).toString());
          painter.drawText(10000,i,query.value(6).toString());



          i = i +500;
                              }
}

void MainWindow::on_pushButton_12_clicked()
{//bouton modifier client
    int ID=ui->ID_MOD->text().toInt();
    QString nom= ui->NOM_MOD->text();
    QString prenom= ui->PRENOM_MOD->text();
    QString Adresse= ui->ADRESSE_MOD->text();
    QString statut = ui->STATUT_MOD->currentText();
    int Tel = ui->TEL_MOD->text().toInt();
    int CIN = ui->CIN_MOD->text().toInt();


     Client C (ID,CIN , Tel , nom , prenom , Adresse,statut) ;

    bool test=C.modifier(ID);
    if (test)
      {
        ui->tab_clients->setModel(c.afficher());
    QMessageBox::information(nullptr,QObject::tr("done"),QObject::tr("modification effectué\n""click to Cancel to exit."), QMessageBox::Cancel);
    ui->tab_clients->setModel(c.afficher());
    ui->ID_MOD->clear();
    ui->CIN_MOD->clear();
    ui->NOM_MOD->clear();
    ui->PRENOM_MOD->clear();
    ui->NOM_MOD->clear();
    }

    else
    {QMessageBox::critical(nullptr, QObject::tr("not done"),QObject::tr("modification non effectué.\n" "click to cancel to exit."),QMessageBox::Cancel);}


}

void MainWindow::on_pushButton_14_clicked()
{
    //bouton supprimer client
    Client c1 ;
    c1.setCIN( (ui->Cin_supp->text().toInt())) ;
    bool test= c1.supprimer(c1.getCIN()) ;

    QMessageBox msgBox ;
    if (test)
    {
    msgBox.setText("suppression avec succes");
    ui->tab_clients->setModel(c1.afficher());
    }
    else
        msgBox.setText("echec de suppression");
    msgBox.exec();

}

void MainWindow::on_pushButton_15_clicked()
{
    //bouton stt
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM client WHERE statut='Single' ");
        int number1=model->rowCount();
        model->setQuery("SELECT * FROM client WHERE statut='Sous societe'");
        int number2=model->rowCount();

        int total=number1+number2;
        QString a = QString("single  "+QString::number((number1*100)/total,'f',2)+"%");
        QString b = QString("sous societe  "+QString::number((number2*100)/total,'f',2)+"%");

        //charte pie style
        QPieSeries *series = new QPieSeries();
        series->append(a,number1); //te9sem charte graphique
        series->append(b,number2);

        if (number1!= 0)
        {
            //partie 1 de cercle
            QPieSlice *slice = series->slices().at(0);
            //affichage de pourcantage
            slice->setLabelVisible();
        }
        if (number2!=0)
        {
            //partie 2 de cercle
            QPieSlice *slice1 = series->slices().at(1);
            //affichage de pourcantage
            slice1->setLabelVisible();
        }
        //Create the chart widget
        QChart *chart = new QChart();
        //ajout des donnee et titre
        chart->addSeries(series);
        chart->setTitle("Pourcentage des statut des clients ");
        //afficher le charte avec sa parametre de taille
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();
}

>>>>>>> 279b53c37b357bc694b3239812a2b7ebc148bca2:integration  taher + nidhal + syrine + wassim + rahma/mainwindow.cpp
