// myrobot.cpp

#include "myrobot.h"
#include <cmath>
#include <math.h>

MyRobot::MyRobot(QObject *parent) : QObject(parent) {
    m_etat = 0;
    DataToSend.resize(9);
    //Pour le CRC
    DataToSend[0] = 0xFF;
    //Taille
    DataToSend[1] = 0x07;
    //Vitesse de la gauche
    DataToSend[2] = 0x0;
    DataToSend[3] = 0x0;
    //Vitesse de la droite
    DataToSend[4] = 0x0;
    DataToSend[5] = 0x0;
    //A determiner
    DataToSend[6] = 0x0;
    //CRC
    DataToSend[7] = 0x0;
    DataToSend[8] = 0x0;
    DataReceived.resize(21);
    TimerEnvoi = new QTimer();
    //Initialisation de la vitesse
    m_vitesse = 120;
    // setup signal and slot
    connect(TimerEnvoi, SIGNAL(timeout()), this, SLOT(MyTimerSlot())); //Send data to wifibot timer
}


void MyRobot::doConnect() {
    socket = new QTcpSocket(this); // socket creation
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
    qDebug() << "connecting..."; // this is not blocking call
    //socket->connectToHost("LOCALHOST", 15020);
    socket->connectToHost("192.168.10.1", 5005); // connection to wifibot
    // we need to wait...
    if(!socket->waitForConnected(5000)) {
        qDebug() << "Error: " << socket->errorString();
        return;
    }
    TimerEnvoi->start(75);
}

void MyRobot::disConnect() {
    TimerEnvoi->stop();
    socket->close();
}

void MyRobot::connected() {
    qDebug() << "connected..."; // Hey server, tell me about you.
}

void MyRobot::disconnected() {
    qDebug() << "disconnected...";
}

void MyRobot::bytesWritten(qint64 bytes) {
    qDebug() << bytes << " bytes written...";
}

void MyRobot::readyRead() {
    qDebug() << "reading..."; // read the data from the socket
    DataReceived = socket->readAll();
    emit updateUI(DataReceived);
    qDebug() << DataReceived[0] << DataReceived[1] << DataReceived[2];
}

void MyRobot::MyTimerSlot() {
    qDebug() << "Timer...";
    move(m_etat);
    while(Mutex.tryLock());
    socket->write(DataToSend);
    Mutex.unlock();
}

void MyRobot::move(int cas){

    //CRC
    DataToSend[0] = 0xFF;
    DataToSend[1] = 0x07;
    //Vitesse gauche
    DataToSend[2] = 0x0;
    DataToSend[3] = 0x0;
    //Vitesse droite
    DataToSend[4] = 0x0;
    DataToSend[5] = 0x0;
    //Avancer ou reculer
    DataToSend[6] = 0x0;

    Mutex.tryLock();
    switch(cas) {
    case 1 :    //Avancer
        //Vitesse Gauche
        DataToSend[2] = m_vitesse;
        //Vitesse Droite
        DataToSend[4] = m_vitesse;
        //Avancer ou reculer
        DataToSend[6] = 0x50;
        break;
    case 2 :    //gauche
        //Vitesse Gauche
        DataToSend[2] = m_vitesse;
         //Vitesse Droite
        DataToSend[4] = m_vitesse;
        //Avancer ou reculer
        DataToSend[6] = 0x10;
        break;
    case 3 :    //droite
        //Vitesse Gauche
        DataToSend[2] = m_vitesse;
        //Vitesse Droite
        DataToSend[4] = m_vitesse;
        //Avancer ou reculer
        DataToSend[6] = 0x40;
        break;
    case 4 :    //reculer
        //Vitesse Gauche
        DataToSend[2] = m_vitesse;
        //Vitesse Droite
        DataToSend[4] = m_vitesse;
        break;
    case 5 :    //STOP
        break;
    case 6 :    //haut gauche
        //Vitesse Droite
        DataToSend[4] = m_vitesse;
        //Avancer ou reculer
        DataToSend[6] = 0x50;
        break;
    case 7 :    //bas gauche
        //Vitesse de la droite
        DataToSend[4] = m_vitesse;
        break;
    case 8 :    //haut droite
        //Vitesse Gauche
        DataToSend[2] = m_vitesse;
        //Avancer ou reculer
        DataToSend[6] = 0x50;
        break;
    case 9 :    //bas droite
        //Vitesse Gauche
        DataToSend[2] = m_vitesse;
        break;
    }
    DataToSend[7] = 0x0;
    qint64 c16 = Crc16(DataToSend, 1);  //7 octets hors CRC

    //CRC
    DataToSend[7] = (unsigned char)c16;    //Partie basse du CRC
    DataToSend[8] = (unsigned char)(c16 >> 8);   //Partie haute


    Mutex.unlock();
}

qint64 MyRobot::Crc16(QByteArray Adresse_tab , int pos)
{
    Adresse_tab.data();
    unsigned char *data = (unsigned char*)Adresse_tab.constData();
    qint64 Crc = 0xFFFF;
    qint64 Polynome = 0xA001;
    qint64 Parity= 0;
    for (; pos < Adresse_tab.length() - 2; pos++) //7 octets
    {
        Crc ^= *(data+pos);
        for ( unsigned int CptBit = 0; CptBit <= 7 ; CptBit++)  //8 bits (par octets)
        {
            Parity= Crc;
            Crc >>= 1;
            if (Parity%2 == true) Crc ^= Polynome;
        }
    }
    return Crc;
}

void MyRobot::set_vitesse(int valeur){
    m_vitesse = valeur;
}

int MyRobot::get_vitesse(){
    return m_vitesse;
}

void MyRobot::set_etat(int valeur){
    m_etat = valeur;
}
