#include "hauptorganisator.h"
#include "teilnehmerliste.h"

using namespace std;

Hauptorganisator::Hauptorganisator(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse):Organisator(vorname, nachname, geburtsname, eMail, kennwort, telNr, adresse)
{
    //const
}


bool Hauptorganisator::KlassenmitgliedZuOrga(Klassenmitglied* km)
{
    bool returnValue = false;

    // km zu orga, rückgabe prüfen
    if( TeilnehmerListe::Instance()->ToOrganisator(km, this->getId()) == 0 )
    {
        returnValue = true;
    }

    return returnValue;
}


bool Hauptorganisator::OrgaZuKlassenmitglied(Organisator* orga)
{
    bool returnValue = false;

    // orga zu km, rückgabe prüfen
    if( TeilnehmerListe::Instance()->ToKlassenmitglied(orga, this->getId()) == 0 )
    {
        returnValue = true;
    }

    return returnValue;
}


bool Hauptorganisator::PasswortZuruecksetzen(Organisator* orga, string pwNeu)
{
    bool returnValue = false;

    // Nutzer für den das passwort zurückgesetzt werden soll, existiert in der TeilnehmerListe
    if( TeilnehmerListe::Instance()->ContainsTeilnehmer( orga ) )
    {
        // Passwort des Nutzers in TeilnehmerListe überschreiben
        TeilnehmerListe::Instance()->GetTeilnehmer(orga->getId())->setKennwort(pwNeu);

        // Passwort wurde erfolgreich übernommen
        if( TeilnehmerListe::Instance()->GetTeilnehmer(orga->getId())->getKennwort() == pwNeu )
        {
            returnValue = true;
        }
    }

    return returnValue;
}
