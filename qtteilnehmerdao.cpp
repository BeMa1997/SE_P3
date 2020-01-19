#include "qtteilnehmerdao.h"

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
    QSqlQuery query(database);
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


int Modify(Klassenmitglied &km) {
    QSqlQuery query(database);

    int id = km.getId();
    query.prepare("DELETE FROM Klassenmitglied WHERE id==\":id\";");
    query.bindValue(":id", QString::fromStdString(to_string(km.getId())));

    if(query.exec())
    {
        qDebug() << "Ok";
    }
    else
    {
        qDebug() << "Fehler: DELETE-Query geht nicht!";
    }

    query.clear();

    query.prepare("INSERT INTO Klassenmitglied ("
                  "id, "
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
                  ":id, "
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
    query.bindValue(":id", QString::fromStdString(to_string(id)));
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


bool Get(int id, Klassenmitglied& km) {
    QSqlQuery query(database);

    query.prepare("SELECT * FROM Klassenmitglied WHERE id==\":id\";");
    query.bindValue(":id", QString::fromStdString(to_string(id)));

    if(query.exec())
    {
        // query.value(0).toString();

        if (query.next())
        {
            int id = query.value(0).toInt();
            string vorname = query.value(1).toString().toStdString();
            string nachname = query.value(2).toString().toStdString();
            string geburtsname = query.value(3).toString().toStdString();
            string email = query.value(4).toString().toStdString();
            string telnr = query.value(5).toString().toStdString();
            int typ = query.value(6).toInt();
            string kennwort = query.value(7).toString().toStdString();
            string strasse = query.value(8).toString().toStdString();
            string hausnr = query.value(9).toString().toStdString();
            string ort = query.value(10).toString().toStdString();
            string plz = query.value(11).toString().toStdString();
            string land = query.value(12).toString().toStdString();

            Klassenmitglied _km(vorname,
                               nachname,
                               geburtsname,
                               email,
                               kennwort,
                               telnr,
                               Adresse(strasse,
                                       hausnr,
                                       ort,
                                       plz,
                                       land));
            km = _km;
            return true;
        }
    }
    else
    {
        return false;
    }

    return false;
}


bool Contains(Klassenmitglied &km) {

    bool returnValue = false;

    QSqlQuery query(database);

    query.prepare("SELECT EXISTS(SELECT 1 FROM Klassenmitglied WHERE id=\":id\" LIMIT 1);");
    query.bindValue(":id", QString::fromStdString(to_string(km.getId())));

    if(query.exec())
    {
        if (query.next())
        {
            if(query.value(0).toInt() == 1)
            {
                returnValue = true;
            }
        }
    }

    return returnValue;
}


bool GetTeilnehmerListe(list<Klassenmitglied> &lkm) {
    QSqlQuery query(database);

    query.prepare("SELECT * FROM Klassenmitglied;");

    if(query.exec())
    {
        while (query.next())
        {
            int id = query.value(0).toInt();
            string vorname = query.value(1).toString().toStdString();
            string nachname = query.value(2).toString().toStdString();
            string geburtsname = query.value(3).toString().toStdString();
            string email = query.value(4).toString().toStdString();
            string telnr = query.value(5).toString().toStdString();
            int typ = query.value(6).toInt();
            string kennwort = query.value(7).toString().toStdString();
            string strasse = query.value(8).toString().toStdString();
            string hausnr = query.value(9).toString().toStdString();
            string ort = query.value(10).toString().toStdString();
            string plz = query.value(11).toString().toStdString();
            string land = query.value(12).toString().toStdString();

            Klassenmitglied _km(vorname,
                               nachname,
                               geburtsname,
                               email,
                               kennwort,
                               telnr,
                               Adresse(strasse,
                                       hausnr,
                                       ort,
                                       plz,
                                       land));
            lkm.insert(lkm.end(), _km);
        }
        return true;
    }
    else
    {
        return false;
    }

    return false;
}


int SetPath() {
    //

    return 0;
}
