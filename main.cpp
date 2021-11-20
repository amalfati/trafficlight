#include <QApplication>
#include "trafficlight.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto D = new TrafficLight;
   D->show();

    return a.exec();
}
