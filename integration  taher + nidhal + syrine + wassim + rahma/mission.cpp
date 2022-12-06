#include "mission.h"
#include<QSqlQuery>
#include<QDebug>
#include <QSqlQueryModel>
#include <QObject>

Mission::Mission()
{
ID=0;
NBR_DE_PERSONES=0;
BUDGET=0;
 DATE_DEBUT_M="";
 DATE_FIN_M="";
 DESTINATION="";
 TYPE_DE_MISSION="";


}

Mission::Mission( int ID,int NBR_DE_PERSONES,float BUDGET, QString DATE_DEBUT_M, QString DATE_FIN_M,QString DESTINATION,QString TYPE_DE_MISSION)
{
    this->ID=ID;
    this->NBR_DE_PERSONES=NBR_DE_PERSONES;
    this->BUDGET=BUDGET;
    this->DATE_DEBUT_M=DATE_DEBUT_M;
    this->DATE_FIN_M=DATE_FIN_M;
    this->DESTINATION=DESTINATION;
    this->TYPE_DE_MISSION=TYPE_DE_MISSION;
   // this->ETAT=ETAT;

}
int Mission::getID(){return  ID;}
int Mission::getETAT(){return  ETAT;}
 QString Mission::getDATE_DEBUT_M(){return DATE_DEBUT_M;}
QString Mission::getTYPE_DE_MISSION(){return TYPE_DE_MISSION;}
 QString Mission::getDATE_FIN_M(){return DATE_FIN_M;}
QString Mission::getDESTINATION(){return DESTINATION;}
float Mission::getBUDGET(){return  BUDGET;}
int Mission::getNBR_DE_PERSONES(){return NBR_DE_PERSONES;}
void Mission:: setID(int ID){this->ID=ID;}
void Mission:: setETAT(int ETAT){this->ETAT=ETAT;}
void Mission::setTYPE_DE_MISSION(QString TYPE_DE_MISSION){this->TYPE_DE_MISSION=TYPE_DE_MISSION;}
void Mission::setDATE_DEBUT_M( QString DATE_DEBUT_M){this->DATE_DEBUT_M=DATE_DEBUT_M;}
void Mission::setDATE_FIN_M( QString DATE_FIN_M){this->DATE_FIN_M=DATE_FIN_M;}
void Mission::setDESTINATION(QString DESTINATION){this->DESTINATION=DESTINATION;}
void Mission::setBUDGET(float BUDGET){this->BUDGET=BUDGET;}
void Mission::setNBR_DE_PERSONES(int NBR_DE_PERSONES){this->NBR_DE_PERSONES=NBR_DE_PERSONES;}
bool Mission::Verif_id()
{
    if (ID==0)
     return true;
 else return false;
}
bool Mission::Verif_budget()
{
    if (BUDGET==0)
     return true;
 else return false;
}
bool Mission::Verif_type()
{
    return TYPE_DE_MISSION.isEmpty();
}
bool Mission::Verif_nbr()
{
    if (NBR_DE_PERSONES==0)
     return true;
 else return false;
}
bool Mission::Verif_destination()
{
    return DESTINATION.isEmpty();
}

bool Mission::Verif_dateD()
{
    return DATE_DEBUT_M.isEmpty();
}
bool Mission::Verif_dateF()
{
    return DATE_FIN_M.isEmpty();
}
bool Mission::ajouter(){
    QSqlQuery query;
    QString ID_string=QString::number(ID);
     QString ETAT_string=QString::number(ETAT);
    QString BUD_string=QString::number(BUDGET);
    QString NBR_string=QString::number(NBR_DE_PERSONES);

                              query.prepare("insert into MISSION (ID,DATE_DEBUT_M,NBR_DE_PERSONES,DESTINATION,BUDGET,DATE_FIN_M,TYPE_DE_MISSION,ETAT) "
                                            "values (:ID,:DATE_DEBUT_M,:NBR_DE_PERSONES,:DESTINATION,:BUDGET,:DATE_FIN_M,:TYPE_DE_MISSION,:ETAT)");
                              query.bindValue(":ID", ID_string);
                              query.bindValue(":DATE_DEBUT_M", DATE_DEBUT_M );
                              query.bindValue(":NBR_DE_PERSONES", NBR_string);
                              query.bindValue(":DESTINATION", DESTINATION);
                              query.bindValue(":BUDGET", BUD_string);
                              query.bindValue(":DATE_FIN_M", DATE_FIN_M);
                              query.bindValue(":TYPE_DE_MISSION", TYPE_DE_MISSION);
                              query.bindValue(":ETAT", ETAT_string);

                              return query.exec();  //retrun TRUE OR FALSE

}

bool Mission::supprimer(int ID)
{
   QSqlQuery query;
   query.prepare("Delete from Mission where ID=:ID");
   query.bindValue(0,ID);
           return  query.exec();
}


QSqlQueryModel *Mission::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("SELECT * FROM MISSION");//afficher la total de mon table
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
    //  model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE DEBUT DE MISSION"));









