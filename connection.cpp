#include "connection.h"

Connection::Connection(){}

bool Connection::createconnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Syrine");//inserer nom de l'utilisateur
db.setPassword("SyrineJAZI");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;

     return  test;
}
void Connection::closeconnection(){db.close();}
