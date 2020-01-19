#include "organisator.h"

using namespace std;

Organisator::Organisator(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse) : Klassenmitglied(vorname, nachname, geburtsname, eMail, kennwort, telNr, adresse)
{
    // constructor
}

bool Organisator::KlassenmitgliedAnlegen(TeilnehmerListe &liste, Klassenmitglied &km)
{
    bool returnValue = false;

//    // check pre-condition
//    if ( !liste.ContainsTeilnehmer(km) )
//    {
//        liste.InsertTeilnehmer(km);
//    }

//    // check post-condition
//    if ( liste.ContainsTeilnehmer(km) )
//    {
//        returnValue = true;
//    }

    return returnValue;
}


bool Organisator::KlassenmitgliedBearbeiten(TeilnehmerListe &liste, Klassenmitglied &km)
{
    bool returnValue = false;

//    // check pre-condition
//    if ( TeilnehmerListe::Instance()->ContainsTeilnehmer(km) )
//    {
//        // overwrite all attributes but the id
//        liste.ModifyTeilnehmer(km);
//    }

//    // check post-condition
//    if ( liste.GetTeilnehmer() ==  &km)
//    {
//        returnValue = true;
//    }

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
