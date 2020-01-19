#ifndef KLASSENMITGLIED_H
#define KLASSENMITGLIED_H

#include <string>
#include <list>
#include <aenderung.h>
#include <adresse.h>
//#include <organisator.h>
#include <datum.h>

using namespace std;

class Organisator;

class Klassenmitglied
{
    public:
        // objekte vom Typ klassenmitglied werden ohne id erzeugt,
        // das objekt in teilnehmerliste erhält diese erhalten sie erst später nach dem eintragen in die Datenbank
        Klassenmitglied(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse);

        // fehlt da nicht ein Argument?
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
        list<Aenderung> aenderung;

};

#endif // KLASSENMITGLIED_H
