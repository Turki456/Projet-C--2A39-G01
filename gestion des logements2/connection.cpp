#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("agence");
db.setUserName("warrior");
db.setPassword("warrior");

if (db.open())
test=true;

    return  test;
}
void Connection::closeConnection()
{
    db.close();
}
