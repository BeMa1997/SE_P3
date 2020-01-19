#ifndef TEILNEHMERLISTE_H
#define TEILNEHMERLISTE_H

#include <klassenmitglied.h>
#include <map>

class TeilnehmerListe
{
    public:
        static TeilnehmerListe* Instance();

        int InsertTeilnehmer(Klassenmitglied &km);
        int InsertTeilnehmer(Organisator &orga);

        int ModifyTeilnehmer(Klassenmitglied &km);
        Klassenmitglied* GetTeilnehmer(int id);
        Klassenmitglied* GetTeilnehmer(string eMail);
        map<int, Klassenmitglied> GetTeilnehmerListe();
        bool ContainsTeilnehmer(Klassenmitglied &km);
        int SetPath(string path);


    private:
        static TeilnehmerListe* uniqueInstance;
        TeilnehmerListe(){}
};

#endif // TEILNEHMERLISTE_H
