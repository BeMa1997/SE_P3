#include "aenderung.h"

Aenderung::Aenderung(int id, int orga, Klassenmitglied* mitglied, Datum datum):datum(datum)
{
    this->id = id;
    this->orga_id = orga;
    this->mitglied = mitglied;
    this->datum = datum;
}

Aenderung::Aenderung(int orgaId, Klassenmitglied* mitglied, Datum datum):datum(datum)
{
    this->orga_id = orgaId;
    this->mitglied = mitglied;
    this->datum = datum;
}
