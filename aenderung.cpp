#include "aenderung.h"

Aenderung::Aenderung(int id, Organisator* orga, Klassenmitglied* mitglied, Datum datum)
{
    this->id = id;
    this->orga = orga;
    this->mitglied = mitglied;
    this->datum = datum;
}
