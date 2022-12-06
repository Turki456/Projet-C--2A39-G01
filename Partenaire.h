#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
#include<qmessagebox.h>


class Partenaire
{
private:
    QString _id, _nom, _type, _mail, _numtel, _dureecontrat, _remise;

public:
    Partenaire();
    void set_id(QString n);
    void set_nom(QString n);
    void set_type(QString n);
    void set_mail(QString n);
    void set_numtel(QString n);
    void set_dureecontrat(QString n);
    void set_remise(QString n);

    QString get_id();
    QString get_nom();
    QString get_type();
    QString get_mail();
    QString get_numtel();
    QString get_dureecontrat();
    QString get_remise();

    bool ajouter(Partenaire p);
    bool supprimer(int id);
    QSqlQueryModel * afficher();
    QSqlQueryModel * trierref();
    QSqlQueryModel * triercroissant();
    QSqlQueryModel * trierdecroissant();

    bool modifier(Partenaire p);
    QSqlQueryModel * Rechercher_ID(int id);
    QSqlQueryModel * Rechercher_TYPE(QString type);
    QSqlQueryModel * Rechercher_NOM(QString nom);

    QSqlQueryModel * besthotel();
};

#endif // PARTENAIRE_H
