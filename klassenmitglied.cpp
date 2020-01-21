#include "klassenmitglied.h"
#include "teilnehmerliste.h"
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


Klassenmitglied::Klassenmitglied(int id, string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse):adresse(adresse)
{
    this->vorname = vorname;
    this->nachname = nachname;
    this->geburtsname = geburtsname;
    this->eMail = eMail;
    this->kennwort = kennwort;
    this->telNr = telNr;
    this->adresse = adresse;
}


Klassenmitglied::Klassenmitglied(Organisator* km) : Klassenmitglied(km->getId(), km->getVorname(), km->getNachname(), km->getGeburtsname(), km->getEmail(), km->getKennwort(), km->getTelnr(), km->getAdresse())
{
    list<Aenderung> _aenderungsListe = km->GetAenderungListe();
    for (auto it : _aenderungsListe) {
        aendern(it.getKlassenmitglied(), it.getOrganisator()->getId(), *it.getDatum());
        this->GetAenderungListe().back().setId(it.getId());
    }
}


Aenderung* Klassenmitglied::aendern(Klassenmitglied* km, int orgaActorId, Datum dat)
{
    Aenderung* ptrReturn = nullptr;

    Aenderung neueAenderung = Aenderung(orgaActorId, km, dat);
    ptrReturn = &neueAenderung;

    // aenderung zu aenderungsListe des km objekts in der TeilnehmerListe hinzufügen
    TeilnehmerListe::Instance()->GetTeilnehmer(km->getId())->GetAenderungListe().push_back(neueAenderung);

    return ptrReturn;
}


bool Klassenmitglied::operator ==(const Klassenmitglied& d)
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

    // aenderung zu aenderungsListe des km objekts in der TeilnehmerListe hinzufügen
    TeilnehmerListe::Instance()->GetTeilnehmer(km->getId()).GetAenderungListe()->push_back(neueAenderung);

    return ptrReturn;
}

bool Klassenmitglied::aendern(int id, Klassenmitglied* km, int orga, Datum datum)
{
    Aenderung a(id, orga, km, datum);

bool Klassenmitglied::operator !=(const Klassenmitglied& d)
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
