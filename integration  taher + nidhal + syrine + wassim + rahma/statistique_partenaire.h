#ifndef STATISTIQUE_PARTENAIRE_H
#define STATISTIQUE_PARTENAIRE_H

#include <QDialog>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
//employe
#include <QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui
{


class Statistique_partenaire : public QDialog
{
    Q_OBJECT

public:
<<<<<<< HEAD:statistique.h
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

         int Statistique_partie2() ;
         int Statistique_partie3() ;
         int Statistique_partie4() ;
         int Statistique_partie5() ;
         int Statistique_partie6() ;
         int Statistique_partie7() ;
         int Statistique_partie8() ;
         int Statistique_partie9() ;
         void paintEvent(QPaintEvent *) ;
         void paintEvent2(QPaintEvent *) ;

         //statsEmploye
             QChartView *chartView ;
             void bar_stat();
             void pie_chart();
             void pie_stat_femme();
             void pie_stat_Homme();



=======
    explicit Statistique_partenaire(QWidget *parent = nullptr);
    int Statistique_partie2() ;
        int Statistique_partie3() ;
         int Statistique_partie4() ;
         int Statistique_partie5() ;
         int Statistique_partie6() ;
        void paintEvent(QPaintEvent *) ;

    ~Statistique_partenaire();
>>>>>>> 279b53c37b357bc694b3239812a2b7ebc148bca2:integration  taher + nidhal + syrine + wassim + rahma/statistique_partenaire.h

private:
    Ui::Statistique_partenaire *ui;
private slots :
};
}
QT_END_NAMESPACE
#endif // STATISTIQUE_H
