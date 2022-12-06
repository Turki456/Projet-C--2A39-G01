#include "mainwindow.h"
#include "dialoglogin.h"
#include <QFile>
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    Dialoglogin l;
    if(test)
<<<<<<< HEAD:main.cpp
    {w.show();
        //l.show();
=======
    {//w.show();
        l.show();
>>>>>>> 279b53c37b357bc694b3239812a2b7ebc148bca2:integration  taher + nidhal + syrine + wassim + rahma/main.cpp
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
