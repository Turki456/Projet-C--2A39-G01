#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouterEmploye_clicked()
{
     //Recuperation des informations du UI
    int ID=ui->ID_le->text().toInt();
    int CIN=ui->CIN_le->text().toInt();
    float salaire=ui->salaire_le->text().toFloat();
    QString nom=ui->nom_le->text();
    QString prenom=ui->prenom_le->text();
    QString poste=ui->poste_le->text();
    QString adresse=ui->adresse_le->text();

    //Appel du constructeur employe
    Employe E(ID,CIN,salaire,nom,prenom,poste,adresse);

    //Appel de la fonction Ajouter
    bool test=E.ajouter();

    //Test sur l'execution de la requete
    if(test)
    {
         //mise à jour de l'affichage
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Ajout non effectué\n""Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_supprimerEmploye_clicked()
{
   //Recuperation de l'id
   int ID=ui->IDsupp_le->text().toInt();

   //Appel de la fonction supprimer
   bool test=Etmp.supprimer(ID);

   //Test sur l'execution de la requete
   if(test)
   {
       //mise à jour de l'affichage
       ui->tableView->setModel(Etmp.afficher());
       QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression effectué\n""Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Suppression non effectué\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_tableauCRUD_tabBarClicked(int index)
{
    //Regeneration des informations a chaque clique du tableau
        ui->tableView->setModel(Etmp.afficher());
}

void MainWindow::on_pushButton_modifierEmploye_clicked()
{

    QSqlQuery query;

    QString id=ui->ID_le->text();
    QString CIN=ui->CIN_le->text();
    QString salaire=ui->salaire_le->text();
    QString nom=ui->nom_le->text();
    QString prenom=ui->prenom_le->text();
    QString poste=ui->poste_le->text();
    QString adresse=ui->adresse_le->text();

    query.prepare("update Employe set ID='"+id+"',CIN='"+CIN+"',salaire='"+salaire+"',nom='"+nom+"',prenom='"+prenom+"',poste='"+poste+"',adresse='"+adresse+"' where ID='"+id+"'");
    if(query.exec())
    {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Modification effectué\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Modification non effectué\n""Click Cancel to exit."), QMessageBox::Cancel);
}
