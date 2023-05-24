#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    ui->setupUi(this);


    ui->setupUi(this);



    robot = new MyRobot(this);
    robot->doConnect();

}

MainWindow::~MainWindow()
{

}

//UTILISATION DU CLAVIER

void MainWindow::keyPressEvent(QKeyEvent* key_robot){
    switch(key_robot->key()){
    case Qt::Key_Z :    //Avancer
        robot->set_etat(1);
        break;
    case Qt::Key_Q :    //Gauche
        robot->set_etat(2);
        break;
    case Qt::Key_D :    //Droite
        robot->set_etat(3);
        break;
    case Qt::Key_S :    //Reculer
        robot->set_etat(4);
        break;
    case Qt::Key_Space :    //Stop
        robot->set_etat(5);
        break;
    }
}

//Lorsque l'on relache, on s'arrete
void MainWindow::keyReleaseEvent(QKeyEvent* key_robot){
    robot->set_etat(5);
}

//Fonctions selon input :
void MainWindow::connexion()
{
    robot->doConnect();
}

void MainWindow::avancer()
{
    robot->set_etat(1);

}

void MainWindow::gauche()
{
    robot->set_etat(2);
}

void MainWindow::droite()
{
    robot->set_etat(3);
}

void MainWindow::reculer()
{
    robot->set_etat(4);
}

void MainWindow::stop()
{
    robot->set_etat(5);
}

void MainWindow::hgauche()
{
    robot->set_etat(6);
}

void MainWindow::bgauche()
{
    robot->set_etat(7);
}

void MainWindow::hdroite()
{
    robot->set_etat(8);
}

void MainWindow::bdroite()
{
    robot->set_etat(9);
}


//MOUVEMENT INTERFACE
void MainWindow::on_Gauche_pressed()
{
    gauche();
}

void MainWindow::on_avancer_pressed()
{
    avancer();
}

void MainWindow::on_droite_pressed()
{
    droite();
}


void MainWindow::on_hgauche_pressed()
{
    hgauche();
}

void MainWindow::on_hdroite_pressed()
{
    hdroite();
}

void MainWindow::on_bgauche_pressed()
{
    bgauche();
}

void MainWindow::on_bdroite_pressed()
{
    bdroite();
}

void MainWindow::on_connexion_clicked()
{
    connexion();
}

void MainWindow::on_avancer_released()
{
    stop();
}

void MainWindow::on_hdroite_released()
{
    stop();
}

void MainWindow::on_droite_released()
{
    stop();
}

void MainWindow::on_bdroite_released()
{
    stop();
}


void MainWindow::on_bgauche_released()
{
    stop();
}

void MainWindow::on_Gauche_released()
{
    stop();
}

void MainWindow::on_hgauche_released()
{
    stop();
}



//CHANGEMENT VITESSE ET AFFICHAGE
void MainWindow::on_slide_vitesse_valueChanged(int value)
{
    //Change la vitesse du robot
    robot->set_vitesse(value);
    //Affiche la vitesse et le pourcentage sur l'interface
    int vit = robot->get_vitesse();
    QString vit_string = QString::number(vit);
    double pourcentage = ((vit-120)*100/120);
    QString pourcentage_string = QString::number(pourcentage);
    ui->titre_vitesse->setText(vit_string + " (" + pourcentage_string + "%)");
}


void MainWindow::on_pushButton_3_pressed()
{
    reculer();
}


void MainWindow::on_pushButton_3_released()
{
    stop();
}
