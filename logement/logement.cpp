#include "logement.h"

logement::logement()
{
    ID_L=0;
    TYPE_L="";
    PRIX_L=0;
     ADRESSE_L="";
    MAIL_L="";
    NUM_TEL_L=0;
}
logement::logement(int id ,QString type,int prix,QString adresse,QString email,int tel)
{

   this->ID_L=id;
   this->TYPE_L=type;
   this->PRIX_L=prix;
    this->ADRESSE_L=adresse;
   this->MAIL_L=email;
   this->NUM_TEL_L=tel;
 }

int logement::get_id(){return ID_L;}
int logement::get_prix(){return PRIX_L;}
QString logement::get_type(){return TYPE_L;}
QString logement::get_ads(){return ADRESSE_L;}
QString logement::get_email(){return MAIL_L ;}
int logement::get_tel(){return NUM_TEL_L;}

void logement::set_id(int i){ID_L=i;}
void logement::set_prix(int m){PRIX_L=m;}
void logement::set_type(QString t){TYPE_L=t;}
void logement::set_ads(QString a){ADRESSE_L=a;}
void logement::set_email(QString ma){MAIL_L=ma;}
void logement::set_tel(int d){NUM_TEL_L=d;}

bool logement::Verif_id()
{
    if (ID_L==0)
     return true;
 else return false;
}
bool logement::Verif_prix()
{
    if (PRIX_L==0)
     return true;
 else return false;
}
bool logement::Verif_type()
{
    return TYPE_L.isEmpty();
}
bool logement::Verif_ads()
{
    return ADRESSE_L.isEmpty();
}
bool logement::Verif_email()
{
    if (MAIL_L.contains("@",Qt::CaseInsensitive)==false)
       return true;
    else return false;
}
bool logement::Verif_tel()
{
    if (NUM_TEL_L==0)
     return true;
 else return false;
}





bool logement::ajouter()
{
   QSqlQuery Query;
   QString res= QString::number(ID_L);
   Query.prepare("insert into LOGEMENT (ID_L,TYPE_L,PRIX_L,ADRESSE_L,MAIL_L,NUM_TEL_L)" "values(:ID_L,:TYPE_L,:PRIX_L,:ADRESSE_L,:MAIL_L,:NUM_TEL_L)");
  Query.bindValue(":ID_L",res);
   Query.bindValue(":TYPE_L",TYPE_L);
    Query.bindValue(":PRIX_L",PRIX_L);
   Query.bindValue(":ADRESSE_L",ADRESSE_L);
   Query.bindValue(":MAIL_L",MAIL_L);
   Query.bindValue(":NUM_TEL_L",NUM_TEL_L);


   return Query.exec();
}

bool logement::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete from LOGEMENT WHERE ID_L=:ID_L");
    query.bindValue(":ID_L",id);
    return query.exec();
}
QSqlQueryModel * logement::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LOGEMENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
    return model;
}
bool logement::modifier(int id)
{
    QSqlQuery query;
       QString res=QString::number(id);

          query.prepare("UPDATE LOGEMENT set TYPE_L=:TYPE_L,PRIX_L=:PRIX_L,ADRESSE_L=:ADRESSE_L,MAIL_L=:MAIL_L,NUM_TEL_L=:NUM_TEL_L where ID_L=:ID_L");
          query.bindValue(":ID_L",res);
          query.bindValue(":TYPE_L",TYPE_L);
           query.bindValue(":PRIX_L",PRIX_L);
          query.bindValue(":ADRESSE_L",ADRESSE_L);
          query.bindValue(":MAIL_L",MAIL_L);
          query.bindValue(":NUM_TEL_L",NUM_TEL_L);
          return query.exec();
}
/*
bool Aff_juridique::modifier(int NUMAFF){
    QSqlQuery query;
   QString NUMAFF_string= QString::number(NUMAFF);

    //requette sql
    query.prepare("UPDATE Aff_juridique set TYPEAFF=:TYPEAFF,DATEAFF=:DATEAFF where NUMAFF=:NUMAFF");

    //saisir de donnee
    query.bindValue(":NUMAFF",NUMAFF_string);
    query.bindValue(":TYPEAFF",TYPEAFF);
    query.bindValue(":DATEAFF",DATEAFF);

    //execution de la requetteNU
    return query.exec();
}
*/
QSqlQueryModel* logement::rechercherType(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM LOGEMENT where TYPE_L LIKE '"+recherche+"%'  OR LOWER(TYPE_L) LIKE '"+recherche+"%' OR UPPER(TYPE_L) LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
    return model;
}
QSqlQueryModel* logement::rechercherID(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM LOGEMENT where ID_L LIKE '"+recherche+"%'  OR LOWER(ID_L) LIKE '"+recherche+"%' OR UPPER(ID_L) LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
    return model;
}

