#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mission.h"
#include<QMessageBox>
#include <QIntValidator>
#include <QValidator>
//#include <QPrinter>
//#include <QPrintDialog>
#include <QPixmap>
#include <QTextDocument>
#include<QDate>
#include<QDateEdit>
#include <iostream>
#include<QPrinter>
#include<QDialog>
#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include "exportexcel.h"
#include"video.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QRegExp reg("^([a-zA-Z.]+)$ ");
           //QValidator *validator = new QRegExpValidator(reg, this);
          // QRegExp reg1("^([0-9_\-\.]+)\([0-9_\-\.]+)\([0-9])$ ");

          // QValidator *validator1 = new QRegExpValidator(reg1, this);

      /*  ui->lineEdit_DD->setValidator(validator1);
        ui->lineEdit_DF->setValidator(validator1);
        ui->lineEdit_DD_N->setValidator(validator1);
        ui->lineEdit_DF_N->setValidator(validator1);*/

        ui->lineEdit_ID->setValidator(new QIntValidator(0,9999999,this));
        ui->lineEdit_BUD->setValidator(new QIntValidator(0,9999999,this));
        ui->lineEdit_BUD_N->setValidator(new QIntValidator(0,9999999,this));
        ui->lineEdit_NBR->setValidator(new QIntValidator(0,999,this));
         ui->lineEdit_NBR_N->setValidator(new QIntValidator(0,999,this));
        ui->lineEdit_DES->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,255}"), this ));
      //  ui->lineEdit_TM->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,255}"), this ));
        ui->lineEdit_DES_N->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,255}"), this ));
        ui->lineEdit_N_ID->setValidator(new QIntValidator(0,9999999,this));
        //ui->lineEdit_ID1->setValidator(new QIntValidator(0,9999999,this));
        //ui->lineEdit_TY_N->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,255}"), this ));
        ui->tab_Mission->setModel(m.afficher());
        ui->comboBox->addItem("tri par id");
        ui->comboBox->addItem("tri par numP");
        ui->comboBox->addItem("tri par bud");
        ui->combotype->addItem("stage_vol");
        ui->combotype->addItem("formation");
        ui->combotype->addItem("stage_pro");
        ui->combomod->addItem("stage_vol");
        ui->combomod->addItem("formation");
        ui->combomod->addItem("stage_pro");
        ui->comboBox_cher->addItem("par TYPE");
        ui->comboBox_cher->addItem("par NB_per");
        ui->comboBox_cher->addItem("par ID");
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::on_pushButton_clicked()//ajouter
{
// QSqlQuery query;
 int ID=ui->lineEdit_ID->text().toInt();
 //QDate DATE_DEBUT_M=ui->
 QDate inputDATE_DEBUT_M= ui->dateD->date();
  QString DATE_DEBUT_M = inputDATE_DEBUT_M.toString("dd.MM.yyyy");
  QDate inputDATE_FIN_M= ui->dateF->date();
   QString DATE_FIN_M = inputDATE_FIN_M.toString("dd.MM.yyyy");


 QString DESTINATION=ui->lineEdit_DES->text();
 float BUDGET=ui->lineEdit_BUD->text().toInt();
 int NBR_DE_PERSSONES=ui->lineEdit_NBR->text().toInt();
QString TYPE_DE_MISSION=ui->combotype->currentText();
         Mission m(ID,NBR_DE_PERSSONES,BUDGET,DATE_DEBUT_M,DATE_FIN_M,DESTINATION,TYPE_DE_MISSION);

         bool test= m.ajouter();
                        if(test){
                            MainWindow w;
                        w.show();
                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                    QObject::tr("Ajout effectué.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                           ui->tab_Mission->setModel(m.afficher());
                    }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                    QObject::tr("Ajout non effectué.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_SUPPRIMER_clicked()
{
    Mission M1;

int id=ui->lineEdit_ID_S->text().toInt();
  QString recherche=ui->lineEdit_ID_S->text();

  if (M1.rechercherID(recherche)->rowCount()!=0 and recherche.length()!=0)
  {
      /*********************/
      /*********************/

      bool test=M1.supprimer(id);
     QMessageBox::information(nullptr, QObject::tr("Succès"),
  QObject::tr("Suppression effectué.\n"
    "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
    }
    else
        {QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                              QObject::tr("Suppression non effectué !\n"
                                "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}

  ui->tab_Mission->setModel(M1.afficher());



}


void MainWindow::on_MODIFIER_clicked()
{

    int ID=ui->lineEdit_N_ID->text().toInt();
    QString recherche=ui->lineEdit_N_ID->text();
    //QString DATE_DEBUT_M=ui->lineEdit_DD_N->text();
    //QString DATE_FIN_M=ui->lineEdit_DF_N->text();
    QDate inputDATE_DEBUT_M= ui->dateD_2->date();
     QString DATE_DEBUT_M = inputDATE_DEBUT_M.toString("dd.MM.yyyy");
     QDate inputDATE_FIN_M= ui->dateF_2->date();
      QString DATE_FIN_M = inputDATE_FIN_M.toString("dd.MM.yyyy");
    QString DESTINATION=ui->lineEdit_DES_N->text();
    float BUDGET=ui->lineEdit_BUD_N->text().toInt();
    int NBR_DE_PERSSONES=ui->lineEdit_NBR_N->text().toInt();
    QString TYPE_DE_MISSION=ui->combomod->currentText();
  // QString TYPE_DE_MISSION=ui->lineEdit_TY_N->text();
  // int RID=ui->lineEdit_ID1->text().toInt();
            Mission m(ID,NBR_DE_PERSSONES,BUDGET,DATE_DEBUT_M,DATE_FIN_M,DESTINATION,TYPE_DE_MISSION);
            bool valid=true;
          if((m.Verif_id()==true) or (m.Verif_nbr()==true) or (m.Verif_type()==true) or (m.Verif_dateD()==true) or (m.Verif_dateF()==true) or (m.Verif_budget()==true)or (m.Verif_destination()==true))
          {
        if(m.Verif_id())
                     { ui->ver1->clear();
              ui->ver1->setText(QString("!"));


        }

              if(m.Verif_nbr())
                            { ui->ver6->clear();
                    ui->ver6->setText(QString("!"));

                                    }
              if(m.Verif_destination())
                            { ui->ver5->clear();
                  ui->ver5->setText(QString("!"));

             }
              if(m.Verif_type())
                            { ui->ver2->clear();
                   ui->ver2->setText(QString("!"));

            }
              if(m.Verif_dateD())
                            { ui->ver3->clear();
                  ui->ver3->setText(QString("!"));

             }
              if(m.Verif_dateF())
                            { ui->ver4->clear();
                  ui->ver4->setText(QString("!"));
             }
              if(m.Verif_budget())
            { ui->ver7->clear();
                  ui->ver7->setText(QString("!"));

              }
             valid=false;
              }
if (m.rechercherID(recherche)->rowCount()!=0 and recherche.length()!=0)
{
            bool test= m.modifier(ID);
                           if(test){
                               MainWindow w;
                           w.show();
                           QMessageBox::information(nullptr, QObject::tr("database is open"),
                                       QObject::tr("Modification effectué.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                              ui->tab_Mission->setModel(m.afficher());
                       }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                       QObject::tr("Modification non effectué.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
}
else
{QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
               QObject::tr("Modification non effectué !\n"
                 "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}

ui->tab_Mission->setModel(m.afficher());


 }





void MainWindow::on_CHERCHER_clicked()
{
    Mission M1;
    QString recherche = ui->lineEdit_cher->text();
    if(recherche.length()!=0)
{
       //ui->tab_Mission->setModel(M1.rechercherType(recherche));
    // ui->tab_Mission->setModel(M1.rechercherID(recherche));
        if(ui->comboBox_cher->currentIndex()==0){
            ui->tab_Mission->setModel(M1.rechercherType(recherche));
           // ui->tab_Mission->setModel(m.triID());

        }
        else if (ui->comboBox_cher->currentIndex()==1)
        {
             ui->tab_Mission->setModel(M1.rechercherNBP(recherche));
           // ui->tab_Mission->setModel(m.triNBP());

        }
        else if(ui->comboBox_cher->currentIndex()==2)
        {
            ui->tab_Mission->setModel(M1.rechercherID(recherche));


    }
    else
    {
       ui->tab_Mission->setModel(M1.afficher());
    }
}
}

void MainWindow::on_pushButton_ANNULER_clicked()
{
         ui->lineEdit_ID->clear();
         ui->lineEdit_BUD->clear();
        // ui->lineEdit_DD->clear();
        //ui->lineEdit_DF->clear();
         ui->lineEdit_DES->clear();
         ui->lineEdit_NBR->clear();
         ui->combotype->clear();
}

void MainWindow::on_pushButton_ANNULER2_clicked()
{
     ui->lineEdit_N_ID->clear();
     ui->lineEdit_BUD_N->clear();
    // ui->lineEdit_DD_N->clear();
    //ui->lineEdit_DF_N->clear();
     ui->lineEdit_DES_N->clear();
     ui->lineEdit_NBR_N->clear();
     ui->combomod->clear();
     ui->ver1->clear();
     ui->ver2->clear();
     ui->ver3->clear();
     ui->ver4->clear();
     ui->ver5->clear();
     ui->ver6->clear();
     ui->ver7->clear();
}

void MainWindow::on_ANNULER3_clicked()
{
   ui->lineEdit_ID_S->clear();
}


void MainWindow::on_pushButton_10_clicked() //tri
{
    Mission m;
    if(ui->comboBox->currentIndex()==0){
        ui->tab_Mission->setModel(m.triID());
       cout << "tri id" << endl;
    }
    else if (ui->comboBox->currentIndex()==1)
    {
        ui->tab_Mission->setModel(m.triNBP());
        cout << "tri nbp" << endl;
    }
    else if(ui->comboBox->currentIndex()==2)
    {
        ui->tab_Mission->setModel(m.triBUD());
        cout << "tri bud" << endl;
    }
    else
        cout << "no combobox" << endl;
}



/*void MainWindow::on_tab_Mission_activated(const QModelIndex &index)
{

}*/

void MainWindow::on_pushButton_7_clicked() //PDF
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tab_Mission->model()->rowCount();
                const int columnCount =ui->tab_Mission->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#f5f5f7 link=#5000A0>\n"
                            "<h1>Liste des MISSIONS</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#51a8a0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_Mission->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_Mission->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tab_Mission->isColumnHidden(column)) {
                                   QString data = ui->tab_Mission->model()->data(ui->tab_Mission->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";



        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("MISSION.pdf");
        document->print(&printer);
}

void MainWindow::on_pushButton_2_clicked() //ref
{
    Mission M1;

 ui->tab_Mission->setModel(M1.afficher());
 ui->lineEdit_cher->clear();
}

void MainWindow::on_pushButton_8_clicked()//stat
{
    Dialog d;
    d.stats();
    d.setWindowTitle("statistique");
    d.exec();
}


void MainWindow::on_execl_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tab_Mission);

    //colums to export
    obj.addField(0,"IDENTIFIANT", "char(20)");
    obj.addField(1,"DATE_DEBUT_M", "char(20)");
    obj.addField(2,"NBR_PERSONES", "char(20)");
    obj.addField(3,"DESTINATION", "char(20)");
    obj.addField(4,"BUDGET", "char(20)");
    obj.addField(5,"DATE_FIN_M", "char(20)");
    obj.addField(6,"TYPE_MISSION", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}


void MainWindow::on_calendarWidget_clicked(const QDate &date)
{

    qInfo()<<date;

       ui->tableCALEN->setModel(m.recherche_DATED(date));


}




void MainWindow::on_tableCALEN_activated(const QModelIndex &index)
{
   QString val=ui->tableCALEN->model()->data(index).toString();

  QSqlQuery qry;
  qry.prepare("select * FROM MISSION where ID=:ID" );
  qry.bindValue(":ID",val);
  if(qry.exec())

      while (qry.next()) {


  {
      ui->lineEdit_ID_S->setText(qry.value(0).toString());//supprimer
      ui->lineEdit_N_ID->setText(qry.value(0).toString());
      ui->lineEdit_NBR_N->setText(qry.value(2).toString());
      ui->lineEdit_DES_N->setText(qry.value(3).toString());
      ui->lineEdit_BUD_N->setText(qry.value(4).toString());
      //ui->lineEdit_->setText(qry.value(3).toString());
}
  }
  }


void MainWindow::on_pushButton_3_clicked()//reff
{
   // ui->tableCALEN->setModel(m.recherche_DATED(date));
}


void MainWindow::on_pushButton_4_clicked()
{
    video v;
   // v =new video();
    v.show();
}

