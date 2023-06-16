/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *gauche_camera;
    QLabel *titre_vitesse;
    QPushButton *hgauche;
    QWidget *formLayoutWidget;
    QFormLayout *camera;
    QPushButton *droite;
    QPushButton *connexion;
    QSlider *slide_vitesse;
    QPushButton *bas_camera;
    QLabel *ir_AvD;
    QPushButton *hdroite;
    QPushButton *Gauche;
    QLabel *titre_batterie;
    QProgressBar *barre_batterie;
    QPushButton *droite_camera;
    QPushButton *avancer;
    QLabel *ir_ArD;
    QPushButton *haut_camera;
    QPushButton *bgauche;
    QPushButton *bdroite;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(859, 454);
        Dialog->setMouseTracking(true);
        gauche_camera = new QPushButton(Dialog);
        gauche_camera->setObjectName(QString::fromUtf8("gauche_camera"));
        gauche_camera->setGeometry(QRect(60, 220, 41, 31));
        titre_vitesse = new QLabel(Dialog);
        titre_vitesse->setObjectName(QString::fromUtf8("titre_vitesse"));
        titre_vitesse->setGeometry(QRect(30, 360, 111, 20));
        hgauche = new QPushButton(Dialog);
        hgauche->setObjectName(QString::fromUtf8("hgauche"));
        hgauche->setGeometry(QRect(660, 150, 31, 31));
        formLayoutWidget = new QWidget(Dialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(200, 120, 411, 241));
        camera = new QFormLayout(formLayoutWidget);
        camera->setObjectName(QString::fromUtf8("camera"));
        camera->setContentsMargins(0, 0, 0, 0);
        droite = new QPushButton(Dialog);
        droite->setObjectName(QString::fromUtf8("droite"));
        droite->setGeometry(QRect(770, 190, 41, 31));
        connexion = new QPushButton(Dialog);
        connexion->setObjectName(QString::fromUtf8("connexion"));
        connexion->setGeometry(QRect(20, 60, 91, 31));
        slide_vitesse = new QSlider(Dialog);
        slide_vitesse->setObjectName(QString::fromUtf8("slide_vitesse"));
        slide_vitesse->setGeometry(QRect(30, 390, 181, 31));
        slide_vitesse->setMinimum(120);
        slide_vitesse->setMaximum(240);
        slide_vitesse->setOrientation(Qt::Horizontal);
        bas_camera = new QPushButton(Dialog);
        bas_camera->setObjectName(QString::fromUtf8("bas_camera"));
        bas_camera->setGeometry(QRect(100, 260, 41, 31));
        ir_AvD = new QLabel(Dialog);
        ir_AvD->setObjectName(QString::fromUtf8("ir_AvD"));
        ir_AvD->setGeometry(QRect(870, 110, 71, 16));
        hdroite = new QPushButton(Dialog);
        hdroite->setObjectName(QString::fromUtf8("hdroite"));
        hdroite->setGeometry(QRect(740, 150, 31, 31));
        Gauche = new QPushButton(Dialog);
        Gauche->setObjectName(QString::fromUtf8("Gauche"));
        Gauche->setGeometry(QRect(620, 190, 41, 31));
        titre_batterie = new QLabel(Dialog);
        titre_batterie->setObjectName(QString::fromUtf8("titre_batterie"));
        titre_batterie->setGeometry(QRect(20, 10, 121, 16));
        barre_batterie = new QProgressBar(Dialog);
        barre_batterie->setObjectName(QString::fromUtf8("barre_batterie"));
        barre_batterie->setGeometry(QRect(80, 10, 118, 23));
        barre_batterie->setValue(24);
        droite_camera = new QPushButton(Dialog);
        droite_camera->setObjectName(QString::fromUtf8("droite_camera"));
        droite_camera->setGeometry(QRect(140, 220, 41, 31));
        avancer = new QPushButton(Dialog);
        avancer->setObjectName(QString::fromUtf8("avancer"));
        avancer->setGeometry(QRect(690, 110, 51, 31));
        ir_ArD = new QLabel(Dialog);
        ir_ArD->setObjectName(QString::fromUtf8("ir_ArD"));
        ir_ArD->setGeometry(QRect(870, 150, 71, 16));
        haut_camera = new QPushButton(Dialog);
        haut_camera->setObjectName(QString::fromUtf8("haut_camera"));
        haut_camera->setGeometry(QRect(100, 180, 41, 31));
        bgauche = new QPushButton(Dialog);
        bgauche->setObjectName(QString::fromUtf8("bgauche"));
        bgauche->setGeometry(QRect(650, 230, 41, 31));
        bdroite = new QPushButton(Dialog);
        bdroite->setObjectName(QString::fromUtf8("bdroite"));
        bdroite->setGeometry(QRect(740, 230, 41, 31));
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(690, 270, 51, 29));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        gauche_camera->setText(QCoreApplication::translate("Dialog", "\342\207\220", nullptr));
        titre_vitesse->setText(QCoreApplication::translate("Dialog", "Vitesse", nullptr));
        hgauche->setText(QCoreApplication::translate("Dialog", "\342\206\226", nullptr));
        droite->setText(QCoreApplication::translate("Dialog", "\342\207\222", nullptr));
        connexion->setText(QCoreApplication::translate("Dialog", "Connexion", nullptr));
        bas_camera->setText(QCoreApplication::translate("Dialog", "\342\207\223", nullptr));
        ir_AvD->setText(QCoreApplication::translate("Dialog", "Avant Droite", nullptr));
        hdroite->setText(QCoreApplication::translate("Dialog", "\342\206\227", nullptr));
        Gauche->setText(QCoreApplication::translate("Dialog", "\342\207\220", nullptr));
        titre_batterie->setText(QCoreApplication::translate("Dialog", "Batterie", nullptr));
        droite_camera->setText(QCoreApplication::translate("Dialog", "\342\207\222", nullptr));
        avancer->setText(QCoreApplication::translate("Dialog", "\342\207\221", nullptr));
        ir_ArD->setText(QCoreApplication::translate("Dialog", "Arriere Droite", nullptr));
        haut_camera->setText(QCoreApplication::translate("Dialog", "\342\207\221", nullptr));
        bgauche->setText(QCoreApplication::translate("Dialog", "\342\206\231", nullptr));
        bdroite->setText(QCoreApplication::translate("Dialog", "\342\206\230", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dialog", "\342\207\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
