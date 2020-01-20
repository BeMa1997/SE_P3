#ifndef AENDERUNG_H
#define AENDERUNG_H

#include "datum.h"

class Klassenmitglied;
class Organisator;

class Aenderung
{
    public:
        Aenderung(int, int, Klassenmitglied*, Datum);
        Aenderung(int, Klassenmitglied*, Datum);
        int getId(){return id;}
        Klassenmitglied* getKlassenmitglied(){return mitglied;}
        int getOrgaId(){return orga_id;}
        Datum* getDatum(){return &datum;}
    private:
        int id;
        int orga_id;
        Klassenmitglied* mitglied;
        Datum datum;

};

#endif // AENDERUNG_H
