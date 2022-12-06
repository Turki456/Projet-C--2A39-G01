#include "employe.h"
#include<QString>
#include<QSqlQuery>
#include<QtDebug>
Employe::Employe()
{
    ID_E = 0;
    salaire_E = 0;
    nom_E =" ";
    prenom_E =" ";
    poste_E =" ";
    mail_E =" ";
    sexe_E="";
    pwd="";
    admin="";
}
Employe::Employe(int ID_E,QString nom_E,QString prenom_E,QString poste_E,float salaire_E,QString mail_E,QString sexe_E,QString pwd,QString admin)
{
    this->ID_E = ID_E;
    this->nom_E = nom_E;
    this->prenom_E = prenom_E;
    this->poste_E = poste_E;
    this->salaire_E = salaire_E;
    this->mail_E = mail_E;
    this->sexe_E = sexe_E;
    this->pwd = pwd;
    this->admin = admin;
}
bool Employe::ajouter()
{
    QSqlQuery query;

    QString ID_string = QString::number(ID_E);
    QString salaire_string= QString::number(salaire_E);

    query.prepare("INSERT INTO Employe(ID_E,nom_E,poste,salaire,mail_E,prenom_E,sexe_E,password,admin)"
                  "VALUES (:ID,:nom,:poste,:salaire,:mail,:prenom,:sexe,:password,:admin)");
    query.bindValue(":ID",ID_string);
    query.bindValue(":nom",nom_E);
    query.bindValue(":poste",poste_E);
    query.bindValue(":salaire",salaire_string);
    query.bindValue(":mail",mail_E);
    query.bindValue(":prenom",prenom_E);
    query.bindValue(":sexe",sexe_E);
    query.bindValue(":password",pwd);
    query.bindValue(":admin",admin);

    return query.exec();
}
bool Employe::supprimer(int val)
{
    QSqlQuery query;
    QString val_string = QString::number(val);

    query.prepare("DELETE FROM Employe where ID_E=:val"); //:val is another placeholder
    query.bindValue(":val",val_string);
    return query.exec();
}
QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    /*model->setQuery("SELECT * FROM Employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Password"));*/

    model->setQuery("SELECT ID_E, nom_E, prenom_E, sexe_E, poste, salaire, mail_E FROM Employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("E-mail"));
    //model->setHeaderData(7,Qt::Horizontal,QObject::tr("Password"));

    return model;
}
bool Employe::verif_ID()
{
    if (ID_E==0)
     return true;
 else return false;
}
bool Employe::verif_salaire()
{
    if (salaire_E==0)
     return true;
 else return false;
}
bool Employe::verif_nom()
{
    return nom_E.isEmpty();
}
bool Employe::verif_prenom()
{
    return prenom_E.isEmpty();
}
bool Employe::verif_mail()
{
    if(mail_E.contains("@",Qt::CaseInsensitive)==false)
           return true;
        else return false;
}
bool Employe::verif_erreur()
{
    if(verif_ID() or verif_nom() or verif_prenom() or verif_mail() or verif_salaire())

        return true; //il y'a une erreur
}
int Employe::search_login_admin(QString username, QString pwd)
{
    QSqlQuery query;
    int res=0;
    QString admin_value = "OUI";
    if(query.exec("SELECT * FROM Employe where ID_E like '"+username+"' and password like'"+pwd+"' and admin like'"+admin_value+"'"))
    {
        int count=0;
        while(query.next())
        {
            count++;
        }
        if(count==1)
            res = 1;
        if(count<1)
            res = -1;
    }
    return res;
}
int Employe::search_login_employe(QString username, QString pwd)
{
    QSqlQuery query;
    int res=0;
    if(query.exec("SELECT * FROM Employe where ID_E like '"+username+"' and password like'"+pwd+"'"))
    {
        int count=0;
        while(query.next())
        {
            count++;
        }
        if(count==1)
            res = 1;
        if(count<1)
            res = -1;
    }
    return res;

}
int Employe::search_employe(QString ID)
{
    QSqlQuery query;
    int res=0;
    if(query.exec("SELECT * FROM Employe where ID_E like '"+ID+"'"))
    {
        int count=0;
        while(query.next())
        {
            count++;
        }
        if(count==1)
            res = 1;
        if(count<1)
            res = -1;
    }
    return res;

}
QSqlQueryModel * Employe::searchName(QString search)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID_E, nom_E, prenom_E, sexe_E, poste, salaire, mail_E FROM Employe where nom_E LIKE '"+search+"%'  OR LOWER(nom_E) LIKE '"+search+"%' OR UPPER(nom_E) LIKE '"+search+"%'"
                    "or ID_E LIKE '"+search+"%'  OR LOWER(ID_E) LIKE '"+search+"%' OR UPPER(ID_E) LIKE '"+search+"%'"
                    "or poste LIKE '"+search+"%'  OR LOWER(poste) LIKE '"+search+"%' OR UPPER(poste) LIKE '"+search+"%'"
                    "or prenom_E LIKE '"+search+"%'  OR LOWER(prenom_E) LIKE '"+search+"%' OR UPPER(prenom_E) LIKE '"+search+"%'"
                    "or sexe_E LIKE '"+search+"%'  OR LOWER(sexe_E) LIKE '"+search+"%' OR UPPER(sexe_E) LIKE '"+search+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("E-mail"));
    return model;
}
QSqlQueryModel * Employe::TriASC()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID_E, nom_E, prenom_E, sexe_E, poste, salaire, mail_E FROM Employe order by UPPER(nom_E) ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("E-mail"));
    return model;
}
QSqlQueryModel * Employe::TriDESC()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID_E, nom_E, prenom_E, sexe_E, poste, salaire, mail_E FROM Employe order by UPPER(nom_E) DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("E-mail"));
    return model;
}
QSqlQueryModel * Employe::TriSalaire_Alpha()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID_E, nom_E, prenom_E, sexe_E, poste, salaire, mail_E FROM Employe order by salaire ASC, UPPER(nom_E) ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("E-mail"));
    return model;
}
QSqlQueryModel * Employe::TriID()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID_E, nom_E, prenom_E, sexe_E, poste, salaire, mail_E FROM Employe order by ID_E ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("E-mail"));
    return model;
}












