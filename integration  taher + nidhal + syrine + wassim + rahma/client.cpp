#include "client.h"
#include "client.h"
#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include<QObject>




Client::Client()
{
    ID=0;
    CIN=0;
    Tel=0;
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
Client::Client (int CIN,int Tel ,QString nom ,QString prenom ,QString Adresse ,QString statut)
{

    this->CIN=CIN;
    this->Tel=Tel;
    this->nom=nom;
    this->prenom=prenom;
    this->Adresse=Adresse;
    this->statut=statut;
}


QString Client::returnName(QString cin){
    QSqlQuery q("select * from client where cin='"+cin+"'");
    while(q.next())
        return q.value(3).toString()+" "+q.value(4).toString();
    return "";
}

bool Client::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(ID);
    QString tel_string= QString::number(Tel);
    QString CIN_string= QString::number(CIN);
          query.prepare("INSERT INTO CLIENT (ID,CIN,Tel,nom,prenom,Addresse,statut) "
                        "VALUES (:ID, :CIN, :TEL, :NOM, :PRENOM, :ADDRESSE, :STATUT )");
          query.bindValue(":ID", id_string);
          query.bindValue(":CIN", CIN_string);
          query.bindValue(":TEL", tel_string);
          query.bindValue(":NOM", nom);
          query.bindValue(":PRENOM", prenom);
          query.bindValue(":ADDRESSE", Adresse);
          query.bindValue(":STATUT", statut);






    return query.exec();

}

QSqlQueryModel* Client::afficher()
{
QSqlQueryModel *model= new QSqlQueryModel();


      model->setQuery("SELECT  * FROM CLIENT");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("L'id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num Cin"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Telephone"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Le nom"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Le prenom"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("L'adresse"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("Le statut"));

      return model ;
}

bool Client::supprimer(int CIIN)
{
    QSqlQuery query;

          query.prepare("Delete from client where cin=:CIN");
          query.bindValue(":CIN", CIIN);

                  return  query.exec();
}


bool Client::modifier(int ID)
{
    QSqlQuery query;

   QString res1= QString::number(CIN);
   QString res2= QString::number(Tel);
   QString res3= QString::number(ID);


   /*int id=ui->ID_MOD->text().toInt();
   QString nom= ui->NOM_MOD->text();
   QString prenom= ui->PRENOM_MOD->text();
   QString Adresse= ui->ADRESSE_MOD->text();
   QString statut = ui->STATUT_MOD->currentText();
   int Tel = ui->TEL_MOD->text().toInt();
   int CIN = ui->CIN_MOD->text().toInt();*/


    //requette sql
    query.prepare("UPDATE CLIENT set  CIN=:CIN, TEL=:TEL, NOM=:NOM,PRENOM=:PRENOM ,ADDRESSE=:ADRESSE where id=:ID");

    //saisir de donnee
    query.bindValue(":ID",res3);
    query.bindValue(":CIN",res1);
    query.bindValue(":TEL",res2);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":ADDRESSE",Adresse);
    query.bindValue(":STATUT",statut);


    //execution de la requetteNU
    return query.exec();
}



QSqlQueryModel* Client::recherche(QString val)
{

    QSqlQueryModel* model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM CLIENT where ID LIKE '" +val+"' ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN "));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADDRESSE"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUT"));

    return model;
}


QSqlQueryModel* Client::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT*FROM CLIENT order by ID ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("L'id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num Cin"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Le nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Le prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("L'adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Le statut"));
    return model;

}



QSqlQueryModel* Client::tri_nom()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT*FROM CLIENT order by NOM ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("L'id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num Cin"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Le nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Le prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("L'adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Le statut"));
    return model;

}





