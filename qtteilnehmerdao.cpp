#include "qtteilnehmerdao.h"
#include <map>
#include "QList"
#include <QtSql>

QSqlDatabase database;

QtTeilnehmerDao::QtTeilnehmerDao() {
    QSqlQuery query(database);
    if(!QFile::exists("klassentreffen_db"))
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("klassentreffen_db");
        if (!database.open())
        {
            qDebug() << "Fehler: Keine Datenbank-Anbindung möglich!";
        }
        else
        {
            qDebug() << "OK: Datenbank verbunden.";
        }

        if(QFile::exists("klassentreffen_db"))
        {
            QFile schemaFile("klassentreffen_schema.sql");
            schemaFile.open(QFile::ReadOnly);
            QStringList schemaTableList = QString(schemaFile.readAll()).split(";");
            foreach(const QString schemaTable, schemaTableList)
            {
                query.exec(schemaTable);
            }

            schemaFile.close();
        }
        else
        {
            qDebug() << "Fehler: Schema-Datei nicht gefunden!";
        }
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("klassentreffen_db");
        if (!database.open())
        {
            qDebug() << "Fehler: Keine Datenbank-Anbindung möglich!";
        }
        else
        {
            qDebug() << "OK: Datenbank verbunden.";
        }
    }
}


int Insert(Klassenmitglied &km) {
    QSqlQuery query;
    query.prepare("INSERT INTO Klassenmitglied ("
                  "vorname, "
                  "nachname, "
                  "geburtsname, "
                  "email, "
                  "telnr, "
                  "typ, "
                  "kennwort, "
                  "strasse, "
                  "hausnr, "
                  "ort, "
                  "plz, "
                  "land) "
                  "VALUES ("
                  ":vorname, "
                  ":nachname, "
                  ":geburtsname,"
                  ":email, "
                  ":telnr, "
                  ":typ, "
                  ":kennwort, "
                  ":strasse, "
                  ":hausnr, "
                  ":ort, "
                  ":plz, "
                  ")");
    query.bindValue(":vorname", QString::fromStdString(km.getVorname()));
    query.bindValue(":nachname", QString::fromStdString(km.getNachname()));
    query.bindValue(":geburtsname", QString::fromStdString(km.getGeburtsname()));
    query.bindValue(":email", QString::fromStdString(km.getEmail()));
    query.bindValue(":telnr", QString::fromStdString(km.getTelnr()));
    if(typeid(km).name() == typeid(Klassenmitglied).name())
    {
       query.bindValue(":typ", "1");
    }
    else
    {
        if(typeid(km).name() == typeid(Organisator).name())
        {
           query.bindValue(":typ", "2");
        }
        else
        {
            if(typeid(km).name() == typeid(Hauptorganisator).name())
            {
               query.bindValue(":typ", "3");
            }
            else
            {
                qDebug() << "Fehler: Kein gültiger Typ!";
            }
        }
    }
    query.bindValue(":kennwort", QString::fromStdString(km.getKennwort()));
    query.bindValue(":strasse", QString::fromStdString(km.getStrasse()));
    query.bindValue(":hausnummer", QString::fromStdString(km.getHausnummer()));
    query.bindValue(":ort", QString::fromStdString(km.getOrt()));
    query.bindValue(":plz", QString::fromStdString(km.getPlz()));

    if(query.exec())
    {
        return 1;
    }
    else
    {
        return 0;
    }

    return 0;
}


int Modify() {

    //

    return 0;
}


Klassenmitglied Get() {

    //
}


bool Contains() {

    bool returnValue = false;

    //

    return returnValue;
}


map<const int, Klassenmitglied> GetTeilnehmerListe() {

    //
}


int SetPath() {
    //

    return 0;
}
