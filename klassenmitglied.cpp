#include "klassenmitglied.h"
#include "organisator.h"

Klassenmitglied::Klassenmitglied(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr): adresse()
{
    this->vorname = vorname;
    this->nachname = nachname;
    this->geburtsname = geburtsname;
    this->eMail = eMail;
    this->kennwort = kennwort;
    this->telNr = telNr;
}


bool aendern(Klassenmitglied*, Organisator*, Datum)
{
    bool returnValue = false;

    //BODY

    return returnValue;
}