#ifndef QTTEILNEHMERDAOI_H
#define QTTEILNEHMERDAOI_H

#include <vector>
#include <QSqlDatabase>
#include "klassenmitglied.h"
//#include "qtteilnehmerdao.h"

using namespace std;
//
class QtTeilnehmerDao;
class QtTeilnehmerDaoI
{
public:
    QtTeilnehmerDaoI(){}
    virtual ~QtTeilnehmerDaoI(){}

    virtual QtTeilnehmerDao* Instance() = 0;
    virtual int InsertTeilnehmer() = 0;
    virtual int ModifyTeilnehmer() = 0;
    virtual Klassenmitglied GetTeilnehmer() = 0;
    virtual bool ContainsTeilnehmer() = 0;
    virtual vector<Klassenmitglied> GetTeilnehmerListe() = 0;
    virtual bool Attach() = 0;
    virtual bool Detach() = 0;
    virtual bool Notify() = 0;
    virtual int SetPath() = 0;


private:
    QtTeilnehmerDao uniqueInstance;
    vector<Klassenmitglied> teilnehmerListe;
    QSqlDatabase database;
};

#endif // QTTEILNEHMERDAOI_H
