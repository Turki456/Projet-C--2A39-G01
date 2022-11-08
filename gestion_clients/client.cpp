#include "client.h"
#include <QString>
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
using namespace std ;

Client::Client()
{
    ID=0;
    nom=" ";
    prenom=" ";
    Adresse=" ";
    statut=" ";

}

Client::Client (int ID ,int CIN,int Tel ,QString nom ,QString prenom ,QString Adresse ,QString statut)
{
    this->ID=ID;
    this->CIN=CIN;
    this->Tel=Tel;
    this->nom=nom;
    this->prenom=prenom;
    this->Adresse=Adresse;
    this->statut=statut;
}


bool Client::ajouter()
{
    bool test=false ;
    QSqlQuery query;
    QString id_string= QString::number(ID);
    QString tel_string= QString::number(Tel);
    QString CIN_string= QString::number(CIN);
          query.prepare("INSERT INTO Client (ID,nom,prenom,Adresse,statut,Tel,CIN) "
                        "VALUES (:id, :nom, :prenom, :Adresse, :statut, :Tel, :CIN)");
          query.bindValue(":id", id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":Adresse", Adresse);
          query.bindValue(":statut", statut);
          query.bindValue(":TEL", tel_string);
          query.bindValue(":CIN", CIN_string);
          query.exec();




    return test ;

}

QSqlQueryModel* Client::afficher()
{
QSqlQueryModel *model= new QSqlQueryModel();

      model->setQuery("SELECT* FROM client");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Le nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Le prenom"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("L'adresse"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Le statut"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("Telephone"));
}



bool Client::supprimer(int IID)
{
    QSqlQuery query;

          query.prepare("Delete from client where id=:ID");
          query.bindValue(":id", IID);

                  return  query.exec();
}




bool Client::modifier (int ID_supp)
{
    QSqlQuery query;
   QString ID_supp_string= QString::number(ID_supp);


    query.prepare("UPDATE Client set nom=:nom, prenom=:prenom where ID_supp=:ID_supp");


    QString id_string= QString::number(ID);
    QString tel_string= QString::number(Tel);
    QString CIN_string= QString::number(CIN);

    query.bindValue(":id", ID);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":Adresse", Adresse);
    query.bindValue(":statut", statut);
    query.bindValue(":TEL", tel_string);
    query.bindValue(":CIN", CIN_string);


    //execution de la requetteNU
    return query.exec();
}
