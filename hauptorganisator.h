#ifndef HAUPTORGANISATOR_H
#define HAUPTORGANISATOR_H

#include "organisator.h"
#include "adresse.h"

class Hauptorganisator : public Organisator
{
    public:
        Hauptorganisator(int id, std::string vorname, std::string nachname, std::string geburtsname, std::string eMail, std::string kennwort, std::string telNr, Adresse adresse):Organisator(id, vorname, nachname, geburtsname, eMail, kennwort, telNr, adresse){};
        Hauptorganisator(std::string vorname, std::string nachname, std::string geburtsname, std::string eMail, std::string kennwort, std::string telNr, Adresse adresse):Organisator(vorname, nachname, geburtsname, eMail, kennwort, telNr, adresse){};

        bool KlassenmitgliedZuOrga(Klassenmitglied* km);
        bool OrgaZuKlassenmitglied(Organisator* orga);
        bool PasswortZuruecksetzen(Organisator* orga);

    private:
        //nichts

};

#endif // HAUPTORGANISATOR_H
