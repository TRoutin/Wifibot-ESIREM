#include "mainwindow.h"
#include "myrobot.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MyRobot robot;
    robot.doConnect();
    robot.MyTimerSlot();
    robot.disConnect();
    return a.exec();
}
