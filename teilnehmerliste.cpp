#include "teilnehmerliste.h"

TeilnehmerListe* TeilnehmerListe::uniqueInstance = nullptr;

TeilnehmerListe* TeilnehmerListe::Instance() {
    if(uniqueInstance == nullptr) {
        uniqueInstance = new TeilnehmerListe();
    }

    return uniqueInstance;
}
