#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"

#include "iostream"

using namespace std;;

loginwindow::loginwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);


}



loginwindow::~loginwindow()
{
    delete ui;
}


void loginwindow::on_anmelden_clicked()
{

    QString Username, Password;
    Username = ui->benutzername->text();
    Password = ui->passwort->text();

    cout << Username.toStdString() << endl;
    cout << Password.toStdString() << endl;

    QSqlQuery *qry = new QSqlQuery;

    if(qry->exec("SELECT typ, email, id FROM klassenmitglied WHERE vorname=\'" + Username + "\' AND kennwort=\'" + Password + "\'")){

        if(qry->next()){
            int typ = qry->value(0).toInt();
            if(typ == 3){
                cout << "Hauptorganisator-Login war erfolgreich" << endl;
                close();
                MainWindow *w = new MainWindow;
                w->setTyp(qry->value(0).toInt());
                w->setEmail(qry->value(1).toString());
                w->setId(qry->value(2).toInt());
                w->show();

            }
            else if(typ == 2){
                cout << "Organisator-Login war erfolgreich" << endl;
            }
            else{
                cout << "Keine Berechtigungen Login war nicht erfolgreich" << endl;
            }

        }
        else{
            cout << "Falscher Nutzername oder Passwort" << endl;
        }

    }
    else{
        cout << "Exec Fehlgeschlagen!" << endl;
    }

}

void loginwindow::on_beenden_clicked()
{
    cout << "Programm wird beendet" << endl;
    exit(0);
}
