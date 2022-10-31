#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
Employe::Employe()
{
    ID = 0;
    CIN = 0;
    salaire = 0;
    nom =" ";
    prenom =" ";
    poste =" ";
    adresse =" ";
}
Employe:: Employe(int ID,int CIN,float salaire,QString nom,QString prenom,QString poste,QString adresse)
{
    this->ID = ID;
    this->CIN = CIN;
    this->salaire = salaire;
    this->nom = nom;
    this->prenom = prenom;
    this->poste = poste;
    this->adresse = adresse;
}
bool Employe::ajouter()
{
    QSqlQuery query;
    QString ID_string = QString::number(ID);
    QString CIN_string = QString::number(CIN);
    QString salaire_string = QString::number(salaire);

    //requête Sql
    query.prepare("INSERT INTO Employe(ID,CIN,salaire,nom,prenom,poste,adresse)"
                  "VALUES(:ID,:CIN,:salaire,:nom,:prenom,:poste,:adresse)");
    //Saisi des données
    query.bindValue(":ID",ID_string);
    query.bindValue(":CIN",CIN_string);
    query.bindValue(":salaire",salaire_string);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":adresse",adresse);

    //Execution de la requête
    return query.exec();
}
bool Employe::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);

    //requête Sql
    query.prepare("DELETE FROM Employe where ID= :id");

    //Saisi de l'ID à supprimer
    query.bindValue(":id",res);

    //Execution de la requête
    return query.exec();
}

QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    //Lecture des données issues de la base de données
    model->setQuery("SELECT * FROM Employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));

    return model;
}














