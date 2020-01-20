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

    // km noch nicht in TeilnehmerListe
    if ( ! TeilnehmerListe::Instance()->ContainsTeilnehmer(km) )
    {
        TeilnehmerListe::Instance()->InsertTeilnehmer(km, this->getId());

        // km jetzt in TeilnehmerListe
        if ( TeilnehmerListe::Instance()->ContainsTeilnehmer(km) )
        {
            returnValue = true;
        }
    }    

    return returnValue;
}


bool Organisator::KlassenmitgliedBearbeiten(Klassenmitglied* km)
{
    bool returnValue = false;

    // check pre-condition
    if ( TeilnehmerListe::Instance()->ContainsTeilnehmer(km) )
    {
        // overwrite all attributes but the id
        TeilnehmerListe::Instance()->ModifyTeilnehmer(km, this->getId());

        // check post-condition
        Klassenmitglied* databaseObj = TeilnehmerListe::Instance()->GetTeilnehmer(km->getId());
        if ( databaseObj ==  km)
        {
            returnValue = true;
        }
    }

    return returnValue;
}


bool Organisator::Logout()
{
    bool returnValue = false;

    // wenn der organisator, welcher "logout" aufruft, auch wirklich der eingeloggte user ist:
    if ( reinterpret_cast<Klassenmitglied*>(this) == TeilnehmerListe::Instance()->getCurrentUser() )
    {
        // currentUser := null
        TeilnehmerListe::Instance()->setCurrentUser(nullptr);

        // wenn Zuweisung funktioniert hat, erfolgreich terminieren
        if ( TeilnehmerListe::Instance()->getCurrentUser() == nullptr )
        {
            returnValue = true;
        }
    }

    return returnValue;
}


bool Organisator::PasswortAendern(string alt, string neu)
{
    bool returnValue = false;
    Klassenmitglied* curr = TeilnehmerListe::Instance()->getCurrentUser();

    // aktuell eingeloggt und credentials geprüft
    if ( this == curr && this->getKennwort() == alt )
    {
        // kennwort überschreiben
        this->setKennwort(neu);

        // Änderungen an TeilnehmerListe übergeben
        TeilnehmerListe::Instance()->ModifyTeilnehmer(this, this->getId());

        // passwort entspricht dem gesetzten Wert
        if( this->getKennwort() == TeilnehmerListe::Instance()->getCurrentUser()->getKennwort() )
        {
            returnValue = true;
        }
    }

    return returnValue;
}
