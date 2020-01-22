#ifndef DATUM_H
#define DATUM_H


class Datum
{
    public:
        Datum();
        Datum(int tag, int monat, int jahr);
        int getTag(){return tag;}
        int getMonat(){return monat;}
        int getJahr(){return jahr;}

    private:
        int tag;
        int monat;
        int jahr;
};

#endif // DATUM_H
