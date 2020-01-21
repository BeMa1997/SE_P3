#ifndef AENDERUNG_H
#define AENDERUNG_H

#include "datum.h"

class Klassenmitglied;
class Organisator;

class Aenderung
{
    public:
        Aenderung(int orgaId, Klassenmitglied* mitglied, Datum datum);

        Klassenmitglied* getKlassenmitglied(){return mitglied;}
        int getOrgaId(){return orga_id;}
        Datum* getDatum(){return &datum;}

        int getId(){return id;}
        void setId(int id){this->id = id;}

    private:
        int id;
        int orga_id;
        Klassenmitglied* mitglied;
        Datum datum;

};

#endif // AENDERUNG_H
