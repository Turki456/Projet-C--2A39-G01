#include "connexion.h"


Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("BD");
db.setUserName("rahma");//inserer nom de l'utilisateur
db.setPassword("rahma");//inserer mot de passe de cet utilisateur

if (db.open())   
test=true;





    return  test;
}
