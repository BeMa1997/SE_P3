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

    //

    return returnValue;
}


bool Hauptorganisator::OrgaZuKlassenmitglied(Organisator* orga)
{
    bool returnValue = false;

    //

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
