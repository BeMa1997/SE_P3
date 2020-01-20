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

        int InsertTeilnehmer(Klassenmitglied &km, int id);
        int InsertTeilnehmer(Organisator &orga);

        int ModifyTeilnehmer(Klassenmitglied &km, int id);
        Klassenmitglied* GetTeilnehmer(int id);
        Klassenmitglied* GetTeilnehmer(std::string eMail);
        bool ContainsTeilnehmer(Klassenmitglied &km);
        int SetPath(std::string path);

        bool Login(std::string eMail, std::string kennwort);

    private:
        static TeilnehmerListe* uniqueInstance;
        TeilnehmerListe(){}
        std::list<Klassenmitglied> teilnehmerListe;
        QtTeilnehmerDao tDAO;
};

#endif // TEILNEHMERLISTE_H
