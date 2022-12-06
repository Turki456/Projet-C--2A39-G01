#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString,float,QString,QString,QString,QString);
    void setID_E(int val){ID_E = val;}
    void setsalaire_E(float val){salaire_E = val;}
    void setnom_E(QString val){nom_E = val;}
    void setprenom_E(QString val){prenom_E = val;}
    void setposte_E(QString val){poste_E = val;}
    void setmail_E(QString val){mail_E = val;}
    void setsexe_E(QString val){sexe_E = val;}
    void setpwd(QString val){pwd = val;}
    void setadmin(QString val){admin = val;}


    int getID_E(){return ID_E;}
    float getsalaire_E(){return salaire_E;}
    QString getnom_E(){return nom_E;}
    QString getprenom_E(){return prenom_E;}
    QString getposte_E(){return poste_E;}
    QString getmail_E(){return mail_E;}
    QString getpwd(){return pwd;}
    QString getadmin(){return admin;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool verif_ID();
    bool verif_nom();
    bool verif_prenom();
    bool verif_salaire();
    bool verif_mail();
    bool verif_erreur();
    bool verif_admin();
    int search_login_admin(QString username,QString pwd);
    int search_login_employe(QString username,QString pwd);
    int search_employe(QString ID);

    QSqlQueryModel * searchName(QString search);
    QSqlQueryModel * TriASC();
    QSqlQueryModel * TriDESC();
    QSqlQueryModel * TriSalaire_Alpha();
    QSqlQueryModel * TriID();




private:
        int ID_E;
        QString nom_E;
        QString prenom_E;
        QString poste_E;
        float salaire_E;
        QString mail_E;
        QString sexe_E;
        QString pwd;
        QString admin;

};

#endif // EMPLOYE_H