return model;
}
/*bool Mission::modifier(int IDR){
    QSqlQuery query;
    QString ID_string=QString::number(ID);
    QString BUD_string=QString::number(BUDGET);
    QString NBR_string=QString::number(NBR_DE_PERSONES);
    query.prepare("UPDATE mission SET ID=:ID,DATE_DEBUT_M=:DATE_DEBUT_M,NBR_DE_PERSONES=:NBR_DE_PERSONES,DESTINATION=:DESTINATION,BUDGET=:BUDGET,DATE_FIN_M=:DATE_FIN_M,TYPE_DE_MISSION=:TYPE_DE_MISSION WHERE ID=:RID");
    query.bindValue(":ID", ID_string);
    query.bindValue(":DATE_DEBUT_M", DATE_DEBUT_M );
    query.bindValue(":NBR_DE_PERSONES", NBR_string);
    query.bindValue(":DESTINATION", DESTINATION);
    query.bindValue(":BUDGET", BUD_string);
    query.bindValue(":DATE_FIN_M", DATE_FIN_M);
    query.bindValue(":TYPE_DE_MISSION", TYPE_DE_MISSION);
     query.bindValue(":RID", RID);

    return query.exec();  //retrun TRUE OR FALSE
}*/
bool Mission::modifier(int ID)
{
    QSqlQuery query;
       QString res=QString::number(ID);
         QString BUD_string=QString::number(BUDGET);
         QString NBR_string=QString::number(NBR_DE_PERSONES);

          query.prepare("UPDATE mission SET ID=:ID,DATE_DEBUT_M=:DATE_DEBUT_M,NBR_DE_PERSONES=:NBR_DE_PERSONES,DESTINATION=:DESTINATION,BUDGET=:BUDGET,DATE_FIN_M=:DATE_FIN_M,TYPE_DE_MISSION=:TYPE_DE_MISSION WHERE ID=:ID");
          query.bindValue(":ID",res);
           query.bindValue(":DATE_DEBUT_M", DATE_DEBUT_M );
           query.bindValue(":NBR_DE_PERSONES", NBR_string);
           query.bindValue(":DESTINATION", DESTINATION);
           query.bindValue(":BUDGET", BUD_string);
           query.bindValue(":DATE_FIN_M", DATE_FIN_M);
           query.bindValue(":TYPE_DE_MISSION", TYPE_DE_MISSION);
          return query.exec();
}
QSqlQueryModel* Mission::rechercherID(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM MISSION where ID LIKE '"+recherche+"%'  OR LOWER(ID) LIKE '"+recherche+"%' OR UPPER(ID) LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DEBUT_M"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NBR_DE_PERSONES"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("BUDGET"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_FIN_M"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("TYPE_DE_MISSION"));
    return model;
}
QSqlQueryModel* Mission::rechercherType(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM MISSION where TYPE_DE_MISSION LIKE '"+recherche+"%'  OR LOWER(TYPE_DE_MISSION) LIKE '"+recherche+"%' OR UPPER(TYPE_DE_MISSION) LIKE '"+recherche+"%'");
   /* model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DEBUT_M"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NBR_DE_PERSONES"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("BUDGET"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_FIN_M"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("TYPE_DE_MISSION"));*/
    return model;
}
QSqlQueryModel* Mission::rechercherNBP(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM MISSION where NBR_DE_PERSONES LIKE '"+recherche+"%'  OR LOWER(TYPE_DE_MISSION) LIKE '"+recherche+"%' OR UPPER(TYPE_DE_MISSION) LIKE '"+recherche+"%'");
   /* model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DEBUT_M"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NBR_DE_PERSONES"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("BUDGET"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_FIN_M"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("TYPE_DE_MISSION"));*/
    return model;
}

QSqlQueryModel * Mission::triID()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM MISSION order by ID");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DEBUT_M"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("NBR_DE_PERSONES"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("BUDGET"));
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_FIN_M"));
  model->setHeaderData(6,Qt::Horizontal,QObject::tr("TYPE_DE_MISSION"));
     return model;


}
QSqlQueryModel * Mission::triNBP()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM MISSION order by NBR_DE_PERSONES");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DEBUT_M"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("NBR_DE_PERSONES"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("BUDGET"));
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_FIN_M"));
  model->setHeaderData(6,Qt::Horizontal,QObject::tr("TYPE_DE_MISSION"));
     return model;


}
QSqlQueryModel * Mission::triBUD()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM MISSION order by BUDGET");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DEBUT_M"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("NBR_DE_PERSONES"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("BUDGET"));
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_FIN_M"));
  model->setHeaderData(6,Qt::Horizontal,QObject::tr("TYPE_DE_MISSION"));
     return model;


}
QSqlQueryModel * Mission::recherche_DATED(QDate val)
{
    QString vall=val.toString("dd.MM.yyyy").toUpper();
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from MISSION where DATE_DEBUT_M LIKE '"+vall+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("DATE_DEBUT_M"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("NBR_DE_PERSONES"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("BUDGET"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_FIN_M"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("TYPE_DE_MISSION"));


        return model;
}

QSqlQueryModel * Mission::recherche_DATEF(QDate val)
{
    QString vall=val.toString("dd.MM.yyyy").toUpper();
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from MISSION where DATE_FIN_M LIKE '"+vall+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DEBUT_M"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("NBR_DE_PERSONES"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("BUDGET"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_FIN_M"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("TYPE_DE_MISSION"));


        return model;
}



