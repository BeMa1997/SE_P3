#include "teilnehmerliste.h"

using namespace std;

TeilnehmerListe* TeilnehmerListe::uniqueInstance = nullptr;
list<Klassenmitglied> teilnehmerListe;
QtTeilnehmerDao tDAO;

TeilnehmerListe* TeilnehmerListe::Instance() {
    if(uniqueInstance == nullptr) {
        uniqueInstance = new TeilnehmerListe();
    }

    return uniqueInstance;
}


int TeilnehmerListe::InsertTeilnehmer(Klassenmitglied &km, int id)
{
    teilnehmerListe.insert(teilnehmerListe.end(), km);
    tDAO.Insert(km, id);
    return 0;
}


int TeilnehmerListe::InsertTeilnehmer(Organisator &orga)
{
    //

    return 0;
}


int TeilnehmerListe::ModifyTeilnehmer(Klassenmitglied &km, int id)
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


bool TeilnehmerListe::ContainsTeilnehmer(Klassenmitglied &km)
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
