#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>

#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setTyp(int typ);
    void setEmail(QString email);
    void setId(int id);

private slots:
    void on_button_abmelden_clicked();

    void on_button_eigenes_pw_aendern_clicked();

    void on_button_neues_mitglied_clicked();

private:
    Ui::MainWindow *ui;
    int id;
};

#endif // MAINWINDOW_H
