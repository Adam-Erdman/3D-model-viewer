#include "PrismObjWindow.h"
#include "RecPrismBox.h"
#include <QApplication>

#include <QAxFactory>

//Factory with library Id and app id
QAXFACTORY_BEGIN(
    "{rec_prim_box_lib}",
    "{rec_prim_box_app}")
    QAXCLASS(RecPrismBox)
QAXFACTORY_END()

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc,argv);

    PrismObjWindow prObj;
    prObj.resize(500, 450);
    prObj.show();
    return a.exec();
}

