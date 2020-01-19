#ifndef ADRESSE_H
#define ADRESSE_H

#include <string>

using namespace std;

class Adresse
{
    public:
        Adresse();
        Adresse(string strasse, string hausnummer, string ort, string plz, string land);

        string getStrasse(){return strasse;}
        string getHausnummer(){return hausnummer;}
        string getOrt(){return ort;}
        string getPlz(){return plz;}
        string getLand(){return land;}

    private:
        string strasse;
        string hausnummer;
        string ort;
        string plz;
        string land;

};

#endif // ADRESSE_H
