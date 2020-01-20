#include <QApplication>
#include "loginview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    LoginView lv;
    lv.show();

    return a.exec();
}
