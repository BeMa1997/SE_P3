#include "datum.h"
#include <iomanip>

Datum::Datum()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    this->tag = tm.tm_mday;
    this->monat = tm.tm_mon;
    this->jahr = tm.tm_year;
}

Datum::Datum(int tag, int monat, int jahr)
{
    this->tag = tag;
    this->monat = monat;
    this->jahr = jahr;
}
