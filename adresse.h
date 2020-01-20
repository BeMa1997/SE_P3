#ifndef ADRESSE_H
#define ADRESSE_H

#include <string>

class Adresse
{
    public:
    Adresse() {};
        Adresse(std::string strasse, std::string hausnummer, std::string ort, std::string plz, std::string land);

        std::string getStrasse(){return strasse;}
        std::string getHausnummer(){return hausnummer;}
        std::string getOrt(){return ort;}
        std::string getPlz(){return plz;}
        std::string getLand(){return land;}

    private:
        std::string strasse;
        std::string hausnummer;
        std::string ort;
        std::string plz;
        std::string land;

};

#endif // ADRESSE_H
