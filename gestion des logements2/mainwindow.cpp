#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logement.h"
#include <QMessageBox>
#include <QIntValidator>
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



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Dtmp.afficher());
    ui->cb_id_supp->setModel(Dtmp.getAllId());
        ui->cb_id_modiff->setModel(Dtmp.getAllId());
        ui->cb_id_QR->setModel(Dtmp.getAllId());
    QRegExp reg("^([a-zA-Z.]+)$ ");
           QValidator *validator = new QRegExpValidator(reg, this);
           QRegExp reg1("^([a-zA-Z0-9_\-\.]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$ ");
           QValidator *validator1 = new QRegExpValidator(reg1, this);
    ui->ID->setValidator(new QIntValidator(0, 99999999,this));;

    ui->adresse->setValidator(validator);
    ui->Mail->setValidator(validator1);
    ui->Prix->setValidator(new QIntValidator(0, 99999999,this));
    ui->Tel->setValidator(new QIntValidator(0, 99999999,this));




    ui->adresse_M->setValidator(validator);
    ui->mail_M->setValidator(validator1);
    ui->prix_M->setValidator(new QIntValidator(0, 99999999,this));
    ui->Tel_M->setValidator(new QIntValidator(0, 99999999,this));



    ui->le_chercher->setValidator(validator);
    QTimer *t = new QTimer(this);
        t->setInterval(1000);
        connect(t, &QTimer::timeout, [&]() {
           QString time1 = QTime::currentTime().toString();
           ui->label_clock->setText(time1);
        } );
        t->start();
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
    logement Dtmp(id,type,prix,adresse,email,tel);
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
    logement Dtmp(id,type,prix,adresse,email,tel);
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
    if(recherche.length()!=0)

       ui->tableView->setModel(Dtmp.rechercherType(recherche));
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
{
    if(ui->comboBox->currentText()=="afficher")
      ui->tableView->setModel(Dtmp.afficher());
    else if(ui->comboBox->currentText()=="Trie par ID par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_ID_A());
    else if (ui->comboBox->currentText()=="Trie par ID par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_ID_D());
    else if (ui->comboBox->currentText()=="Trie par Prix par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_PRIX_A());
    else if (ui->comboBox->currentText()=="Trie par Prix par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_PRIX_D());
    else if (ui->comboBox->currentText()=="Trier par Adresse par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_adresse_A());
    else if (ui->comboBox->currentText()=="Trier par Adresse par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_adresse_D());
    else if (ui->comboBox->currentText()=="Trier les Hotels par ID par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_Hotel_ID_A());
    else if (ui->comboBox->currentText()=="Trier les Hotels par ID par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_Hotel_ID_D());
    else if (ui->comboBox->currentText()=="Trier les Hotels par Prix par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_Hotel_PRIX_A());
    else if (ui->comboBox->currentText()=="Trier les Hotels par Prix par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_Hotel_PRIX_D());
    else if (ui->comboBox->currentText()=="Trier les Hotels par Adresse par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_Hotel_adresse_A());
    else if (ui->comboBox->currentText()=="Trier les Hotels par Adresse par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_Hotel_adresse_D());
    else if (ui->comboBox->currentText()=="Trier les Maisons par ID par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_Maison_ID_A());
    else if (ui->comboBox->currentText()=="Trier les Maisons par ID par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_Maison_ID_D());
    else if (ui->comboBox->currentText()=="Trier les Maisons par Prix par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_Maison_PRIX_A());
    else if (ui->comboBox->currentText()=="Trier les Maisons par Prix par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_Maison_PRIX_D());
    else if (ui->comboBox->currentText()=="Trier les Maisons par Adresse par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_Maison_adresse_A());
    else if (ui->comboBox->currentText()=="Trier les Maisons par Adresse par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_Maison_adresse_D());
    else if (ui->comboBox->currentText()=="Trier les Appartements par ID par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_Appartement_ID_A());
    else if (ui->comboBox->currentText()=="Trier les Appartements par ID par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_Appartement_ID_D());
    else if (ui->comboBox->currentText()=="Trier les Appartements par Prix par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_Appartement_PRIX_A());
    else if (ui->comboBox->currentText()=="Trier les Appartements par Prix par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_Appartement_PRIX_D());
    else if (ui->comboBox->currentText()=="Trier les Appartements par Adresse par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_Appartement_adresse_A());
    else if (ui->comboBox->currentText()=="Trier les Appartements par Adresse par ordre decroissant")
        ui->tableView->setModel(Dtmp.Trier_Appartement_adresse_D());

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
                           "<h1 style=\"text-align: center;\"><strong> **LISTE DES DONS ** "+TT+"</strong></h1>"
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
