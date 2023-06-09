#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QKeyEvent>
#include "myrobot.h"
#include <QWebEngineView>
#include <QNetworkAccessManager>



QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE


class MainWindow : public QDialog
{
    Q_OBJECT

public :
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots :


    //Connexion
    void connexion();

    void updatingUI(QByteArray DataReceived);

    //Lancement du mouvement
    void avancer();
    void gauche();
    void droite();
    void reculer();
    void stop();
    void hgauche();
    void bgauche();
    void hdroite();
    void bdroite();

    //Clavier
    void keyPressEvent(QKeyEvent* key_robot);
    void keyReleaseEvent(QKeyEvent* key_robot);



    //Donnees du robot

    void on_slide_vitesse_valueChanged(int value);


    //Boutons connexion et mouvement
    void on_Gauche_pressed();
    void on_avancer_pressed();
    void on_droite_pressed();

    void on_hgauche_pressed();
    void on_hdroite_pressed();
    void on_bgauche_pressed();
    void on_bdroite_pressed();
    void on_connexion_clicked();
    void on_avancer_released();
    void on_hdroite_released();
    void on_droite_released();
    void on_bdroite_released();

    void on_bgauche_released();
    void on_Gauche_released();
    void on_hgauche_released();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    //Mouvements cameras
    void on_haut_camera_pressed();
    void on_gauche_camera_pressed();
    void on_droite_camera_pressed();
    void on_bas_camera_pressed();

    void cam_haut();
    void cam_bas();
    void cam_gauche();
    void cam_droite();

private:

    //Affichage camera
    QWebEngineView *view;

    //Mouvement camera
    QNetworkAccessManager *manager;
    QNetworkRequest request;

    //Robot
    MyRobot* robot;

    Ui::Dialog *ui;

    int speedFront[2];
    int batLevel;

};

#endif // MAINWINDOW_H
