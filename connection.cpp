#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test_bd");
db.setUserName("wassim");
db.setPassword("wassim");

if (db.open())
test=true;

    return  test;
}
void Connection::closeConnection()
{
    db.close();
}
