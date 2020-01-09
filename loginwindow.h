#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class loginwindow;
}

class loginwindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr);
    ~loginwindow();

private slots:

    void on_anmelden_clicked();

    void on_beenden_clicked();

private:
    Ui::loginwindow *ui;
};

#endif // LOGINWINDOW_H
