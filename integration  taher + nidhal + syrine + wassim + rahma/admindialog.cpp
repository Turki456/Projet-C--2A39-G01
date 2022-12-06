#include "admindialog.h"
#include "ui_admindialog.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "dialoglogin.h"
#include "statistique.h"
#include <QMessageBox>
#include<QComboBox>
#include <QApplication>
#include <QDate>
#include <QPrinter>
#include <QPrintDialog>
#include <QPixmap>
#include <QTextDocument>



AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
    ui->tableView_afficher->setModel(Etmp.afficher());
    ui->tableView_modifier->setModel(Etmp.afficher());
}

AdminDialog::~AdminDialog()
{
    delete ui;
}
void AdminDialog::on_pushButton_ajouterEmploye_clicked()
{

    int ID=ui->ID_le->text().toInt();
    QString nom=ui->nom_le->text();
    QString prenom=ui->prenom_le->text();
    QString mail=ui->mail_le->text();
    QString poste=ui->Poste_comboBox->currentText();
    float salaire=ui->salaire_le->text().toFloat();
    QString pwd=ui->pwd_le->text();
    QString sexe;
    QString admin;

    bool valid = true;

    //radio button of sexe
    if(ui->female_radiobutton->isChecked())
    {sexe = "Femme";}
    else if (ui->male_radiobutton->isChecked())
    {sexe = "Homme";}
    if(ui->checkBox->isChecked())
    {   admin = "OUI";  }
    else
        admin ="NON";


    Employe E(ID,nom,prenom,poste,salaire,mail,sexe,pwd,admin);

    if( E.verif_erreur() or ((!(ui->female_radiobutton->isChecked())) and !(ui->male_radiobutton->isChecked()))  )
    {
        if (E.verif_ID())
            {
                ui->ID_le->clear();
                ui->ID_le->setText("Champ obligatoire !");
            }
        if(E.verif_nom())
            {
                ui->nom_le->clear();
                ui->nom_le->setText("Champ obligatoire !");
            }
        if(E.verif_prenom())
            {
                ui->prenom_le->clear();
                ui->prenom_le->setText("Champ obligatoire !");
            }
        if(E.verif_salaire())
            {
                ui->salaire_le->clear();
                ui->salaire_le->setText("Champ obligatoire !");
            }
        if(E.verif_mail())
            {
                ui->mail_le->clear();
                ui->mail_le->setText("E-mail non valide !");
            }
        if ((!(ui->female_radiobutton->isChecked())) and (!(ui->male_radiobutton->isChecked())))
            {
                ui->warning_label->setText("Veuillez chooisir une option !");
            }


            valid = false;
    }

    if(valid)
    {
    bool test = E.ajouter();

    if(test)
    {
        ui->tableView_afficher->setModel(Etmp.afficher());
        ui->tableView_modifier->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Ajout non effectué\n""Click Cancel to exit."), QMessageBox::Cancel);
    }

    ui->pwd_le->clear();
    ui->ID_le->clear();
    ui->salaire_le->clear();
    ui->nom_le->clear();
    ui->prenom_le->clear();
    ui->mail_le->clear();


}


void AdminDialog::on_pushButton_supprimerEmploye_clicked()
{

    int val_ID = ui->IDsupp_le->text().toInt();
    QString string_ID = ui->IDsupp_le->text();
    bool test = false;
    if(Etmp.search_employe(string_ID)==1)

    {test = Etmp.supprimer(val_ID);}



    if(test)
    {
        ui->tableView_afficher->setModel(Etmp.afficher());
        ui->tableView_modifier->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression effectué\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Suppression non effectué\n""Click Cancel to exit."), QMessageBox::Cancel);

 }





void AdminDialog::on_tableauCRUD_tabBarClicked(int index)
{
    ui->tableView_afficher->setModel(Etmp.afficher());
    ui->tableView_modifier->setModel(Etmp.afficher());
    ui->pwd_le_2->clear();
    ui->ID_le_2->clear();
    ui->salaire_le_2->clear();
    ui->nom_le_2->clear();
    ui->prenom_le_2->clear();
    ui->mail_le_2->clear();


    ui->pwd_le->clear();
    ui->ID_le->clear();
    ui->salaire_le->clear();
    ui->nom_le->clear();
    ui->prenom_le->clear();
    ui->mail_le->clear();
}

void AdminDialog::on_pushButton_modifier_clicked()
{
    QSqlQuery query;

    QString id=ui->ID_le_2->text();
    QString salaire=ui->salaire_le_2->text();
    QString nom=ui->nom_le_2->text();
    QString prenom=ui->prenom_le_2->text();
    QString poste=ui->Poste_comboBox_2->currentText();
    QString mail=ui->mail_le_2->text();
    QString pwd=ui->pwd_le_2->text();
    QString sexe;
    QString admin;

    if(ui->female_radiobutton_2->isChecked())
    {sexe = "Femme";}
    else if (ui->male_radiobutton_2->isChecked())
    {sexe = "Homme";}

    if(ui->checkBox_2->isChecked())
    {   admin = "OUI";  }
    else
        admin = "NON";


    if ((!(ui->female_radiobutton_2->isChecked())) and (!(ui->male_radiobutton_2->isChecked())))
        {
            QMessageBox::information(this,"Warning !","Veuillez cochez une option !");
        }


    query.prepare("update Employe set ID_E='"+id+"',salaire='"+salaire+"',nom_E='"+nom+"',prenom_E='"+prenom+"',poste='"+poste+"',mail_E='"+mail+"',sexe_E='"+sexe+"' ,password ='"+pwd+"' where ID_E='"+id+"'");
    if(query.exec())
    {
        ui->tableView_afficher->setModel(Etmp.afficher());
        ui->tableView_modifier->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Modification effectué\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Modification non effectué\n""Click Cancel to exit."), QMessageBox::Cancel);

    }


void AdminDialog::on_tableView_modifier_activated(const QModelIndex &index)
{
    QString val=ui->tableView_modifier->model()->data(index).toString();
    QSqlQuery query;

    query.prepare("select * from Employe where ID_E='"+val+"' or nom_E='"+val+"' or prenom_E='"+val+"' or poste='"+val+"' or salaire='"+val+"' or sexe_E='"+val+"' or mail_E='"+val+"'");
    if(query.exec())
    {
        while(query.next())
        {
            ui->ID_le_2->setText(query.value(0).toString());
            ui->nom_le_2->setText(query.value(1).toString());
            ui->prenom_le_2->setText(query.value(2).toString());
            ui->salaire_le_2->setText(query.value(5).toString());
            ui->mail_le_2->setText(query.value(6).toString());
            ui->pwd_le_2->setText(query.value(7).toString());
        }
    }
}

void AdminDialog::on_search_button_clicked()
{
    QString search=ui->search_le->text();
    if(search.length()!=0)
        ui->tableView_afficher->setModel(Etmp.searchName(search));
    else
    {
        ui->tableView_afficher->setModel(Etmp.afficher());
    }
}

void AdminDialog::on_reset_button_clicked()
{
    ui->search_le->clear();
    ui->tableView_afficher->setModel(Etmp.afficher());
}

void AdminDialog::on_tri_asc_clicked()
{

    if(ui->tri_comboBox->currentIndex() == 0)
    {ui->tableView_afficher->setModel(Etmp.TriID());}

    if(ui->tri_comboBox->currentIndex() == 1)
    {ui->tableView_afficher->setModel(Etmp.TriASC());}

    else if(ui->tri_comboBox->currentIndex() == 2)
    {ui->tableView_afficher->setModel(Etmp.TriSalaire_Alpha());}
}

void AdminDialog::on_pdf_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                       const int rowCount = ui->tableView_afficher->model()->rowCount();
                       const int columnCount = ui->tableView_afficher->model()->columnCount();

                       out <<"<html>\n"
                             "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           << "<title>LISTE EMPLOYES<title>\n "
                           << "</head>\n"
                           "<body bgcolor=#ffffff link=#5000A0>\n"
                           "<h1 style=\"text-align: center;\"><strong>Employees de l'agence""</strong></h1>"
                           "<table style=\"text-align: center; font-size: 20px;\" border=none>\n "
                           "</br> </br>";

                       // headers
                       out << "<thead><tr bgcolor=#78ccbf>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->tableView_afficher->isColumnHidden(column))
                           out << QString("<th>%1</th>").arg(ui->tableView_afficher->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";

                       // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView_afficher->isColumnHidden(column)) {
                                   QString data =ui->tableView_afficher->model()->data(ui->tableView_afficher->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<"</table>\n"
                           "</body>\n"
                           "</html>\n";

                       QTextDocument *document = new QTextDocument();
                       document->setHtml(strStream);

                       QPrinter printer;

                       QPrintDialog *test = new QPrintDialog(&printer, NULL);
                       if (test->exec() == QDialog::Accepted) {
                           document->print(&printer);
                       }

                       delete document;
}

void AdminDialog::on_stats_clicked()
{
      statistique * s;
      s = new statistique();

      if(ui->stat_comboBox->currentIndex() == 0)
      {
          s->setWindowTitle("Statistiques des employés");
          s->bar_stat();
          s->show();
      }
      else if(ui->stat_comboBox->currentIndex() == 1)
      {
          s->setWindowTitle("Stats du secteur IT");
          s->pie_chart();
          s->show();
      }
      else if(ui->stat_comboBox->currentIndex() == 2)
      {
          s->setWindowTitle("Jobs des Femmes");
          s->pie_stat_femme();
          s->show();
      }
      else if(ui->stat_comboBox->currentIndex() == 3)
      {
          s->setWindowTitle("Jobs des Hommes");
          s->pie_stat_Homme();
          s->show();
      }
}



void AdminDialog::on_pushButton_quitter_clicked()
{
    Dialoglogin *l;

    l = new Dialoglogin();

        l->show();
        this->close();
}



