#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    ui->setupUi(this);



    //Vue de la webcam du robot (indÃ©pendant du robot)
    manager = new QNetworkAccessManager;
        view = new QWebEngineView();
        view->load(QUrl("http://192.168.1.106:8080/?action=stream"));
        view->show();

    this->ui->camera->addWidget(view);

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
    case Qt::Key_Right:
        cam_droite();
    case Qt::Key_Left:
        cam_gauche();
    case Qt::Key_Up:
        cam_haut();
    case Qt::Key_Down:
        cam_bas();
    case Qt::Key_Escape:
        robot->disConnect();
    }
}

//Lorsque l'on relache, on s'arrete
void MainWindow::keyReleaseEvent(QKeyEvent* key_robot){
    robot->set_etat(5);
}

void MainWindow::updatingUI(QByteArray DataReceived){ // Mise a jour de l'interface
    //On récupère les données des vitesses gauche et droites
    speedFront[0] = int((DataReceived[1] << 8) + DataReceived[0]);// Vitesse Gauche
    if (speedFront[0] < 0){ speedFront[0] = 65536+speedFront[0];} // Prise en compte du bit de signe
    speedFront[1] = int((DataReceived[10] << 8) + DataReceived[9]);// Vitesse Droite
    if (speedFront[1] < 0){ speedFront[1] = 65536+speedFront[1];}
    //tics /50 ms Faut voir le nb de marqueur et la taille de la roue pour transferer les tics en metre
    //2448 tics par tour de roue. Taille roue : (a la main ) diamètre 14cm
    //Calcul vitesse
    float vitesse[] = {0,0};
    vitesse[0] = float(speedFront[0])*3.14*0.014*20*100/2448; //On prend quelque chiffre après la virgule
    vitesse[1] = float(speedFront[1])*3.14*0.014*20*100/2448;

    //Affichage dans l'interface
    // QString::first() n'existe pas?? On est donc forcé a utiliser le code pas pratique suivant
    QString GVitesse = QVariant(vitesse[0]).toString();
    GVitesse.chop(GVitesse.length()-4);
    QString LVitesse = QVariant(vitesse[1]).toString();
    LVitesse.chop(LVitesse.length()-4);
    ui->leftSpeed-> setText(GVitesse+" cm/s");
    ui->rightSpeed-> setText(LVitesse+" cm/s");

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

//MOUVEMENT CAMERA
void MainWindow::on_haut_camera_pressed()
{
    cam_haut();
}

void MainWindow::on_gauche_camera_pressed()
{
    cam_gauche();
}

void MainWindow::on_droite_camera_pressed()
{
    cam_droite();
}

void MainWindow::on_bas_camera_pressed()
{
    cam_bas();
}

void MainWindow::cam_haut()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200")));
}
void MainWindow::cam_bas()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200")));

}
void MainWindow::cam_gauche()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200")));
}
void MainWindow::cam_droite()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    manager->get(QNetworkRequest(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200")));
}

void MainWindow::on_pushButton_3_pressed()
{
    reculer();
}


void MainWindow::on_pushButton_3_released()
{
    stop();
}
