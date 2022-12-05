#include "logement.h"

logement::logement()
{
    ID_L=0;
    TYPE_L="";
    PRIX_L=0;
     ADRESSE_L="";
    MAIL_L="";
    NUM_TEL_L=0;
    ALERTE="";
}
logement::logement(int id ,QString type,int prix,QString adresse,QString email,int tel,QString alerte)
{

   this->ID_L=id;
   this->TYPE_L=type;
   this->PRIX_L=prix;
    this->ADRESSE_L=adresse;
   this->MAIL_L=email;
   this->NUM_TEL_L=tel;
    this->ALERTE=alerte;

 }

int logement::get_id(){return ID_L;}
int logement::get_prix(){return PRIX_L;}
QString logement::get_type(){return TYPE_L;}
QString logement::get_ads(){return ADRESSE_L;}
QString logement::get_email(){return MAIL_L ;}
int logement::get_tel(){return NUM_TEL_L;}
QString logement::get_alerte(){return ALERTE;}

void logement::set_id(int i){ID_L=i;}
void logement::set_prix(int m){PRIX_L=m;}
void logement::set_type(QString t){TYPE_L=t;}
void logement::set_ads(QString a){ADRESSE_L=a;}
void logement::set_email(QString ma){MAIL_L=ma;}
void logement::set_tel(int d){NUM_TEL_L=d;}
void logement::set_alerte(QString x){ALERTE=x;}


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
   Query.prepare("insert into LOGEMENT (ID_L,TYPE_L,PRIX_L,ADRESSE_L,MAIL_L,NUM_TEL_L,ALERTE)" "values(:ID_L,:TYPE_L,:PRIX_L,:ADRESSE_L,:MAIL_L,:NUM_TEL_L,:ALERTE)");
  Query.bindValue(":ID_L",res);
   Query.bindValue(":TYPE_L",TYPE_L);
    Query.bindValue(":PRIX_L",PRIX_L);
   Query.bindValue(":ADRESSE_L",ADRESSE_L);
   Query.bindValue(":MAIL_L",MAIL_L);
   Query.bindValue(":NUM_TEL_L",NUM_TEL_L);
   Query.bindValue(":ALERTE",ALERTE);


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
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
    return model;
}
bool logement::modifier(int id)
{
    QSqlQuery query;
       QString res=QString::number(id);

          query.prepare("UPDATE LOGEMENT set TYPE_L=:TYPE_L,PRIX_L=:PRIX_L,ADRESSE_L=:ADRESSE_L,MAIL_L=:MAIL_L,NUM_TEL_L=:NUM_TEL_L,ALERTE=:ALERTE where ID_L=:ID_L");
          query.bindValue(":ID_L",res);
          query.bindValue(":TYPE_L",TYPE_L);
           query.bindValue(":PRIX_L",PRIX_L);
          query.bindValue(":ADRESSE_L",ADRESSE_L);
          query.bindValue(":MAIL_L",MAIL_L);
          query.bindValue(":NUM_TEL_L",NUM_TEL_L);
          query.bindValue(":ALERTE",ALERTE);
          return query.exec();
}
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
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
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
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
    return model;
}
 QSqlQueryModel * logement::rechercheAdresse(QString recherche)
 {
     QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT * FROM LOGEMENT where ADRESSE_L LIKE '"+recherche+"%'  OR LOWER(ADRESSE_L) LIKE '"+recherche+"%' OR UPPER(ADRESSE_L) LIKE '"+recherche+"%'");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;

 }
QSqlQueryModel * logement::Trier_PRIX_D()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LOGEMENT ORDER BY PRIX_L DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
    return model;
}
QSqlQueryModel * logement::Trier_PRIX_A()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LOGEMENT ORDER BY PRIX_L ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
    return model;
}

QSqlQueryModel * logement::Trier_ID_D()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LOGEMENT ORDER BY ID_L DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
    return model;
}
QSqlQueryModel * logement::Trier_ID_A()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LOGEMENT ORDER BY ID_L ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
    return model;
}

