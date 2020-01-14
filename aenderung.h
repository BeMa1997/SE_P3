#ifndef AENDERUNG_H
#define AENDERUNG_H

#include <organisator.h>
#include <datum.h>
#include <klassenmitglied.h>


class Aenderung
{
public:
    Aenderung();
private:
    int id;
    Organisator* orga;
    Datum datum;
    Klassenmitglied* mitglied;

};

#endif // AENDERUNG_H
