#ifndef DATUM_H
#define DATUM_H


class Datum
{
    public:
        Datum(int tag, int monat, int jahr);

    private:
        int tag;
        int monat;
        int jahr;
};

#endif // DATUM_H
