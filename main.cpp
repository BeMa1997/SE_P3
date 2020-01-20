#include <QCoreApplication>
#include "teilnehmerliste.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TeilnehmerListe *tn = TeilnehmerListe::Instance();
    tn->loadTeilnehmerListe();
    qDebug() << tn->teilnehmerListe.size();
    qDebug() << tn->teilnehmerListe.begin()->getId();



    Klassenmitglied km2 = tn->GetTeilnehmer(1);

    qDebug() << "GetTeilnehmer: ";
    qDebug() << km2.getId();



    Klassenmitglied km("Jesus", "Christ", "gott", "jesus@himmel.de", "derErloeser", "01854646",
                       Adresse("Himmelweg", "1", "Himmel", "7777", "HI"));
    int new_id = tn->InsertTeilnehmer(km, 0);
    qDebug() << new_id;

    Klassenmitglied km1("Jesus", "Christ", "gott", "jesus.christ@himmel.de", "derErloeser", "01854646",
                       Adresse("Himmelweg", "1", "Himmel", "7777", "HI"));
    new_id = tn->InsertTeilnehmer(km1, 0);
    qDebug() << new_id;

    return a.exec();
}
