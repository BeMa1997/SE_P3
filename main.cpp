#include <iostream>
#include "TeilnehmerListeView.h"

using namespace std;

#include <QtSql>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mw;
    mw.show();

    return a.exec();
}
