#ifndef QTTEILNEHMERDAO_H
#define QTTEILNEHMERDAO_H

#include <klassenmitglied.h>
#include <vector>
#include <QSqlDatabase>

class QtTeilnehmerDao
{
public:
    QtTeilnehmerDao();

    int InsertTeilnehmer();
    int ModifyTeilnehmer();
    Klassenmitglied GetTeilnehmer();
    bool ContainsTeilnehmer();
    vector<Klassenmitglied> GetTeilnehmerListe();
    bool Attach();
    bool Detach();
    bool Notify();
    int SetPath();

private:
    vector<Klassenmitglied> teilnehmerListe;
    QSqlDatabase database;
};

#endif // QTTEILNEHMERDAO_H
