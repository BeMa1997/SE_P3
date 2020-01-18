#ifndef QTTEILNEHMERDAO_H
#define QTTEILNEHMERDAO_H

#include "qtteilnehmerdaoi.h"

class QtTeilnehmerDao : public QtTeilnehmerDaoI
{
public:
    QtTeilnehmerDao();

    static QtTeilnehmerDao* Instance();

private:
    QtTeilnehmerDao obj; //singleton object

};

#endif // QTTEILNEHMERDAO_H
