#include "dialog.h"
#include "ui_dialog.h"
#include "mission.h"
#include<QtCharts>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{



    delete ui;
}
 void Dialog::stats()
 {

     QSqlQuery query0,query1,query2,query3;
             float valFOR=0,valSTV=0,valSTP=0,items=0;
             query0.prepare("select * from MISSION");
             query0.exec();
             query1.prepare("select * from MISSION where TYPE_DE_MISSION =:formation");
             query1.bindValue(":formation","formation");
             query1.exec();
             query2.prepare("select * from MISSION where TYPE_DE_MISSION =:stage_vol");
             query2.bindValue(":stage_vol","stage_vol");
             query2.exec();
             query3.prepare("select * from MISSION where TYPE_DE_MISSION =:stage_pro");
             query3.bindValue(":stage_pro","stage_pro");
             query3.exec();
             while(query0.next()){items++;};
             while(query1.next()){valFOR++;};
             while(query2.next()){valSTV++;};
             while(query3.next()){valSTP++;}

             valFOR=valFOR/items;
             valSTV=valSTV/items;
            valSTP=valSTP/items;

             QPieSeries *series = new QPieSeries();
             series->append("formation",valFOR);
             series->append("stage_vol",valSTV);
             series->append("stage_pro",valSTP);

             QPieSlice *slice0 = series->slices().at(0);
             slice0->setLabelVisible();
             QPieSlice *slice1 = series->slices().at(1);
             slice1->setLabelVisible();
             QPieSlice *slice2 = series->slices().at(2);
             slice2->setLabelVisible();
            /* QPieSlice *slice3 = series->slices().at(3);
             slice3->setLabelVisible();*/

             QChart *chart = new QChart();
             chart->addSeries(series);
             chart->legend()->hide();

             QChartView *chartView = new QChartView(chart,this);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->setMinimumSize(420,300);
                chartView->show();


 }

