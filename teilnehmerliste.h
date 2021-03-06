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

        int InsertTeilnehmer(Klassenmitglied* km, int orgaId);
        int InsertTeilnehmer(Organisator* orga, int orgaId);

        int ModifyTeilnehmer(Klassenmitglied* km, int orgaId);
        int ToKlassenmitglied(Organisator* orga, int orgaId);
        int ToOrganisator(Klassenmitglied* km, int orgaId);

        bool ContainsTeilnehmer(Klassenmitglied* km);
        bool ContainsTeilnehmer(Organisator* orga);
        bool ContainsTeilnehmer(string eMail);

        Klassenmitglied GetTeilnehmerFromDatabase(int teilnehmerId);
        Klassenmitglied* GetTeilnehmer(std::string eMail);
        Klassenmitglied* GetTeilnehmer(int orgaId);

        bool loadTeilnehmerListe();

        // Session-Management
        bool Login(std::string eMail, std::string kennwort);
        Klassenmitglied* getCurrentUser(){return currentUser;}
        void setCurrentUser(Klassenmitglied* currentUser){this->currentUser = currentUser;}


    private:
        TeilnehmerListe(){}
        static TeilnehmerListe* uniqueInstance;
        static Klassenmitglied* currentUser;
        std::list<Klassenmitglied> teilnehmerListe;
        QtTeilnehmerDao tDAO;
};

#endif // TEILNEHMERLISTE_H