QSqlQueryModel * logement::Trier_adresse_A()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LOGEMENT ORDER BY ADRESSE_L ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
    return model;
}
QSqlQueryModel * logement::Trier_adresse_D()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LOGEMENT ORDER BY ADRESSE_L DESC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
    return model;
}
QSqlQueryModel* logement::getAllId()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT ID_L FROM LOGEMENT");

    return model;
}
 bool  logement::controlTel(int tel)
 {
     QString num= QString::number(tel);
         for(int i=0;i<num.length();i++)
         {
             if (num.length()==8)
             {
                 return false;
             }
         }
         return true;
 }
 QSqlQueryModel * logement::Trier_Hotel_PRIX_D()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT where TYPE_L='Hotel' or TYPE_L='HOTEL' or TYPE_L='hotel' ORDER BY PRIX_L DESC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 QSqlQueryModel * logement::Trier_Hotel_PRIX_A()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT where TYPE_L='Hotel' or TYPE_L='HOTEL' or TYPE_L='hotel' ORDER BY PRIX_L ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }

 QSqlQueryModel * logement::Trier_Hotel_ID_D()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Hotel' or TYPE_L='HOTEL' or TYPE_L='hotel' ORDER BY ID_L DESC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 QSqlQueryModel * logement::Trier_Hotel_ID_A()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT where TYPE_L='Hotel' or TYPE_L='HOTEL' or TYPE_L='hotel'  ORDER BY ID_L ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }

 QSqlQueryModel * logement::Trier_Hotel_adresse_A()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Hotel' or TYPE_L='HOTEL' or TYPE_L='hotel' ORDER BY ADRESSE_L ASC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 QSqlQueryModel * logement::Trier_Hotel_adresse_D()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Hotel' or TYPE_L='HOTEL' or TYPE_L='hotel' ORDER BY ADRESSE_L DESC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }

 QSqlQueryModel * logement::Trier_Maison_PRIX_D()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Maison' or TYPE_L='MAISON' or TYPE_L='maison' ORDER BY PRIX_L DESC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 QSqlQueryModel * logement::Trier_Maison_PRIX_A()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT where TYPE_L='Maison' or TYPE_L='MAISON' or TYPE_L='maison' ORDER BY PRIX_L ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }

 QSqlQueryModel * logement::Trier_Maison_ID_D()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Maison' or TYPE_L='MAISON' or TYPE_L='maison' ORDER BY ID_L DESC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 QSqlQueryModel * logement::Trier_Maison_ID_A()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT where TYPE_L='Maison' or TYPE_L='MAISON' or TYPE_L='maison'  ORDER BY ID_L ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }

 QSqlQueryModel * logement::Trier_Maison_adresse_A()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Maison' or TYPE_L='MAISON' or TYPE_L='maison' ORDER BY ADRESSE_L ASC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 QSqlQueryModel * logement::Trier_Maison_adresse_D()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Maison' or TYPE_L='MAISON' or TYPE_L='maison' ORDER BY ADRESSE_L DESC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 /*
 */
 QSqlQueryModel * logement::Trier_Appartement_PRIX_D()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Appartement' or TYPE_L='APPARTEMENT' or TYPE_L='appartement' ORDER BY PRIX_L DESC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 QSqlQueryModel * logement::Trier_Appartement_PRIX_A()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Appartement' or TYPE_L='APPARTEMENT' or TYPE_L='appartement' ORDER BY PRIX_L ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }

 QSqlQueryModel * logement::Trier_Appartement_ID_D()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Appartement' or TYPE_L='APPARTEMENT' or TYPE_L='appartement' ORDER BY ID_L DESC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 QSqlQueryModel * logement::Trier_Appartement_ID_A()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT where TYPE_L='Appartement' or TYPE_L='APPARTEMENT' or TYPE_L='appartement'  ORDER BY ID_L ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }

 QSqlQueryModel * logement::Trier_Appartement_adresse_A()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Appartement' or TYPE_L='APPARTEMENT' or TYPE_L='appartement' ORDER BY ADRESSE_L ASC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 QSqlQueryModel * logement::Trier_Appartement_adresse_D()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOGEMENT  where TYPE_L='Appartement' or TYPE_L='APPARTEMENT' or TYPE_L='appartement' ORDER BY ADRESSE_L DESC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_L"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_L"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_L"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_L"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL_L"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL_L"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("ALERTE"));
     return model;
 }
 /*
 QSqlQueryModel* logement::alerte()
 {


      QSqlQueryModel * model=new QSqlQueryModel();
      model->setQuery("SELECT alerte FROM alerte");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("alerte"));
     return model;
 }
*/




