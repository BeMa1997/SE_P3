#include "teilnehmerliste.h"

using namespace std;

TeilnehmerListe* TeilnehmerListe::uniqueInstance = nullptr;
Klassenmitglied* TeilnehmerListe::currentUser = nullptr;
list<Klassenmitglied> teilnehmerListe;

TeilnehmerListe* TeilnehmerListe::Instance() {
    if(uniqueInstance == nullptr) {
        uniqueInstance = new TeilnehmerListe();
    }

    return uniqueInstance;
}

// fügt Klassenmitglied der TeilnehmerListe hinzu
// gibt id des objekts in der Datenbank zurück
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


int TeilnehmerListe::ModifyTeilnehmer(Klassenmitglied km, int id)
{
    //
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

bool TeilnehmerListe::ContainsTeilnehmer(Klassenmitglied km)
{
    bool returnValue = false;

    //

    return returnValue;
}


// was soll diese Funktion tun?
int TeilnehmerListe::SetPath(string path)
{
    //

    return 0;
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
