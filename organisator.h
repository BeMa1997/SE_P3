#ifndef ORGANISATOR_H
#define ORGANISATOR_H

#include <klassenmitglied.h>
#include <teilnehmerliste.h>

class Organisator : public Klassenmitglied
{
    public:
        Organisator(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse);

        bool KlassenmitgliedAnlegen(TeilnehmerListe &liste, Klassenmitglied &km);
        bool KlassenmitgliedBearbeiten(TeilnehmerListe &liste, Klassenmitglied &km);

        bool Login(string eMail, string password);
        bool Logout();
        bool PasswortAendern(string alt, string neu);

    private:
        //nichts

};

#endif // ORGANISATOR_H
