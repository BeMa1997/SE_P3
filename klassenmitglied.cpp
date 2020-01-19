#include "klassenmitglied.h"
#include "organisator.h"


Klassenmitglied::Klassenmitglied(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse):adresse(adresse)
{
    this->vorname = vorname;
    this->nachname = nachname;
    this->geburtsname = geburtsname;
    this->eMail = eMail;
    this->kennwort = kennwort;
    this->telNr = telNr;
    this->adresse = adresse;
}


bool aendern(Klassenmitglied*, Organisator*, Datum)
{
    bool returnValue = false;

    //BODY

    return returnValue;
}


//bool operator == (Klassenmitglied const &obj1, Klassenmitglied const &obj2)
//{
//    bool returnValue = false;

//    Klassenmitglied km1, km2;
//    km1 = obj1;
//    km2 = obj2;

//    if ( km1.eMail == km2.eMail &&
//      km1.telNr == km2.telNr &&
//      km1.adresse == km2.adresse &&
//      km1.vorname == km2.vorname &&
//      km1.kennwort == km2.kennwort &&
//      km1.nachname == km2.nachname &&
//      km1.geburtsname == km2.geburtsname )
//    {
//     returnValue = true;
//    }

//    return returnValue;
//}
