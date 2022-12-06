#ifndef MISSION_H
#define MISSION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class Mission
{
public:
    Mission();
    Mission(int ID,int NBR_DE_PERSONES,float BUDGET, QString DATE_DEBUT_M, QString DATE_FIN_M,QString DESTINATION,QString TYPE_DE_MISSION);
    int getID();
    QString getDATE_DEBUT_M();
    QString getDATE_FIN_M();
    QString getDESTINATION();
    QString getTYPE_DE_MISSION();
    int getETAT();
    float getBUDGET();
    int getNBR_DE_PERSONES();
    void setID(int);
    void setETAT(int);
    void setDATE_DEBUT_M( QString);
    void setDATE_FIN_M( QString);
    void setDESTINATION(QString);
    void setTYPE_DE_MISSION(QString);
    void setBUDGET(float);
    void setNBR_DE_PERSONES(int);
    // verfication
    bool Verif_id();
    bool Verif_budget();
    bool Verif_type();
    bool Verif_nbr();
    bool Verif_destination();
    bool Verif_dateD();
    bool Verif_dateF();

    //fonctionnalites de base relatives a l'entite mission
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);

      QSqlQueryModel * rechercherID(QString);
      QSqlQueryModel * rechercherType(QString);
      QSqlQueryModel * rechercherNBP(QString);
      QSqlQueryModel *  triID();
      QSqlQueryModel *  triNBP();
      QSqlQueryModel *  triBUD();
      QSqlQueryModel * recherche_DATED(QDate val);
      QSqlQueryModel * recherche_DATEF(QDate val);




private:
      int ID;
      int NBR_DE_PERSONES;
      float BUDGET;
      QString DATE_DEBUT_M;
      QString DATE_FIN_M;
      QString DESTINATION;
      QString TYPE_DE_MISSION;
      int ETAT;





};

#endif // MISSION_H
