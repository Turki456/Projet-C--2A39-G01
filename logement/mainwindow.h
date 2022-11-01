#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"logement.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_Confirmer_clicked();
    void on_supprimer_clicked();
    void on_Modifier_clicked();
    void on_pushButton_2_clicked();
    void on_Annuler_clicked();
    void on_Chercher_clicked();
     void on_Refresh_clicked();

private:
    Ui::MainWindow *ui;
    logement Dtmp;
    QByteArray data;
};
#endif // MAINWINDOW_H
