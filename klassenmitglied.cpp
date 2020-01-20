#include "klassenmitglied.h"
#include "teilnehmerliste.h"


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
    this->id = id;
    this->vorname = vorname;
    this->nachname = nachname;
    this->geburtsname = geburtsname;
    this->eMail = eMail;
    this->kennwort = kennwort;
    this->telNr = telNr;
    this->adresse = adresse;
}


Aenderung* Klassenmitglied::aendern(Klassenmitglied* km, int orgaActorId, Datum dat)
{
    Aenderung* ptrReturn = nullptr;

    Aenderung neueAenderung = Aenderung(orgaActorId, km, dat);
    ptrReturn = &neueAenderung;

    // aenderung zu aenderungsListe des km objekts in der TeilnehmerListe hinzufügen
    TeilnehmerListe::Instance()->GetTeilnehmer(km->getId())->GetAenderungListe()->push_back(neueAenderung);

    return ptrReturn;
}

bool Klassenmitglied::aendern(int id, Klassenmitglied* km, int orga, Datum datum)
{
    Aenderung a(id, orga, km, datum);

    // aenderung zu aenderungsListe des km objekts in der TeilnehmerListe hinzufügen
    TeilnehmerListe::Instance()->GetTeilnehmer(km->getId())->GetAenderungListe()->push_back(a);

    return true;
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
