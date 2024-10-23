#include "landingpage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    landingPage w;
    w.show();
    return a.exec();
}
