#ifndef KLASSENMITGLIED_H
#define KLASSENMITGLIED_H

#include <list>
#include "datum.h"
#include "adresse.h"
#include "aenderung.h"

using namespace std;

class Organisator;

class Klassenmitglied
{
    public:
        // objekte vom Typ klassenmitglied werden ohne id erzeugt,
        // das objekt in teilnehmerliste erhält diese erhalten sie erst später nach dem eintragen in die Datenbank
        Klassenmitglied(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse);
        Klassenmitglied(int id, string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse);
        Klassenmitglied() {}

        //getter
        int getId(){return id;}
        string getVorname(){return vorname;}
        string getNachname(){return nachname;}
        string getGeburtsname(){return geburtsname;}
        string getEmail(){return eMail;}
        string getKennwort(){return kennwort;}
        string getTelnr(){return telNr;}
        string getStrasse(){return adresse.getStrasse();}
        string getOrt(){return adresse.getOrt();}
        string getPlz(){return adresse.getPlz();}
        string getLand(){return adresse.getLand();}
        string getHausnummer(){return adresse.getHausnummer();}
        list<Aenderung>* GetAenderungListe(){return &aenderung;}

        //setter
        void setVorname(string vorname){this->vorname = vorname;}
        void setNachname(string nachname){this->nachname = nachname;}
        void setGeburtsname(string geburtsname){this->geburtsname = geburtsname;}
        void setEmail(string eMail){this->eMail = eMail;}
        void setKennwort(string kennwort){this->kennwort = kennwort;}
        void setTelnr(string telNr){this->telNr = telNr;}

        // fehlt da nicht ein Argument?
        Aenderung* aendern(Klassenmitglied*, int, Datum);
        bool aendern(int, Klassenmitglied*, int, Datum);

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
