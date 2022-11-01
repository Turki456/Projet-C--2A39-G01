#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logement.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QPixmap>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp reg("^([a-zA-Z.]+)$ ");
           QValidator *validator = new QRegExpValidator(reg, this);
           QRegExp reg1("^([a-zA-Z0-9_\-\.]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$ ");
           QValidator *validator1 = new QRegExpValidator(reg1, this);
    ui->ID->setValidator(new QIntValidator(0, 99999999,this));;
   ui->type->setValidator(validator);
    ui->adresse->setValidator(validator);
    ui->Mail->setValidator(validator1);
    ui->Prix->setValidator(new QIntValidator(0, 99999999,this));
    ui->Tel->setValidator(new QIntValidator(0, 99999999,this));


    ui->ID__M->setValidator(new QIntValidator(0, 99999999,this));
    ui->type_M->setValidator(validator);
    ui->adresse_M->setValidator(validator);
    ui->mail_M->setValidator(validator1);
    ui->prix_M->setValidator(new QIntValidator(0, 99999999,this));
    ui->Tel_M->setValidator(new QIntValidator(0, 99999999,this));

    ui->le_id_Supp->setValidator(new QIntValidator(0, 99999999,this));

    ui->le_chercher->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Confirmer_clicked()
{   QString taille=ui->ID->text();
    int id=ui->ID->text().toInt();
    QString type=ui->type->text();
    QString adresse=ui->adresse->text();
    QString email=ui->Mail->text();
    int prix=ui->Prix->text().toInt();
    int tel=ui->Tel->text().toInt();
    logement Dtmp(id,type,prix,adresse,email,tel);
     bool valid=true;
   if((Dtmp.Verif_type()==true) or (Dtmp.Verif_id()==true) or (Dtmp.Verif_ads()==true) or (Dtmp.Verif_prix()==true) or (Dtmp.Verif_tel()==true) or (Dtmp.Verif_email()==true))
   {

if(Dtmp.Verif_type())
              { ui->verifier2->clear();
       ui->verifier2->setText(QString("Le type doit être non vide"));


 }

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
       if(Dtmp.Verif_tel())
                     { ui->verifier4->clear();
           ui->verifier4->setText(QString("Le tel doit etre non vide"));


      }
       if(Dtmp.Verif_email())
                     { ui->verifier5->clear();
           ui->verifier5->setText(QString("Le email doit etre non vide"));


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
   ui->type->clear();
   ui->adresse->clear();
  ui->Mail->clear();
   ui->Prix->clear();
    ui->Tel->clear();
    ui->verifier1->clear();
   ui->verifier2->clear();
   ui->verifier3->clear();
  ui->verifier4->clear();
   ui->verifier5->clear();
    ui->verifier6->clear();
    ui->tableView->setModel(Dtmp.afficher());


}
void MainWindow::on_Modifier_clicked()
{
    QString  recherche=ui->ID__M->text();
    int id=ui->ID__M->text().toInt();
    QString type=ui->type_M->text();
    QString adresse=ui->adresse_M->text();
    QString email=ui->mail_M->text();
    int prix=ui->prix_M->text().toInt();
    int tel=ui->Tel_M->text().toInt();
    logement Dtmp(id,type,prix,adresse,email,tel);
    bool valid=true;
  if((Dtmp.Verif_type()==true) or (Dtmp.Verif_id()==true) or (Dtmp.Verif_ads()==true) or (Dtmp.Verif_prix()==true) or (Dtmp.Verif_tel()==true) or (Dtmp.Verif_email()==true))
  {
if(Dtmp.Verif_type())
             { ui->verifier8->clear();
      ui->verifier8->setText(QString("Le type doit être non vide"));


}

      if(Dtmp.Verif_id())
                    { ui->verifier7->clear();
            ui->verifier7->setText(QString("Le id doit etre non vide"));


   }
      if(Dtmp.Verif_ads())
                    { ui->verifier9->clear();
          ui->verifier9->setText(QString("L'adresse doit etre non vide"));



     }
      if(Dtmp.Verif_prix())
                    { ui->verifier12->clear();
           ui->verifier12->setText(QString("Le prix doit etre non vide"));



    }
      if(Dtmp.Verif_tel())
                    { ui->verifier10->clear();
          ui->verifier10->setText(QString("Le tel doit etre non vide"));


     }
      if(Dtmp.Verif_email())
                    { ui->verifier11->clear();
          ui->verifier11->setText(QString("Le email doit etre non vide"));


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

    ui->ID__M->clear();
   ui->type_M->clear();
   ui->adresse_M->clear();
  ui->mail_M->clear();
   ui->prix_M->clear();
    ui->Tel_M->clear();
    ui->verifier7->clear();
   ui->verifier8->clear();
   ui->verifier9->clear();
  ui->verifier10->clear();
   ui->verifier11->clear();
    ui->verifier12->clear();
    ui->tableView->setModel(Dtmp.afficher());


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
{   int id=ui->le_id_Supp->text().toInt();
    QString recherche=ui->le_id_Supp->text();

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
    ui->le_id_Supp->clear();
}
void MainWindow::on_pushButton_2_clicked()
{
    ui->ID->clear();
   ui->type->clear();
   ui->adresse->clear();
  ui->Mail->clear();
   ui->Prix->clear();
    ui->Tel->clear();
}
void MainWindow::on_Annuler_clicked()
{     ui->ID__M->clear();
      ui->type_M->clear();
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
