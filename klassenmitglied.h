#ifndef KLASSENMITGLIED_H
#define KLASSENMITGLIED_H

#include <string>
#include <vector>
#include <aenderung.h>
#include <adresse.h>
#include <organisator.h>
#include <datum.h>

using namespace std;

class Klassenmitglied
{
public:
    Klassenmitglied();
    bool aendern(Klassenmitglied*, Organisator*, Datum);

private:
    int id;
    string vorname;
    string nachname;
    string geburtsname;
    string eMail;
    string kennwort;
    string telNr;

    Adresse adresse;
    vector<Aenderung> aenderung;

};

#endif // KLASSENMITGLIED_H
