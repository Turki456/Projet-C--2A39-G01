#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"mission.h"
#include<QtSql>
#include<QPrinter>
//#include<QWebEngineView>


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
    void on_pushButton_clicked();

    void on_SUPPRIMER_clicked();

    void on_MODIFIER_clicked();

    void on_CHERCHER_clicked();

    void on_pushButton_ANNULER_clicked();

    void on_pushButton_ANNULER2_clicked();

    void on_ANNULER3_clicked();

    void on_TRI_ID_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_10_clicked();

    void on_tab_Mission_activated(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_execl_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_3_clicked();

    void on_tableCALEN_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Mission m;
};
#endif // MAINWINDOW_H
