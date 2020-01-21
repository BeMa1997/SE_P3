#include "teilnehmerliste.h"
#include "organisator.h"

using namespace std;

TeilnehmerListe* TeilnehmerListe::uniqueInstance = nullptr;
Klassenmitglied* TeilnehmerListe::currentUser = nullptr;

TeilnehmerListe* TeilnehmerListe::Instance() {
    if(uniqueInstance == nullptr) {
        uniqueInstance = new TeilnehmerListe();
    }

    return uniqueInstance;
}


int TeilnehmerListe::InsertTeilnehmer(Klassenmitglied* km, int orgaId)
{
    // km in TeilnehmerListe einfügen (ohne id)
    teilnehmerListe.push_back(*km);

    // km in Datenbank einfügen (id wird dort zugewiesen)
    int ret = tDAO.Insert(*km, orgaId);

    // ID in das Objekt in TeilnehmerListe hinzufügen
    TeilnehmerListe::Instance()->GetTeilnehmer(km->getId())->setId(ret);

    return ret;
}

bool TeilnehmerListe::loadTeilnehmerListe()
{
    tDAO.GetTeilnehmerListe(&teilnehmerListe);
}


int TeilnehmerListe::ModifyTeilnehmer(Klassenmitglied* km, int orgaId)
{
    int retVal = 1;
    Klassenmitglied* left = km;
    Klassenmitglied* right = TeilnehmerListe::Instance()->GetTeilnehmer(km->getId());


    if ( left->getVorname() != right->getVorname() )
    {
        right->setVorname( left->getVorname() );
    }

    if ( left->getNachname() != right->getNachname() )
    {
        right->setNachname( left->getNachname() );
    }

    if ( left->getGeburtsname() != right->getGeburtsname() )
    {
        right->setGeburtsname( left->getGeburtsname() );
    }

    if ( left->getEmail() != right->getEmail() )
    {
        right->setEmail( left->getEmail() );
    }

    if ( left->getKennwort() != right->getKennwort() )
    {
        right->setKennwort( left->getKennwort() );
    }

    if ( left->getTelnr() != right->getTelnr() )
    {
        right->setTelnr( left->getTelnr() );
    }

    if ( left->getAdresse() != right->getAdresse() )
    {
        right->setAdresse( left->getAdresse() );
    }

    // schreibe Aenderungen aus TeilnehmerListe nach Datenbank
    Aenderung writeBack = Aenderung(orgaId, left, Datum());

    retVal = tDAO.Modify(writeBack);


    return retVal;
}


Klassenmitglied* TeilnehmerListe::GetTeilnehmer(int orgaId)
{
    Klassenmitglied* kmOut = nullptr;

    for(auto x : teilnehmerListe)
    {
        if ( x.getId() == orgaId )
        {
            kmOut = &x;
            break;
        }
    }

    return kmOut;
}


Klassenmitglied TeilnehmerListe::GetTeilnehmer(int id)
{
    return tDAO.Get(id);
}


Klassenmitglied* TeilnehmerListe::GetTeilnehmer(string eMail)
{
    Klassenmitglied* kmOut = nullptr;

    for(auto x : teilnehmerListe)
    {
        if ( x.getEmail() == eMail )
        {
            kmOut = &x;
            break;
        }
    }

    return kmOut;
}


bool TeilnehmerListe::ContainsTeilnehmer(Klassenmitglied* km)
{
    bool returnValue = false;

    for(auto x : teilnehmerListe)
    {
        if ( &x == km )
        {
            returnValue = true;
            break;
        }
    }

    return returnValue;
}


// überprüft ob Organisator orga in der TeilnehmerListe enthalten ist (anhand des gesamten Objekts)
bool TeilnehmerListe::ContainsTeilnehmer(Organisator* orga)
{
    bool returnValue = false;

    for(auto x : teilnehmerListe)
    {
        if ( &x == reinterpret_cast<Klassenmitglied*>(orga) )
        {
            returnValue = true;
            break;
        }
    }

    return returnValue;
}


// überprüft ob Klassenmitglied km in der TeilnehmerListe enthalten ist (anhand seiner unique eMail)
bool TeilnehmerListe::ContainsTeilnehmer(string eMail)
{
    bool returnValue = false;

    for(auto x : teilnehmerListe)
    {
        if ( x.getEmail() == eMail )
        {
            returnValue = true;
            break;
        }
    }

    return returnValue;
}


// loggt einen user lokal ein
bool TeilnehmerListe::Login(string eMail, string kennwort)
{
    bool returnValue = false;
    Klassenmitglied* userToLogin;

    // Teilnehmer mit eMail in TeilnehmerListe enthalten
    if ( ContainsTeilnehmer(eMail) )
    {
        userToLogin = GetTeilnehmer(eMail);

        // Validierung der user credentials erfolgreich
        if(userToLogin->getKennwort() == kennwort)
        {
            currentUser = userToLogin;
            returnValue = true;
        }
    }

    return returnValue;
}


int TeilnehmerListe::ToOrganisator(Klassenmitglied* km, int orgaId)
{
    int retVal = 0;

    // km in TeilnehmerListe?
    if( TeilnehmerListe::Instance()->ContainsTeilnehmer(km) )
    {
        // km zu orga kopieren
        Organisator orga = Organisator(km);

        // km aus TeilnehmerListe löschen
        teilnehmerListe.remove(*km);

        // organisator in TeilnehmerListe einfügen
        teilnehmerListe.push_back(orga);

        // organisator zu Datenbank synchronisieren
        Aenderung change = Aenderung(orgaId, &orga, Datum());

        int index = tDAO.Modify(change);
        change.setId(index);

    }

    return retVal;
}


int TeilnehmerListe::ToKlassenmitglied(Organisator *orga, int orgaId)
{
    int retVal = 0;

    // orga in TeilnehmerListe?
    if( TeilnehmerListe::Instance()->ContainsTeilnehmer(orga) )
    {
        // orga zu km kopieren
        Klassenmitglied km = Klassenmitglied(orga);

        // orga aus TeilnehmerListe löschen
        for(auto it = teilnehmerListe.begin(); it != teilnehmerListe.end(); it++)
        {
            if ( it->getId() == orga->getId() )
            {
                teilnehmerListe.erase(it);
                break;
            }
        }

        // km in TeilnehmerListe einfügen
        teilnehmerListe.push_back(km);

        // km zu Datenbank synchronisieren
        Aenderung change = Aenderung(orgaId, &km, Datum());

        int index = tDAO.Modify(change);
        change.setId(index);

    }

    return retVal;
}
