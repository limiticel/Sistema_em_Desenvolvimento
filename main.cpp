#include "loginesenha.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogineSenha w;
    w.show();
    return a.exec();
}
