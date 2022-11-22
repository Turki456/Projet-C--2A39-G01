#include"connection.h"

connection::connection(){}
bool connection::createconnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("new crud");
    db.setUserName("nidhal");
    db.setPassword("nidhal");
    if (db.open())
        test=true;
    return  test;

}
void connection::closeconnection(){db.close();}
