#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
//test commentaire
class Connection
{
    private:
        QSqlDatabase db;
    public:
    Connection();
    bool createconnection();
    void closeconnection();

};

#endif // CONNECTION_H
