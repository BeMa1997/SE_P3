#ifndef AENDERUNG_H
#define AENDERUNG_H

#include <organisator.h>
#include <datum.h>
#include <klassenmitglied.h>


class Aenderung
{
public:
    Aenderung(int id, Organisator* orga, Klassenmitglied* mitglied, Datum datum);
    ~Aenderung();

private:
    int id;
    Organisator* orga;
    Klassenmitglied* mitglied;
    Datum datum;

};

#endif // AENDERUNG_H
