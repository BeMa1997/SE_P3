#ifndef QTTEILNEHMERDAO_H
#define QTTEILNEHMERDAO_H

#include <QSqlDatabase>
#include <QtSql>
#include <list>
#include "aenderung.h"

class Klassenmitglied;

class QtTeilnehmerDao
{
    public:
        QtTeilnehmerDao();

        //return id des eingefügten km
        int Insert(Klassenmitglied km, int orgaId);
        int Modify(Aenderung aenderung);
        Klassenmitglied Get(int id);
        bool Contains(Klassenmitglied km);
        bool GetTeilnehmerListe(std::list<Klassenmitglied>* liste);
        int SetPath();


    private:
        QSqlDatabase database;
};

#endif // QTTEILNEHMERDAO_H
