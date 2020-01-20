#include <QApplication>
#include "passwortaendernview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PasswortAendernView paev;
    paev.show();

    return a.exec();
}
