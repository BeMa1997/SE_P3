#include "TeilnehmerListeView.h"
#include "ui_mainwindow.h"

#include "QList"
#include <QtSql>

#include "iostream"

using namespace std;;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set up tableWidget
    ui->table_mitglieder->setColumnCount(2);
    ui->table_mitglieder->setHorizontalHeaderLabels(QStringList() << "Vorname" << "Nachname");
    ui->table_mitglieder->verticalHeader()->hide();
    ui->table_mitglieder->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

      // Tabelle mit den Person in der Liste füllen
      //int n = persons.size();
//      ui->table_mitglieder->setRowCount(n-1);
//      ui->table_mitglieder->insertRow(ui->table_mitglieder->rowCount());

//      for (int i = 0;i < n; i++){
//        QTableWidgetItem* firstName = new QTableWidgetItem(persons.at(i).getFirstName());
//        firstName->setFlags(Qt::ItemIsEnabled);
//        ui->table_mitglieder->setItem(i, 0, firstName);

//        QTableWidgetItem* lastName = new QTableWidgetItem(persons.at(i).getLastName());
//        lastName->setFlags(Qt::ItemIsEnabled);
//        ui->table_mitglieder->setItem(i, 1, lastName);
//      }
//      ui->table_mitglieder->resizeColumnsToContents();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_abmelden_clicked()
{

}

void MainWindow::setEmail(QString email)
{
    //Set up Email Label
    ui->label_mail_account->setText(email);
}

void MainWindow::setTyp(int typ)
{
    if(typ == 3){
        ui->label_role->setText("Hauptorganisator");
    }
    else{
        ui->label_role->setText("Organisator");
    }
}

void MainWindow::setId(int id){
    this->id = id;
}

void MainWindow::on_button_eigenes_pw_aendern_clicked()
{

}

void MainWindow::on_button_neues_mitglied_clicked()
{
    QString id;
    QString vorname = ui->lineEdit_vorname->text();
    QString nachname = ui->lineEdit_nachname->text();
    QString geburtsdatum = ui->dateEdit_geburtsdatum->text();
    QString email = ui->lineEdit_email->text();
    QString tel = ui->lineEdit_tel->text();
    QString strasse = ui->lineEdit_strasse->text();
    QString plz = ui->lineEdit_plz->text();
    QString stadt = ui->lineEdit_stadt->text();
    QString land = ui->lineEdit_land->text();

    QString organisator;
    if(ui->checkBox_is_organisator->isChecked()){
        organisator = "2";
    }
    else{
        organisator = "1";
    }


}
