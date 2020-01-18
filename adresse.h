#ifndef ADRESSE_H
#define ADRESSE_H

#include <string>

using namespace std;

class Adresse
{
public:
    Adresse(string strasse, string hausnummer, string ort, string plz, string land);
    Adresse();
    ~Adresse();

private:
    string strasse;
    string hausnummer;
    string ort;
    string plz;
    string land;

};

#endif // ADRESSE_H
