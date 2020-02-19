#include "handinginput.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HandingInput w;
    w.show();
    return a.exec();
}
