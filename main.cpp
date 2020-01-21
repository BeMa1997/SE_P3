#include <QApplication>
#include "TeilnehmerListeView.h"
#include <QtSql>
#include "teilnehmerliste.h"
#include "loginview.h"
#include "passwortaendernview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mw;
    mw.show();

    return app.exec();
}
