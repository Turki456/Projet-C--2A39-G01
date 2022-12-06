#include "statistique.h"
#include "ui_statistique.h"
#include "ui_mainwindow.h"
#include<iostream>
#include "mainwindow.h"


statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}
int statistique::Statistique_partie2()
{
        qreal tot=0;
        QSqlQuery q1;
                q1.prepare("select * from LOGEMENT where PRIX_L <250");
                q1.exec();
                while (q1.next()){tot++;}
                return tot;

}

int statistique::Statistique_partie3()
{
    qreal tot=0;
        QSqlQuery q1;
                q1.prepare("select * from LOGEMENT where PRIX_L <500 and PRIX_L >250 ");
                q1.exec();
                while (q1.next()){tot++;}
                return tot;

}
int statistique::Statistique_partie4()
{   qreal tot=0;
    QSqlQuery q1;
            q1.prepare("select * from LOGEMENT where PRIX_L <750 and PRIX_L >500 ");
            q1.exec();
            while (q1.next()){tot++;}
            return tot;
}
int statistique::Statistique_partie7()
{
     qreal tot=0;
     QSqlQuery q1;
             q1.prepare("select * from LOGEMENT where PRIX_L >750 and PRIX_L <1000 ");
             q1.exec();
             while (q1.next()){tot++;}
             return tot;

}
int statistique::Statistique_partie8()
{
   qreal tot=0;
    QSqlQuery q1;
            q1.prepare("select * from LOGEMENT where PRIX_L >1000 ");
            q1.exec();
            while (q1.next()){tot++;}
            return tot;
}

int statistique::Statistique_partie5()
{   qreal tot=0;
    QSqlQuery q1;
            q1.prepare("SELECT * FROM  LOGEMENT where TYPE_L='Hotel' or TYPE_L='HOTEL' or TYPE_L='hotel'  ");
            q1.exec();
            while (q1.next()){tot++;}
            return tot;
}
int statistique::Statistique_partie6()
{
    qreal tot=0;
        QSqlQuery q1;
                q1.prepare("SELECT * FROM  LOGEMENT where TYPE_L='Maison' or TYPE_L='MAISON' or TYPE_L='maison'  ");
                q1.exec();
                while (q1.next()){tot++;}
                return tot;
}
int statistique::Statistique_partie9()
{
    qreal tot=0;
        QSqlQuery q1;
                q1.prepare("SELECT * FROM  LOGEMENT where TYPE_L='Appartement' or TYPE_L='APPARTEMENT' or TYPE_L='appartement'  ");
                q1.exec();
                while (q1.next()){tot++;}
                return tot;

}






