#ifndef LOGEMENT_H
#define LOGEMENT_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>

class logement
{
    int ID_L;
    QString TYPE_L;
     int  PRIX_L;
    QString   ADRESSE_L ;
    QString    MAIL_L;
     int      NUM_TEL_L;
 ;
public:
    logement();
    logement(int,QString,int,QString,QString,int);

    int get_id();
    int get_prix();
    QString get_type();
    QString get_ads();
    QString get_email();
    int get_tel();

    void set_id(int);
    void set_prix(int);
    void set_type(QString);
    void set_ads(QString);
    void set_email(QString);
    void set_tel(int);

    bool Verif_id();
    bool Verif_prix();
    bool Verif_type();
    bool Verif_ads();
 bool Verif_email();
  bool Verif_tel();
   bool  controlTel(int tel);
   QSqlQueryModel* getAllId();



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
  QSqlQueryModel * rechercherType(QString);
  QSqlQueryModel * rechercherID(QString);
  QSqlQueryModel * Trier_PRIX_A();
  QSqlQueryModel * Trier_PRIX_D();
  QSqlQueryModel * Trier_ID_A();
   QSqlQueryModel * Trier_ID_D();
  QSqlQueryModel * Trier_adresse_A();
   QSqlQueryModel * Trier_adresse_D();
   QSqlQueryModel * Trier_Hotel_PRIX_A();
   QSqlQueryModel * Trier_Hotel_PRIX_D();
   QSqlQueryModel * Trier_Hotel_ID_A();
    QSqlQueryModel * Trier_Hotel_ID_D();
   QSqlQueryModel * Trier_Hotel_adresse_A();
    QSqlQueryModel * Trier_Hotel_adresse_D();
    QSqlQueryModel * Trier_Maison_PRIX_A();
    QSqlQueryModel * Trier_Maison_PRIX_D();
    QSqlQueryModel * Trier_Maison_ID_A();
     QSqlQueryModel * Trier_Maison_ID_D();
    QSqlQueryModel * Trier_Maison_adresse_A();
     QSqlQueryModel * Trier_Maison_adresse_D();
     QSqlQueryModel * Trier_Appartement_PRIX_A();
     QSqlQueryModel * Trier_Appartement_PRIX_D();
     QSqlQueryModel * Trier_Appartement_ID_A();
      QSqlQueryModel * Trier_Appartement_ID_D();
     QSqlQueryModel * Trier_Appartement_adresse_A();
      QSqlQueryModel * Trier_Appartement_adresse_D();



};
#endif // LOGEMENT_H
