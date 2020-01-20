#ifndef QTTEILNEHMERDAO_H
#define QTTEILNEHMERDAO_H

#include <QSqlDatabase>
#include <QtSql>
#include <list>

class Klassenmitglied;

class QtTeilnehmerDao
{
    public:
        QtTeilnehmerDao();

        int Insert(Klassenmitglied &km, int id);
        int Modify(Klassenmitglied &km, int id);
        bool Get(int id, Klassenmitglied &km);
        bool Contains(Klassenmitglied &km);
        bool GetTeilnehmerListe(std::list<Klassenmitglied> &liste);
        int SetPath();


    private:
        QSqlDatabase database;
};

#endif // QTTEILNEHMERDAO_H
