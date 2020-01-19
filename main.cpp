//#include "loginwindow.h"
#include "iostream"

using namespace std;

#include <QtSql>
#include <QApplication>

//DB-Verbindung (mit SQLite-Treiber "QSlite") herstellen.
void openDB() {

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("C:\\Users\\Andreas\\Documents\\soft_eng\\SE_P3\\Datenbank.db");
    db.setDatabaseName("..\\data\\Datenbank.db");

    if (!db.open()){
        cerr << "Datenbank Verbindung ist gescheitert" << endl;
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    openDB();

    //loginwindow login;

    //login.show();
    //w.show();

    return a.exec();
}