void statistique::paintEvent(QPaintEvent *)
{
    // statistique prix
    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;
    int d=Statistique_partie4();
    cout<<d<<endl ;
    int e=Statistique_partie7();
    cout<<e<<endl ;
    int f=Statistique_partie8();
    cout<<f<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float s4=d*100;
        float s5=e*100;
        float s6=f*100;
        float nb = b+c+d+e+f ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float q4;
        q4=s4/nb;
        float q5;
        q5=s5/nb;
        float q6;
        q6=s6/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float o;
        o= (q4*360)/100;
        float u;
        u= (q5*360)/100;
        float x;
        x= (q6*360)/100;
    QPainter painter(this);
    //QRectF size=QRectF(350,150,this->width()-700,this->width()-700);
    QRectF size=QRectF(500,75,this->width()-650,this->width()-650);



    painter.setBrush(Qt::darkBlue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("(logement [0->250])") ;
    ui->label_3->setNum(q2) ;
    painter.setBrush(Qt::darkGreen);
    painter.drawPie(size,16*y,16*m);
    ui->label_4->setText("(logement [250->500])") ;
    ui->label_6->setNum(q3) ;
    painter.setBrush(Qt::darkRed);
    painter.drawPie(size,16*y+16*m,16*o);
    ui->label_5->setText("(logement [500->750])") ;
    ui->label_7->setNum(q4) ;
    painter.setBrush(Qt::darkYellow);
    painter.drawPie(size,16*y+16*m+16*o,16*u);
    ui->label_11->setText("(logement [750->1000])") ;
    ui->label_9->setNum(q5) ;
    painter.setBrush(Qt::black);
    painter.drawPie(size,16*y+16*m+16*o+16*u,16*x);
    ui->label_12->setText("(logement [>1000])") ;
    ui->label_10->setNum(q6) ;


    // statistique type
    int b1=Statistique_partie5();
    cout<<b1<<endl ;
    int c1=Statistique_partie6();
    cout<<c1<<endl ;
    int a1=Statistique_partie9();
    cout<<a1<<endl ;
        float s11=a1*100;
        float s21= b1*100 ;
        float s31=c1*100;
        float nb1 = a1+b1+c1 ;
        float q11 ;
        q11 = s11/nb1 ;
        float q21 ;
        q21 = s21/nb1 ;
        float q31;
        q31=s31/nb1;
        float x1  ;
        x1 = (q11*360)/100 ;
        float y1  ;
        y1 = (q21*360)/100 ;
        float m1;
        m1= (q31*360)/100;
    //QPainter painter(this);
    QRectF size1=QRectF(5,100,this->width()-700,this->width()-700);

    painter.setBrush(Qt::darkBlue);
    painter.drawPie(size1,0,16*y1);
    ui->label_17->setText("Hotel") ;
     ui->label_22->setNum(q21) ;

     painter.setBrush(Qt::darkGreen);
     painter.drawPie(size1,16*y1,16*m1);
     ui->label_20->setText("Maison");
     ui->label_15->setNum(q31);


    painter.setBrush(Qt::darkRed);
    painter.drawPie(size1,16*y1+16*m1,16*x1);
    ui->label_19->setText("Appartement");
    ui->label_18->setNum(q11);




}

/*
void statistique::paintEvent2(QPaintEvent *)
{


        int b=Statistique_partie5();
        cout<<b<<endl ;
        int c=Statistique_partie6();
        cout<<c<<endl ;
        int a=Statistique_partie9();
        cout<<a<<endl ;
            float s1=a*100;
            float s2= b*100 ;
            float s3=c*100;
            float nb = a+b+c ;
            float q1 ;
            q1 = s1/nb ;
            float q2 ;
            q2 = s2/nb ;
            float q3;
            q3=s3/nb;
            float x  ;
            x = (q1*360)/100 ;
            float y  ;
            y = (q2*360)/100 ;
            float m;
            m= (q3*360)/100;
        QPainter painter(this);
        QRectF size=QRectF(350,150,this->width()-700,this->width()-700);

        painter.setBrush(Qt::darkBlue);
        painter.drawPie(size,0,16*y);
        ui->label_17->setText("Hotel") ;
         ui->label_22->setNum(q2) ;

         painter.setBrush(Qt::darkGreen);
         painter.drawPie(size,16*y,16*m);
         ui->label_20->setText("Maison");
         ui->label_15->setNum(q3);


        painter.setBrush(Qt::darkRed);
        painter.drawPie(size,16*y+16*m,16*x);
        ui->label_19->setText("Appartement");
        ui->label_18->setNum(q1);




}
*/

/*------------------------------------- STATS EMPLOYE -------------------------------------------------------------*/
/*------------------------------------- STATS EMPLOYE -------------------------------------------------------------*/

void statistique::bar_stat()
{
    QSqlQuery query1,query2,query3;
    qreal tot=0,s1=0,s2=0;

    //Queries and calculations
    query1.prepare("SELECT * FROM Employe");
    query1.exec();
    query2.prepare("SELECT * FROM Employe WHERE sexe_E = 'Femme' ");
    query2.exec();
    query3.prepare("SELECT * FROM Employe WHERE sexe_E = 'Homme' ");
    query3.exec();


    while(query1.next()){tot++;}
    while(query2.next()){s1++;}
    while(query3.next()){s2++;}

    s1 = s1/tot;
    s2 = s2/tot;

    //Attacher des noms au lots
    QBarSet * set1 = new QBarSet("Taux de femmes");
    QBarSet * set2 = new QBarSet("Taux d'hommes");

    //Attacher des valeurs au lots
    *set1 << s1;
    *set2 << s2;

    //Ajouter les lots en une serie
    QBarSeries * series = new QBarSeries();

    series->append(set1);
    series->append(set2);

    //Legende du graphe
    QChart * chart = new QChart();

    //Ajouter la serie au graphe
    chart->addSeries(series);

    QPalette palette = qApp->palette();
    palette.setColor(QPalette::Window, QRgb(0xffffff));
    palette.setColor(QPalette::WindowText, QRgb(0x404044));

    //Appliquer la palette
    qApp->setPalette(palette);

    //affichage du graphe
    chartView = new QChartView(chart,ui->stat_le);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();
}
void statistique::pie_chart()
{
    QSqlQuery query0,query1,query2;
    qreal tot=0, s1=0, s2=0;
    QString keyword = "Specialiste IT";

    //requetes et calculs
    query0.prepare("SELECT * FROM Employe");
    query0.exec();
    query1.prepare("SELECT * FROM Employe WHERE sexe_E = 'Femme' and poste like '"+keyword+"' OR LOWER(poste) like '"+keyword+"' OR UPPER(poste) like '"+keyword+"' ");
    query1.exec();
    query2.prepare("SELECT * FROM Employe WHERE sexe_E = 'Homme' and poste like '"+keyword+"' OR LOWER(poste) like '"+keyword+"' OR UPPER(poste) like '"+keyword+"' ");
    query2.exec();

    while(query0.next()){tot++;}
    while(query1.next()){s1++;}
    while(query2.next()){s2++;}

    s1 = s1/tot;
    s2 = s2/tot;

    //definir les tranches
    QPieSeries *series = new QPieSeries();
    series->append("Femmes",s1);
    series->append("Hommes",s2);


    // Creer le graphe
     QChart *chart = new QChart();

    // affecter les donnees au graphique
    chart->addSeries(series);
    chart->legend()->show();


    // Afficher le graohe
    chartView = new QChartView(chart,ui->stat_le);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();
}

void statistique::pie_stat_femme()
{
    QSqlQuery query0,query1,query2,query3,query4,query5,query6;
    qreal tot=0, s1=0, s2=0, s3=0, s4=0, s5=0, s6=0;

    QString IT = "Specialiste IT";
    QString RH = "Responsable RH";
    QString directeur = "Directeur";
    QString manager ="Manager de projets";
    QString marketing = "Responsable marketing";
    QString comptable = "Service comptable";


    query0.prepare("SELECT * FROM Employe");
    query0.exec();

    query1.prepare("SELECT * FROM Employe WHERE sexe_E = 'Femme' and poste like '"+IT+"' OR LOWER(poste) like '"+IT+"' OR UPPER(poste) like '"+IT+"' ");
    query1.exec();
    query2.prepare("SELECT * FROM Employe WHERE sexe_E = 'Femme' and poste like '"+RH+"' OR LOWER(poste) like '"+RH+"' OR UPPER(poste) like '"+RH+"' ");
    query2.exec();
    query3.prepare("SELECT * FROM Employe WHERE sexe_E = 'Femme' and poste like '"+directeur+"' OR LOWER(poste) like '"+directeur+"' OR UPPER(poste) like '"+directeur+"' ");
    query3.exec();
    query4.prepare("SELECT * FROM Employe WHERE sexe_E = 'Femme' and poste like '"+manager+"' OR LOWER(poste) like '"+manager+"' OR UPPER(poste) like '"+manager+"'");
    query4.exec();
    query5.prepare("SELECT * FROM Employe WHERE sexe_E = 'Femme' and poste like '"+marketing+"' OR LOWER(poste) like '"+marketing+"' OR UPPER(poste) like '"+marketing+"' ");
    query5.exec();
    query6.prepare("SELECT * FROM Employe WHERE sexe_E = 'Femme' and poste like '"+comptable+"' OR LOWER(poste) like '"+comptable+"' OR UPPER(poste) like '"+comptable+"' ");
    query6.exec();

    while(query0.next()){tot++;}
    while(query1.next()){s1++;}
    while(query2.next()){s2++;}
    while(query3.next()){s3++;}
    while(query4.next()){s4++;}
    while(query5.next()){s5++;}
    while(query6.next()){s6++;}

    s1 = s1/tot;
    s2 = s2/tot;
    s3 = s3/tot;
    s4 = s4/tot;
    s5 = s5/tot;
    s6 = s6/tot;

    QPieSeries *series = new QPieSeries();
    series->append("IT",s1);
    series->setLabelsVisible("IT");
    series->append("RH",s2);
    series->setLabelsVisible("RH");
    series->append("Direction",s3);
    series->setLabelsVisible("Direction");
    series->append("Management",s4);
    series->setLabelsVisible("Management");
    series->append("Marketing",s5);
    series->setLabelsVisible("Marketing");
    series->append("Compatbilité",s6);
    series->setLabelsVisible("Comptabilité");



    // Creer le graphe
     QChart *chart = new QChart();

    // affecter les donnees au graphique
    chart->addSeries(series);
    chart->legend()->show();


    // Afficher le graohe
    chartView = new QChartView(chart,ui->stat_le);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();

}
void statistique::pie_stat_Homme()
{
    QSqlQuery query0,query1,query2,query3,query4,query5,query6;
    qreal tot=0, s1=0, s2=0, s3=0, s4=0, s5=0, s6=0;

    QString IT = "Specialiste IT";
    QString RH = "Responsable RH";
    QString directeur = "Directeur";
    QString manager ="Manager de projets";
    QString marketing = "Responsable marketing";
    QString comptable = "Service comptable";


    query0.prepare("SELECT * FROM Employe");
    query0.exec();

    query1.prepare("SELECT * FROM Employe WHERE sexe_E = 'Homme' and poste like '"+IT+"' OR LOWER(poste) like '"+IT+"' OR UPPER(poste) like '"+IT+"' ");
    query1.exec();
    query2.prepare("SELECT * FROM Employe WHERE sexe_E = 'Homme' and poste like '"+RH+"' OR LOWER(poste) like '"+RH+"' OR UPPER(poste) like '"+RH+"' ");
    query2.exec();
    query3.prepare("SELECT * FROM Employe WHERE sexe_E = 'Homme' and poste like '"+directeur+"' OR LOWER(poste) like '"+directeur+"' OR UPPER(poste) like '"+directeur+"' ");
    query3.exec();
    query4.prepare("SELECT * FROM Employe WHERE sexe_E = 'Homme' and poste like '"+manager+"' OR LOWER(poste) like '"+manager+"' OR UPPER(poste) like '"+manager+"'");
    query4.exec();
    query5.prepare("SELECT * FROM Employe WHERE sexe_E = 'Homme' and poste like '"+marketing+"' OR LOWER(poste) like '"+marketing+"' OR UPPER(poste) like '"+marketing+"' ");
    query5.exec();
    query6.prepare("SELECT * FROM Employe WHERE sexe_E = 'Homme' and poste like '"+comptable+"' OR LOWER(poste) like '"+comptable+"' OR UPPER(poste) like '"+comptable+"' ");
    query6.exec();

    while(query0.next()){tot++;}
    while(query1.next()){s1++;}
    while(query2.next()){s2++;}
    while(query3.next()){s3++;}
    while(query4.next()){s4++;}
    while(query5.next()){s5++;}
    while(query6.next()){s6++;}

    s1 = s1/tot;
    s2 = s2/tot;
    s3 = s3/tot;
    s4 = s4/tot;
    s5 = s5/tot;
    s6 = s6/tot;

    QPieSeries *series = new QPieSeries();
    series->append("IT",s1);
    series->setLabelsVisible("IT");
    series->append("RH",s2);
    series->setLabelsVisible("RH");
    series->append("Direction",s3);
    series->setLabelsVisible("Direction");
    series->append("Management",s4);
    series->setLabelsVisible("Management");
    series->append("Marketing",s5);
    series->setLabelsVisible("Marketing");
    series->append("Compatbilité",s6);
    series->setLabelsVisible("Comptabilité");



    // Creer le graphe
     QChart *chart = new QChart();

    // affecter les donnees au graphique
    chart->addSeries(series);
    chart->legend()->show();


    // Afficher le graohe
    chartView = new QChartView(chart,ui->stat_le);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();

}


