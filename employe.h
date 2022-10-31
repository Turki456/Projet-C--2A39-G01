#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(int,int,float,QString,QString,QString,QString);

    int GetID(){return ID;}
    int GetCIN(){return CIN;}
    float Getsalaire(){return salaire;}
    QString Getnom(){return nom;}
    QString Getprenom(){return prenom;}
    QString Getposte(){return poste;}
    QString Getadresse(){return adresse;}

    void SetID(int val){ID = val;}
    void SetCIN(int val){CIN = val;}
    void Setsalaire(float val){salaire = val;}
    void Setnom(QString val){nom = val;}
    void Setprenom(QString val){prenom = val;}
    void Setposte(QString val){poste = val;}
    void Setadresse(QString val){adresse = val;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

private:
    int ID;
    int CIN;
    float salaire;
    QString nom;
    QString prenom;
    QString poste;
    QString adresse;



};

#endif // EMPLOYE_H
