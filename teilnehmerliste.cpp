#include "teilnehmerliste.h"

using namespace std;

TeilnehmerListe* TeilnehmerListe::uniqueInstance = nullptr;
//list<Klassenmitglied> teilnehmerListe;
//QtTeilnehmerDao tDAO;

TeilnehmerListe* TeilnehmerListe::Instance() {
    if(uniqueInstance == nullptr) {
        uniqueInstance = new TeilnehmerListe();
        //tDAO.GetTeilnehmerListe(teilnehmerListe);
    }

    return uniqueInstance;
}


bool TeilnehmerListe::loadTeilnehmerListe()
{
    tDAO.GetTeilnehmerListe(&teilnehmerListe);
}


int TeilnehmerListe::InsertTeilnehmer(Klassenmitglied km, int id)
{
    teilnehmerListe.insert(teilnehmerListe.end(), km);
    int km_id = tDAO.Insert(km, id);

    return km_id;
}


int TeilnehmerListe::ModifyTeilnehmer(Klassenmitglied &km, int id)
{
    //
}


Klassenmitglied TeilnehmerListe::GetTeilnehmer(int id)
{
    return tDAO.Get(id);
}


void TeilnehmerListe::GetTeilnehmer(int id, Klassenmitglied* km)
{
    //tDAO.Get(id, km);
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
