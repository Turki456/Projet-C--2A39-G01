#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include<QString>
#include <QMessageBox>
#include<QIntValidator>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   ui->ID_2->setValidator( new QIntValidator(0, 999, this));
   ui->nom_2->setValidator( new QIntValidator(0, 50, this));
   ui->prenom_2->setValidator( new QIntValidator(0, 50, this));
   ui-> CIN ->setValidator(new QIntValidator (00000001,99999999, this)) ;
   ui-> tab_clients->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


QString nom= ui->nom_2->text();
QString prenom= ui->prenom_2->text();
QString Adresse= ui->adresse_2->text();
QString statut = ui->Statut->currentText();
QString Tel = ui->num_tel->text();
QString CIN = ui->CIN->text();

Client C (int ID ,int CIN, int Tel ,QString nom , QString prenom ,QString Adresse ,QString statut) ;
bool test= c.ajouter() ;
QMessageBox msgBox ;
if (test)
  {  msgBox.setText("ajout avec succes");
  ui->tab_clients->setModel(c.afficher());
}
else
    msgBox.setText("echec d'ajout");
msgBox.exec();

}

void MainWindow::on_Supprimer_clicked()
{
Client c1 ; c1.setID (ui->ID_supp->text().toInt()) ;
bool test= c.supprimer(c1.getID()) ;

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

