#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "admindialog.h"
#include "ui_admindialog.h"

#include"todolist.h"
#include<QMessageBox>

Dialoglogin::Dialoglogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoglogin)
{

    ui->setupUi(this);

}

Dialoglogin::~Dialoglogin()
{
    delete ui;
}

void Dialoglogin::on_confirmButton_clicked()
{
    Dialoglogin l;
    AdminDialog *crudAdmin;
    MainWindow *crudEmploye;

    Employe E;
    crudAdmin = new AdminDialog();
    crudEmploye = new MainWindow();

    QString ID = ui->username_le->text();
    QString pwd = ui->password_le->text();

    if(E.search_login_admin(ID,pwd)==1)
    {
        crudAdmin->show();
        this->close();
    }
    else
    {
      if(E.search_login_employe(ID,pwd) == 1)
        {
          /*
              TodoList *app;
              app = new TodoList();
              app->show();
              this->close();
          */
          crudEmploye->show();
          this->close();
        }
      else
          QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("ACCES IMPOSSIBLE"), QMessageBox::Cancel);
    }




}

