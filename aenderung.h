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
        Organisator* getOrganisator(){return orga;}
        Datum* getDatum(){return &datum;}

        int getId(){return id;}
        void setId(int id){this->id = id;}

    private:
        int id;
        Organisator* orga;
        Klassenmitglied* mitglied;
        Datum datum;

};

#endif // AENDERUNG_H
