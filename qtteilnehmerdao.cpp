#include "qtteilnehmerdao.h"
#include "hauptorganisator.h"
#include <string>


QSqlDatabase database;
//Klassenmitglied _tmpKm = Klassenmitglied();

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
        return -1;
    }

    return -1;
}


int QtTeilnehmerDao::Modify(Aenderung aenderung) {
    QSqlQuery query(database);

    query.prepare("INSERT INTO Aenderung ("
    //"id, "
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
    //":id, "
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
                return -1;
            }
        }
    }
    query.bindValue(":kennwort", QString::fromStdString(aenderung.getKlassenmitglied()->getKennwort()));
    query.bindValue(":strasse", QString::fromStdString(aenderung.getKlassenmitglied()->getStrasse()));
    query.bindValue(":hausnr", QString::fromStdString(aenderung.getKlassenmitglied()->getHausnummer()));
    query.bindValue(":ort", QString::fromStdString(aenderung.getKlassenmitglied()->getOrt()));
    query.bindValue(":plz", QString::fromStdString(aenderung.getKlassenmitglied()->getPlz()));
    query.bindValue(":land", QString::fromStdString(aenderung.getKlassenmitglied()->getLand()));
    query.bindValue(":erfasst", aenderung.getKlassenmitglied()->getId());
    query.bindValue(":taetigt", aenderung.getOrgaId());

    Klassenmitglied* tmp_km = nullptr;

    //Get(aenderung.getKlassenmitglied()->getId(), *tmp_km);

    //qDebug

    if(query.exec())
    {
        return query.lastInsertId().toInt();
    }
    else
    {
        return -1;
    }

    return -1;
}


Klassenmitglied QtTeilnehmerDao::Get(int id) {
    QSqlQuery query(database);

    query.prepare("SELECT * FROM Klassenmitglied WHERE id==:id;");
    query.bindValue(":id", id);

    if(query.exec())
    {
        qDebug() << "In exec!";
        // query.value(0).toString();

        if (query.next())
        {
            id = query.value(0).toInt();
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

            Klassenmitglied _tmpKm = Klassenmitglied();
            if(typ == 1)
            {
                _tmpKm = Klassenmitglied(id,
                                   vorname,
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
                    _tmpKm = Organisator(id,
                                       vorname,
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
                    if(typ == 3)
                    {
                        _tmpKm = Hauptorganisator(id,
                                           vorname,
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
            }


            qDebug() << "Debug ID (GET)";
            qDebug() << _tmpKm.getId();
            return _tmpKm;
        }
    }
    else
    {
        //return nullptr;
    }

    //return nullptr;
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


bool QtTeilnehmerDao::GetTeilnehmerListe(list<Klassenmitglied>* lkm) {
    QSqlQuery query(database);
    QSqlQuery query_inner(database);

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

            qDebug() << "KM:";
            qDebug() << id;

            Klassenmitglied *_km = nullptr;
            if(typ == 1)
            {
                _km = new Klassenmitglied(id,
                                   vorname,
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
                    _km = new Organisator(id,
                                       vorname,
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
                    _km = new Hauptorganisator(id,
                                       vorname,
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

            // TODO: Änderungen!
            // aendern(Klassenmitglied* km, int orga_id, Datum datum)
            query_inner.prepare("SELECT * FROM Aenderung WHERE erfasst=:kmid ORDER BY id ASC");
            query_inner.bindValue(":kmid", _km->getId());

            while (query_inner.next())
            {
                int id = query_inner.value(0).toInt();
                int tag = query_inner.value(1).toInt();
                int monat = query_inner.value(2).toInt();
                int jahr = query_inner.value(3).toInt();
                string vorname = query_inner.value(4).toString().toStdString();
                string nachname = query_inner.value(5).toString().toStdString();
                string geburtsname = query_inner.value(6).toString().toStdString();
                string email = query_inner.value(7).toString().toStdString();
                string telnr = query_inner.value(8).toString().toStdString();
                int typ = query_inner.value(9).toInt();
                string kennwort = query_inner.value(10).toString().toStdString();
                string strasse = query_inner.value(11).toString().toStdString();
                string hausnr = query_inner.value(12).toString().toStdString();
                string ort = query_inner.value(13).toString().toStdString();
                string plz = query_inner.value(14).toString().toStdString();
                string land = query_inner.value(15).toString().toStdString();
                int k_id = query_inner.value(16).toInt();
                int orga_id = query_inner.value(17).toInt();

                Klassenmitglied *_km1 = nullptr;
                if(typ == 1)
                {
                    _km1 = new Klassenmitglied(k_id,
                                       vorname,
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
                        _km1 = new Organisator(k_id,
                                           vorname,
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
                        _km1 = new Hauptorganisator(k_id,
                                           vorname,
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
                } // END TYP-if

                Datum dt(tag, monat, jahr);
                _km->aendern(id, _km1, orga_id, dt);

            } // END INNER-WHILE

            lkm->push_back(*_km);
            //lkm.insert(lkm.end(), *_km);
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
