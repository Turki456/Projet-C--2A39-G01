#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <QDialog>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>

using namespace std;

namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
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

    ~statistique();

private:
    Ui::statistique *ui;
private slots :
};
#endif // STATISTIQUE_H
