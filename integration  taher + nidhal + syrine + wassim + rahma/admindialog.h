#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>
#include "employe.h"

namespace Ui {
class AdminDialog;
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = nullptr);
    ~AdminDialog();

private slots:
    void on_pushButton_ajouterEmploye_clicked();

    void on_pushButton_supprimerEmploye_clicked();

    void on_tableauCRUD_tabBarClicked(int index);

    void on_pushButton_modifier_clicked();

    void on_tableView_modifier_activated(const QModelIndex &index);

    //void on_clickme_clicked();

    //void on_click_me_clicked();

    //void on_pushButton_2_clicked();

    void on_search_button_clicked();

    void on_reset_button_clicked();

    void on_tri_asc_clicked();

    //void on_tri_desc_clicked();

    void on_pdf_clicked();

    void on_stats_clicked();

    void on_pushButton_quitter_clicked();

    //void on_pushButton_modifier_2_clicked();

    //void on_button_mission_clicked();


private:
    Ui::AdminDialog *ui;
    Employe Etmp;
};

#endif // ADMINDIALOG_H
