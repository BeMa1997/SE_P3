#ifndef ORGANISATOR_H
#define ORGANISATOR_H

#include <klassenmitglied.h>

class Organisator : public Klassenmitglied
{
public:
    Organisator();
    ~Organisator();

    // bool KlassenmitgliedAnlegen(String[] args);ueüberladung
    //bool KlassenmitgliedAnlegen(Klassenmitglied* km);
    bool KlassenmitgliedAnlegen(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr);

    //bool KlassenmitgliedBearbeiten(Klassenmitglied* km);
    bool KlassenmitgliedBearbeiten(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr);

    bool Login(string eMail, string password);
    bool Logout();
    bool PasswortAendern(string alt, string neu);

private:
    //nichts

};

#endif // ORGANISATOR_H
