#include "aenderung.h"
#include "organisator.h"
#include "klassenmitglied.h"

Aenderung::Aenderung(int id, Organisator* orga, Klassenmitglied* mitglied, Datum datum): datum(datum)
{
    this->id = id;
    this->orga = orga;
    this->mitglied = mitglied;
    this->datum = datum;
}