#ifndef AENDERUNG_H
#define AENDERUNG_H

#include "datum.h"

class Klassenmitglied;
class Organisator;

class Aenderung
{
    public:
        Aenderung(int id, Organisator* orga, Klassenmitglied* mitglied, Datum datum);

    private:
        int id;
        Organisator* orga;
        Klassenmitglied* mitglied;
        Datum datum;

};

#endif // AENDERUNG_H
