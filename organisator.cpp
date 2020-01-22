#include "organisator.h"
#include "teilnehmerliste.h"

using namespace std;

Organisator::Organisator(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse) : Klassenmitglied(vorname, nachname, geburtsname, eMail, kennwort, telNr, adresse)
{
    // constructor
}


Organisator::Organisator(Klassenmitglied* km) : Klassenmitglied(km->getId(), km->getVorname(), km->getNachname(), km->getGeburtsname(), km->getEmail(), km->getKennwort(), km->getTelnr(), km->getAdresse())
{
    list<Aenderung> _aenderungsListe = km->GetAenderungListe();
    for (auto it : _aenderungsListe) {
        aendern(it.getKlassenmitglied(), it.getOrgaId(), *it.getDatum());
        this->GetAenderungListe().back().setId(it.getId());
    }
}


bool Organisator::KlassenmitgliedAnlegen(Klassenmitglied* km)
{
    bool returnValue = false;

    // check pre-condition
    if ( ! TeilnehmerListe::Instance()->ContainsTeilnehmer(km) )
    {
        //TeilnehmerListe::Instance()->InsertTeilnehmer(*km);
    }

    // check post-condition
    if ( TeilnehmerListe::Instance()->ContainsTeilnehmer(km) )
    {
        returnValue = true;
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
        //TeilnehmerListe::Instance()->ModifyTeilnehmer(*km);
    }

    // check post-condition
    Klassenmitglied* databaseObj = TeilnehmerListe::Instance()->GetTeilnehmer(km->getId());
    if ( databaseObj ==  km)
    {
        returnValue = true;
    }

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


bool Organisator::operator ==(const Organisator& d)
{
    bool returnValue = false;

    if(vorname == d.vorname &&
        nachname == d.nachname &&
        geburtsname == d.geburtsname &&
        eMail == d.eMail &&
        kennwort == d.kennwort &&
        telNr == d.telNr &&
        adresse == d.adresse)
    {
        returnValue = true;
    }

    return returnValue;
}


bool Organisator::operator !=(const Organisator& d)
{
    bool returnValue = false;

    if(vorname != d.vorname ||
        nachname != d.nachname ||
        geburtsname != d.geburtsname ||
        eMail != d.eMail ||
        kennwort != d.kennwort ||
        telNr != d.telNr ||
        adresse != d.adresse)
    {
        returnValue = true;
    }

    return returnValue;
}
