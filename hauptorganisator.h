#ifndef HAUPTORGANISATOR_H
#define HAUPTORGANISATOR_H

#include <organisator.h>

class Hauptorganisator : public Organisator
{
    public:                            
        Hauptorganisator(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse);

        bool KlassenmitgliedZuOrga(Klassenmitglied* km);
        bool OrgaZuKlassenmitglied(Organisator* orga);
        bool PasswortZuruecksetzen(Organisator* orga);

    private:
        //nichts

};

#endif // HAUPTORGANISATOR_H
