#include "changepasswordwindow.h"
#include "ui_changepasswordwindow.h"

#include <QtSql>

#include "iostream"

using namespace std;;

changepasswordwindow::changepasswordwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changepasswordwindow)
{
    ui->setupUi(this);

}

changepasswordwindow::~changepasswordwindow()
{
    delete ui;
}

void changepasswordwindow::setId(int id){
    this->id = id;
}

void changepasswordwindow::on_pushButton_1_clicked()
{
    close();
}

void changepasswordwindow::on_pushButton_2_clicked()
{
    QString Password_1, Password_2;
    Password_1 = ui->lineEdit_1->text();
    Password_2 = ui->lineEdit_2->text();

    if(Password_1 != Password_2){
        cout << "Unterschieliche Passwörter" << endl;
    }
    else{
        QSqlQuery *qry = new QSqlQuery;

        QString id = QString::number(this->id);

        //update klassenmitglied set kennwort='testtest' where id=1
        if(qry->exec("UPDATE klassenmitglied SET kennwort=\'" + Password_1 + "\' WHERE id=" + id + ";")){
            cout << "Passwort erfolgreich geändert" << endl;
            close();
        }
        else{
            cout << "Exec Fehlgeschlagen!" << endl;
        }
    }
}
