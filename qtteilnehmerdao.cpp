#include "qtteilnehmerdao.h"
#include "hauptorganisator.h"
#include <string>

using namespace std;

QtTeilnehmerDao::QtTeilnehmerDao() {
    if(!QFile::exists("klassentreffen.db"))
    {

        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("klassentreffen.db");
        if (!database.open())
        {
            qDebug() << "Fehler: Keine Datenbank-Anbindung möglich!";
        }
        else
        {
            qDebug() << "OK: Datenbank verbunden.";
        }

        if(QFile::exists("klassentreffen_schema.sql"))
        {
            QSqlQuery query(database);
            qDebug() << "Not exist...";
            QFile schemaFile("klassentreffen_schema.sql");
            schemaFile.open(QFile::ReadOnly);
            QStringList schemaTableList = QString(schemaFile.readAll()).split(";");
            foreach(const QString schemaTable, schemaTableList)
            {
                query.exec(schemaTable);
            }
            qDebug() << "Vor close...!";
            schemaFile.close();
            qDebug() << "Nach close...";
            query.clear();
        }
        else
        {
            qDebug() << "Fehler: Schema-Datei nicht gefunden!";
        }
    }
    else
    {
        qDebug() << "Lol";
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("klassentreffen.db");
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


int QtTeilnehmerDao::Insert(Klassenmitglied km, int orga_id) {
    QSqlQuery query(database);
    query.prepare("INSERT INTO Klassenmitglied ("
                  //"id, "
                  "vorname, "
                  "nachname, "
                  "geburtsname, "
                  "email, "
                  "teln, "
                  "typ, "
                  "kennwort, "
                  "strasse, "
                  "hausnr, "
                  "ort, "
                  "plz, "
                  "land) "
                  "VALUES ("
                  //":id, "
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
                  ":land)");
    //query.bindValue(":id", 0);
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
                return -1;
            }
        }
    }
    query.bindValue(":kennwort", QString::fromStdString(km.getKennwort()));
    query.bindValue(":strasse", QString::fromStdString(km.getStrasse()));
    query.bindValue(":hausnr", QString::fromStdString(km.getHausnummer()));
    query.bindValue(":ort", QString::fromStdString(km.getOrt()));
    query.bindValue(":plz", QString::fromStdString(km.getPlz()));
    query.bindValue(":land", QString::fromStdString(km.getLand()));

    if(query.exec())
    {

        return query.lastInsertId().toInt();
    }
    else
    {
        return 1;
    }

    return 1;
}


int QtTeilnehmerDao::Modify(Aenderung aenderung) {
    QSqlQuery query(database);

    query.prepare("INSERT INTO Aenderung ("
    "id, "
    "tag, "
    "monat, "
    "jahr, "
    "vorname, "
    "nachname, "
    "geburtsname, "
    "email, "
    "teln, "
    "typ, "
    "kennwort, "
    "strasse, "
    "hausnr, "
    "ort, "
    "plz, "
    "land, "
    "erfasst, "
    "taetigt) "
    "VALUES ("
    ":id, "
    ":tag, "
    ":monat, "
    ":jahr, "
    ":vorname, "
    ":nachname, "
    ":geburtsname,"
    ":email, "
    ":teln, "
    ":typ, "
    ":kennwort, "
    ":strasse, "
    ":hausnr, "
    ":ort, "
    ":plz, "
    ":land, "
    ":erfasst, "
    ":taetigt)");
    query.bindValue(":id", aenderung.getId());
    query.bindValue(":vorname", QString::fromStdString(aenderung.getKlassenmitglied()->getVorname()));
    query.bindValue(":nachname", QString::fromStdString(aenderung.getKlassenmitglied()->getNachname()));
    query.bindValue(":geburtsname", QString::fromStdString(aenderung.getKlassenmitglied()->getGeburtsname()));
    query.bindValue(":email", QString::fromStdString(aenderung.getKlassenmitglied()->getEmail()));
    query.bindValue(":teln", QString::fromStdString(aenderung.getKlassenmitglied()->getTelnr()));
    if(typeid(aenderung.getKlassenmitglied()).name() == typeid(Klassenmitglied).name())
    {
        query.bindValue(":typ", "1");
    }
    else
    {
        if(typeid(aenderung.getKlassenmitglied()).name() == typeid(Organisator).name())
        {
            query.bindValue(":typ", "2");
        }
        else
        {
            if(typeid(aenderung.getKlassenmitglied()).name() == typeid(Hauptorganisator).name())
            {
                query.bindValue(":typ", "3");
            }
            else
            {
                qDebug() << "Fehler: Kein gültiger Typ!";
            }
        }
    }
    query.bindValue(":kennwort", QString::fromStdString(aenderung.getKlassenmitglied()->getKennwort()));
    query.bindValue(":strasse", QString::fromStdString(aenderung.getKlassenmitglied()->getStrasse()));
    query.bindValue(":hausnummer", QString::fromStdString(aenderung.getKlassenmitglied()->getHausnummer()));
    query.bindValue(":ort", QString::fromStdString(aenderung.getKlassenmitglied()->getOrt()));
    query.bindValue(":plz", QString::fromStdString(aenderung.getKlassenmitglied()->getPlz()));
    query.bindValue(":land", QString::fromStdString(aenderung.getKlassenmitglied()->getLand()));

    if(query.exec())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


bool QtTeilnehmerDao::Get(int id, Klassenmitglied &km) {
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


bool QtTeilnehmerDao::Contains(Klassenmitglied km) {

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


bool QtTeilnehmerDao::GetTeilnehmerListe(list<Klassenmitglied> lkm) {
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

            Klassenmitglied *_km = nullptr;
            if(typ == 1)
            {
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
            }
            else
            {
                if(typ == 2)
                {
                    Organisator _km(vorname,
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
                }
                else
                {
                    Hauptorganisator _km(vorname,
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
                }
            }

            lkm.insert(lkm.end(), *_km);
        }
        return true;
    }
    else
    {
        return false;
    }

    return false;
}


int QtTeilnehmerDao::SetPath() {
    //

    return 0;
}
