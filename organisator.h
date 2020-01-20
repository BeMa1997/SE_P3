#ifndef ORGANISATOR_H
#define ORGANISATOR_H

#include "klassenmitglied.h"
#include <string>

class TeilnehmerListe;

class Organisator : public Klassenmitglied
{
    public:
        Organisator(int id, std::string vorname, std::string nachname, std::string geburtsname, std::string eMail, std::string kennwort, std::string telNr, Adresse adresse);
        Organisator(std::string vorname, std::string nachname, std::string geburtsname, std::string eMail, std::string kennwort, std::string telNr, Adresse adresse);

        bool KlassenmitgliedAnlegen(Klassenmitglied* km);
        bool KlassenmitgliedBearbeiten(Klassenmitglied* km);

        bool Logout();
        bool PasswortAendern(std::string alt, std::string neu);

        bool operator ==(const Organisator& d);
    private:
        //nichts

};

#endif // ORGANISATOR_H
