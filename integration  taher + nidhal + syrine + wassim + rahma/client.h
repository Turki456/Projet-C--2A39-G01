#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>






class Client
{
    QString nom, prenom , Adresse , statut ;
    int ID, Tel , CIN ;
public:
    //constructeurs
    Client();
    Client (int,int,int,QString,QString,QString,QString);
    Client (int,int,QString,QString,QString,QString);
    //Getters
    QString getnom(){return nom ;}
    QString getprenom(){return prenom ;}
    QString getAdresse(){return Adresse ;}
    int getID(){return ID ;}
    int getCIN(){return CIN; }
    int getTel(){return Tel ;}


    //Setters
    void setnom(QString n){ nom = n ;}
    void setprenom (QString p){ prenom = p ;}
    void setAdresse(QString A){ Adresse = A ;}
    void setID(int ID){this-> ID=ID ;}
    void setCIN(int CIN){this-> CIN=CIN ;}
    void setTel(int Tel){this-> Tel=Tel ;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int) ;
    bool modifier (int id);
    bool getClientByID(int id);
    QSqlQueryModel* tri();
    QSqlQueryModel* tri_nom();
    QSqlQueryModel* recherche(QString val);

    QString returnName(QString cin);





};

#endif // CLIENT_H
