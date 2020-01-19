#ifndef TEILNEHMERLISTE_H
#define TEILNEHMERLISTE_H


class TeilnehmerListe {
    public:
        static TeilnehmerListe* Instance();

    private:
        static TeilnehmerListe* uniqueInstance;
        TeilnehmerListe(){}
};

#endif // TEILNEHMERLISTE_H
