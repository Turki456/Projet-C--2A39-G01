#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>
#include <QMainWindow>


namespace Ui {
class Dialoglogin;
}

class Dialoglogin : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoglogin(QWidget *parent = nullptr);
    ~Dialoglogin();

private slots:
    void on_confirmButton_clicked();

    //void on_pushButton_clicked();

private:
    Ui::Dialoglogin *ui;

};

#endif // DIALOGLOGIN_H
