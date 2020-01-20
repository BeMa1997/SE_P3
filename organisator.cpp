#include "organisator.h"
#include "teilnehmerliste.h"

using namespace std;

Organisator::Organisator(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse) : Klassenmitglied(vorname, nachname, geburtsname, eMail, kennwort, telNr, adresse)
{
    // constructor
}

bool Organisator::KlassenmitgliedAnlegen(Klassenmitglied* km)
{
    bool returnValue = false;

    // check pre-condition
    if ( ! TeilnehmerListe::Instance()->ContainsTeilnehmer(*km) )
    {
        TeilnehmerListe::Instance()->InsertTeilnehmer(*km);
    }

    // check post-condition
    if ( TeilnehmerListe::Instance()->ContainsTeilnehmer(*km) )
    {
        returnValue = true;
    }

    return returnValue;
}


bool Organisator::KlassenmitgliedBearbeiten(Klassenmitglied* km)
{
    bool returnValue = false;

    // check pre-condition
    if ( TeilnehmerListe::Instance()->ContainsTeilnehmer(*km) )
    {
        // overwrite all attributes but the id
        TeilnehmerListe::Instance()->ModifyTeilnehmer(*km);
    }

    // check post-condition
    Klassenmitglied* databaseObj = TeilnehmerListe::Instance()->GetTeilnehmer(km->getId());
    if ( databaseObj ==  km)
    {
        returnValue = true;
    }

    return returnValue;
}


bool Organisator::Login(string eMail, string password)
{
    bool returnValue = false;

    //

    return returnValue;
}


bool Organisator::Logout()
{
    bool returnValue = false;

    //

    return returnValue;
}


bool Organisator::PasswortAendern(string alt, string neu)
{
    bool returnValue = false;

    //Klassenmitglied km = TeilnehmerListe::Instance()->GetTeilnehmer(eMail);

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
