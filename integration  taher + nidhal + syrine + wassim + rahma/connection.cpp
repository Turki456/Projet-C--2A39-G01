#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
<<<<<<< HEAD:connection.cpp
db.setDatabaseName("test_bd");
db.setUserName("wassim");
db.setPassword("wassim");
=======
db.setDatabaseName("agence");
db.setUserName("taher");
db.setPassword("taher");
>>>>>>> 279b53c37b357bc694b3239812a2b7ebc148bca2:integration  taher + nidhal + syrine + wassim + rahma/connection.cpp

if (db.open())
test=true;

    return  test;
}
void Connection::closeConnection()
{
    db.close();
}
