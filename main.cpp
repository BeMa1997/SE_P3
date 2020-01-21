#include "TeilnehmerListeView.h"
#include <QtSql>
#include <QApplication>
#include "teilnehmerliste.h"
#include "loginview.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainWindow mw;
    mw.show();

    return a.exec();
}
