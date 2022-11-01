#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employe.h"
#include <QMainWindow>
/*
#include <QRegExpValidator>
#define valid_chaine "([A-Z][a-z]*)([\\s\\'-][A-Z][a-z]*)*"
#define valid_nombre "[0-9]+"
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouterEmploye_clicked();

    void on_pushButton_supprimerEmploye_clicked();

    void on_tableauCRUD_tabBarClicked(int index);

    void on_pushButton_modifierEmploye_clicked();

private:
    Ui::MainWindow *ui;
    Employe Etmp;
};

#endif // MAINWINDOW_H
