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
