#ifndef QTTEILNEHMERDAO_H
#define QTTEILNEHMERDAO_H

#include <klassenmitglied.h>
#include <vector>
#include <QSqlDatabase>
#include <map>

class QtTeilnehmerDao
{
    public:
        QtTeilnehmerDao();

        int Insert();
        int Modify();
        Klassenmitglied Get();
        bool Contains();
        map<const int, Klassenmitglied> GetTeilnehmerListe();
        int SetPath();

    private:
        map<const int, Klassenmitglied> teilnehmerListe;
        QSqlDatabase database;
};

#endif // QTTEILNEHMERDAO_H
