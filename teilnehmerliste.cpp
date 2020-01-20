#include "teilnehmerliste.h"

using namespace std;

TeilnehmerListe* TeilnehmerListe::uniqueInstance = nullptr;
list<Klassenmitglied> teilnehmerListe;

TeilnehmerListe* TeilnehmerListe::Instance() {
    if(uniqueInstance == nullptr) {
        uniqueInstance = new TeilnehmerListe();
    }

    return uniqueInstance;
}


int TeilnehmerListe::InsertTeilnehmer(Klassenmitglied km, int id)
{
    teilnehmerListe.insert(teilnehmerListe.end(), km);
    int new_id = tDAO.Insert(km, id);
    return 0;
}


int TeilnehmerListe::ModifyTeilnehmer(Klassenmitglied km, int id)
{
    //
}


Klassenmitglied* TeilnehmerListe::GetTeilnehmer(int id)
{
    //
}


Klassenmitglied* TeilnehmerListe::GetTeilnehmer(string eMail)
{
    //
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

    if ( ContainsTeilnehmer(eMail) )
    {
        currentUser = GetTeilnehmer(eMail);
        returnValue = true;
    }

    return returnValue;
}
