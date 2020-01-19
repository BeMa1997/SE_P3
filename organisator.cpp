#include "organisator.h"
#include "klassenmitglied.h"
#include "qtteilnehmerdao.h"

Organisator::Organisator(): Klassenmitglied()
{

}


bool KlassenmitgliedAnlegen(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr)
{
    bool returnValue = false;

    Klassenmitglied* km = new Klassenmitglied(vorname, nachname, geburtsname, eMail,  kennwort, telNr);
    QtTeilnehmerDao::Instance()->InsertTeilnehmer(km);

    if ( QtTeilnehmerDao::Instance()->ContainsTeilnehmer(km) )
    {
        returnValue = true;
    }

    return returnValue;
}


bool KlassenmitgliedBearbeiten(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr)
{
    //
}


bool Login(string eMail, string password)
{
    //
}


bool Logout()
{
    //
}


bool PasswortAendern(string alt, string neu)
{
    //
}
