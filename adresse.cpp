#include "adresse.h"

using namespace std;

Adresse::Adresse(string strasse, string hausnummer, string ort, string plz, string land)
{
    this->strasse = strasse;
    this->hausnummer = hausnummer;
    this->ort = ort;
    this->plz = plz;
    this->land = land;
}

bool Adresse::operator ==(const Adresse& d)
{
    bool returnValue = false;

    if(strasse == d.strasse &&
        hausnummer == d.hausnummer &&
        ort == d.ort &&
        plz == d.plz &&
        land == d.land)
    {
            returnValue = true;
    }

    return returnValue;
}
