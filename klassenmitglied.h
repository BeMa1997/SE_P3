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
        Klassenmitglied(int id, string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse);
        Klassenmitglied(string vorname, string nachname, string geburtsname, string eMail, string kennwort, string telNr, Adresse adresse);

        //getter
        int getId(){return id;}
        list<Aenderung> GetAenderungListe(){return aenderungListe;}

        Klassenmitglied* getThis(){return this;}
        string getVorname(){return vorname;}
        string getNachname(){return nachname;}
        string getGeburtsname(){return geburtsname;}
        string getEmail(){return eMail;}
        string getKennwort(){return kennwort;}
        string getTelnr(){return telNr;}
        Adresse getAdresse(){return adresse;}

        // Adresse
        string getLand(){return adresse.getLand();}
        string getPlz(){return adresse.getPlz();}
        string getOrt(){return adresse.getOrt();}
        string getStrasse(){return adresse.getStrasse();}
        string getHausnummer(){return adresse.getHausnummer();}

        //setter
        void setId(int id){this->id = id;}
        void setVorname(string vorname){this->vorname = vorname;}
        void setNachname(string nachname){this->nachname = nachname;}
        void setGeburtsname(string geburtsname){this->geburtsname = geburtsname;}
        void setEmail(string eMail){this->eMail = eMail;}
        void setKennwort(string kennwort){this->kennwort = kennwort;}
        void setTelnr(string telNr){this->telNr = telNr;}
        void setAdresse(Adresse adresse){this->adresse = adresse;}

        Aenderung* aendern(Klassenmitglied* km, int orgaId, Datum);

    private:
        int id;
        string vorname;
        string nachname;
        string geburtsname;
        string eMail;
        string kennwort;
        string telNr;
        Adresse adresse;

        list<Aenderung> aenderungListe;

};

#endif // KLASSENMITGLIED_H
