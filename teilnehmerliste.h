#ifndef TEILNEHMERLISTE_H
#define TEILNEHMERLISTE_H

#include "klassenmitglied.h"
#include "qtteilnehmerdao.h"
#include <string>
#include <list>


class Organisator;

class TeilnehmerListe
{
    public:
        static TeilnehmerListe* Instance();

        int InsertTeilnehmer(Klassenmitglied km, int id);

        int ModifyTeilnehmer(Klassenmitglied &km, int id);
        Klassenmitglied GetTeilnehmer(int id);
        void GetTeilnehmer(int, Klassenmitglied*);
        Klassenmitglied* GetTeilnehmer(std::string eMail);
        bool ContainsTeilnehmer(Klassenmitglied &km);
        int SetPath(std::string path);
        bool loadTeilnehmerListe();

        std::list<Klassenmitglied> teilnehmerListe;


    private:
        static TeilnehmerListe* uniqueInstance;
        TeilnehmerListe(){}
        //static std::list<Klassenmitglied> teilnehmerListe;
        QtTeilnehmerDao tDAO;
};

#endif // TEILNEHMERLISTE_H
