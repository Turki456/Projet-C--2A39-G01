#include "Partenaire.h"

Partenaire::Partenaire()
{
    _id="";
    _nom="";
    _type="";
    _mail="";
    _numtel="";
    _dureecontrat="";
    _remise="";

}

void Partenaire::set_id(QString n)
{
    _id=n;
}
void Partenaire::set_nom(QString n)
{
    _nom=n;
}
void Partenaire::set_type(QString n)
{
    _type=n;
}
void Partenaire::set_mail(QString n)
{
    _mail=n;
}
void Partenaire::set_numtel(QString n)
{
    _numtel=n;
}
void Partenaire::set_dureecontrat(QString n)
{
    _dureecontrat=n;
}
void Partenaire::set_remise(QString n)
{
    _remise=n;
}

QString Partenaire::get_id()
{
    return _id;
}
QString Partenaire::get_nom()
{
    return _nom;
}
QString Partenaire::get_type()
{
    return _type;
}
QString Partenaire::get_mail()
{
    return _mail;
}
QString Partenaire::get_numtel()
{
    return _numtel;
}
QString Partenaire::get_dureecontrat()
{
    return _dureecontrat;
}
QString Partenaire::get_remise()
{
    return _remise;
}
bool Partenaire::ajouter(Partenaire p)
{
  QSqlQuery query;
  query.prepare("INSERT INTO PARTENAIRE (ID, NOM, TYPE, NUMTEL, MAIL, DUREECONTRAT, REMISE) VALUES (:ID, :NOM, :TYPE, :NUMTEL, :MAIL, :DUREECONTRAT, :REMISE)");
  query.bindValue(":ID",p.get_id());
  query.bindValue(":NOM",p.get_nom());
  query.bindValue(":TYPE",p.get_type());
  query.bindValue(":NUMTEL",p.get_numtel());
  query.bindValue(":MAIL",p.get_mail());
  query.bindValue(":DUREECONTRAT",p.get_dureecontrat());
  query.bindValue(":REMISE",p.get_remise());
  return query.exec();

}
bool Partenaire::supprimer(int id)
{
  QSqlQuery query ;
  QString res = QString::number(id);
  query.prepare("delete from PARTENAIRE where ID= :ID");
  query.bindValue(":ID",res);
  return query.exec();

}

QSqlQueryModel * Partenaire::afficher()
{
 QSqlQueryModel * model = new QSqlQueryModel();
 model->setQuery("select * from PARTENAIRE ");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumTel"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("Dureecontrat"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("Remise"));
 return model;
}

QSqlQueryModel * Partenaire::trierref()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PARTENAIRE order by Remise ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumTel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Dureecontrat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Remise"));
    return model;
}

QSqlQueryModel * Partenaire::triercroissant()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PARTENAIRE order by ID ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumTel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Dureecontrat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Remise"));
    return model;
}

QSqlQueryModel * Partenaire::trierdecroissant()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PARTENAIRE order by ID DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumTel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Dureecontrat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Remise"));
    return model;
}




bool Partenaire::modifier(Partenaire p)
{
  QSqlQuery query;
  query.prepare("update PARTENAIRE set NOM= :NOM, TYPE= :TYPE, NUMTEL= :NUMTEL, MAIL= :MAIL, DUREECONTRAT= :DUREECONTRAT, REMISE= :REMISE where ID= :ID");
  query.bindValue(":ID",p.get_id());
  query.bindValue(":NOM",p.get_nom());
  query.bindValue(":TYPE",p.get_type());
  query.bindValue(":NUMTEL",p.get_numtel());
  query.bindValue(":MAIL",p.get_mail());
  query.bindValue(":DUREECONTRAT",p.get_dureecontrat());
  query.bindValue(":REMISE",p.get_remise());
  return query.exec();

}
QSqlQueryModel * Partenaire::Rechercher_ID(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from PARTENAIRE where ID = :ID");
    query.bindValue(":ID",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumTel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Dureecontrat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Remise"));
    return model;
}

QSqlQueryModel * Partenaire::Rechercher_NOM(QString nom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from PARTENAIRE where NOM = :NOM");
    query.bindValue(":NOM",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumTel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Dureecontrat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Remise"));
    return model;
}

QSqlQueryModel * Partenaire::Rechercher_TYPE(QString type)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from PARTENAIRE where TYPE = :TYPE");
    query.bindValue(":TYPE",type);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumTel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Dureecontrat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Remise"));
    return model;
}
QSqlQueryModel * Partenaire::besthotel()
{
 QSqlQueryModel * model = new QSqlQueryModel();
 model->setQuery("SELECT * from OFFRES ");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_PARTENAIRE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Remise"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
 return model;
}



