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

        int ModifyTeilnehmer(Klassenmitglied km, int id);
        Klassenmitglied* GetTeilnehmer(int id);

        bool ContainsTeilnehmer(Klassenmitglied* km);

        Klassenmitglied* GetTeilnehmer(int teilnehmerId);
        Klassenmitglied* GetTeilnehmer(std::string eMail);

        int SetPath(std::string path);

        // Session-Management
        bool Login(std::string eMail, std::string kennwort);
        Klassenmitglied* getCurrentUser(){return currentUser;}
        void setCurrentUser(Klassenmitglied* currentUser){this->currentUser = currentUser;}


    private:
        static TeilnehmerListe* uniqueInstance;
        static Klassenmitglied* currentUser;
        TeilnehmerListe(){}
        std::list<Klassenmitglied> teilnehmerListe;
        QtTeilnehmerDao tDAO;

};

#endif // TEILNEHMERLISTE_H
