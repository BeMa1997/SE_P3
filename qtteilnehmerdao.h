#ifndef QTTEILNEHMERDAO_H
#define QTTEILNEHMERDAO_H

#include <klassenmitglied.h>
#include <organisator.h>
#include <hauptorganisator.h>
#include <vector>
#include <QSqlDatabase>
#include <list>

class QtTeilnehmerDao
{
    public:
        QtTeilnehmerDao();

        int Insert(Klassenmitglied &km);
        int Modify(Klassenmitglied &km);
        Klassenmitglied Get();
        bool Contains(Klassenmitglied &km);
        bool GetTeilnehmerListe(list<Klassenmitglied>*);
        int SetPath();

    private:
        QSqlDatabase database;
};

#endif // QTTEILNEHMERDAO_H
