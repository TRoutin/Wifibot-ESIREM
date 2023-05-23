#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QWebEngineView>


MainWindow::~MainWindow()
{
    delete ui;
}


MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    ui->setupUi(this);


    //Vue de la webcam du robot
    manager = new QNetworkAccessManager;
    view = new QWebEngineView();
    view->load(QUrl("http://192.168.1.106:8080/?action=stream"));
    view->show();

    this->ui->camera->addWidget(view);

    robot = new MyRobot(this);


}
