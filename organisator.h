#ifndef ORGANISATOR_H
#define ORGANISATOR_H

#include <klassenmitglied.h>

class Organisator : public Klassenmitglied
{
public:
    Organisator();
    bool KlassenmitgliedAnlegen(Klassenmitglied* km);
    // bool KlassenmitgliedAnlegen(String[] args);ueüberladung
    bool KlassenmitgliedBearbeiten(Klassenmitglied* km);
    bool Login(string eMail, string password);
    bool Logout();
    bool PasswortAendern(string alt, string neu);

private:
    //nichts

};

#endif // ORGANISATOR_H
