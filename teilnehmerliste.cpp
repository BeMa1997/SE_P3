#include "teilnehmerliste.h"

TeilnehmerListe* TeilnehmerListe::uniqueInstance = nullptr;
list<Klassenmitglied> teilnehmerListe;
QtTeilnehmerDao tDAO;

TeilnehmerListe* TeilnehmerListe::Instance() {
    if(uniqueInstance == nullptr) {
        uniqueInstance = new TeilnehmerListe();
    }

    return uniqueInstance;
}


int InsertTeilnehmer(Klassenmitglied &km)
{
    teilnehmerListe.insert(teilnehmerListe.end(), km);
    tDAO.Insert(km);
    return 0;
}


int InsertTeilnehmer(Organisator &orga)
{
    //

    return 0;
}


int ModifyTeilnehmer(Klassenmitglied &km)
{
    //
}


Klassenmitglied* GetTeilnehmer(int id)
{
    //
}


Klassenmitglied* GetTeilnehmer(string eMail)
{
    //
}


bool ContainsTeilnehmer(Klassenmitglied &km)
{
    bool returnValue = false;

    //

    return returnValue;
}


// was soll diese Funktion tun?
int SetPath(string path)
{
    //

    return 0;
}
