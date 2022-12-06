#ifndef STATISTIQUE_PARTENAIRE_H
#define STATISTIQUE_PARTENAIRE_H

#include <QDialog>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui
{


class Statistique_partenaire : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique_partenaire(QWidget *parent = nullptr);
    int Statistique_partie2() ;
        int Statistique_partie3() ;
         int Statistique_partie4() ;
         int Statistique_partie5() ;
         int Statistique_partie6() ;
        void paintEvent(QPaintEvent *) ;

    ~Statistique_partenaire();

private:
    Ui::Statistique_partenaire *ui;
private slots :
};
}
QT_END_NAMESPACE
#endif // STATISTIQUE_H
