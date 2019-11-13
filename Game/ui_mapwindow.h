/********************************************************************************
** Form generated from reading UI file 'mapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWINDOW_H
#define UI_MAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QFrame *frame;
    QLabel *moneyLable;
    QLCDNumber *lcdFood;
    QLCDNumber *lcdMoney;
    QLabel *foodLabel;
    QLCDNumber *lcdWood;
    QLCDNumber *lcdStone;
    QLabel *woodLabel;
    QLabel *stoneLabel;
    QLCDNumber *lcdOre;
    QLabel *oreLabel;
    QLabel *resourcesLabel;
    QFrame *frame_2;
    QLabel *label_3;
    QPushButton *hqButton;
    QPushButton *farmButton;
    QPushButton *sawButton;
    QPushButton *outpustButton;
    QPushButton *mineButton;
    QPushButton *smallHouseButton;
    QPushButton *largeHouseButton;
    QPushButton *apartmentsButton;
    QPushButton *skyscraperButton;
    QFrame *frame_3;
    QLabel *label_8;
    QPushButton *assignButton;
    QPushButton *unassignButton;
    QPushButton *bwButton;
    QPushButton *farmerButton;
    QPushButton *loggerButton;
    QPushButton *minerButton;
    QPushButton *pushButton;
    QPushButton *highScoreButton;
    QPushButton *highScoreButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName(QString::fromUtf8("MapWindow"));
        MapWindow->resize(800, 600);
        centralwidget = new QWidget(MapWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(12, 12, 511, 501));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(540, 30, 241, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        moneyLable = new QLabel(frame);
        moneyLable->setObjectName(QString::fromUtf8("moneyLable"));
        moneyLable->setGeometry(QRect(70, 20, 41, 16));
        lcdFood = new QLCDNumber(frame);
        lcdFood->setObjectName(QString::fromUtf8("lcdFood"));
        lcdFood->setGeometry(QRect(10, 50, 51, 23));
        lcdMoney = new QLCDNumber(frame);
        lcdMoney->setObjectName(QString::fromUtf8("lcdMoney"));
        lcdMoney->setGeometry(QRect(10, 20, 51, 23));
        foodLabel = new QLabel(frame);
        foodLabel->setObjectName(QString::fromUtf8("foodLabel"));
        foodLabel->setGeometry(QRect(70, 50, 41, 16));
        lcdWood = new QLCDNumber(frame);
        lcdWood->setObjectName(QString::fromUtf8("lcdWood"));
        lcdWood->setGeometry(QRect(130, 20, 51, 23));
        lcdStone = new QLCDNumber(frame);
        lcdStone->setObjectName(QString::fromUtf8("lcdStone"));
        lcdStone->setGeometry(QRect(130, 50, 51, 23));
        woodLabel = new QLabel(frame);
        woodLabel->setObjectName(QString::fromUtf8("woodLabel"));
        woodLabel->setGeometry(QRect(190, 20, 41, 16));
        stoneLabel = new QLabel(frame);
        stoneLabel->setObjectName(QString::fromUtf8("stoneLabel"));
        stoneLabel->setGeometry(QRect(190, 50, 41, 16));
        lcdOre = new QLCDNumber(frame);
        lcdOre->setObjectName(QString::fromUtf8("lcdOre"));
        lcdOre->setGeometry(QRect(10, 80, 51, 23));
        oreLabel = new QLabel(frame);
        oreLabel->setObjectName(QString::fromUtf8("oreLabel"));
        oreLabel->setGeometry(QRect(70, 80, 41, 16));
        resourcesLabel = new QLabel(frame);
        resourcesLabel->setObjectName(QString::fromUtf8("resourcesLabel"));
        resourcesLabel->setGeometry(QRect(80, 0, 71, 16));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(540, 280, 241, 191));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 10, 31, 16));
        hqButton = new QPushButton(frame_2);
        hqButton->setObjectName(QString::fromUtf8("hqButton"));
        hqButton->setGeometry(QRect(20, 30, 201, 32));
        farmButton = new QPushButton(frame_2);
        farmButton->setObjectName(QString::fromUtf8("farmButton"));
        farmButton->setGeometry(QRect(20, 150, 101, 32));
        sawButton = new QPushButton(frame_2);
        sawButton->setObjectName(QString::fromUtf8("sawButton"));
        sawButton->setGeometry(QRect(20, 90, 101, 32));
        outpustButton = new QPushButton(frame_2);
        outpustButton->setObjectName(QString::fromUtf8("outpustButton"));
        outpustButton->setGeometry(QRect(20, 60, 101, 32));
        mineButton = new QPushButton(frame_2);
        mineButton->setObjectName(QString::fromUtf8("mineButton"));
        mineButton->setGeometry(QRect(20, 120, 101, 32));
        smallHouseButton = new QPushButton(frame_2);
        smallHouseButton->setObjectName(QString::fromUtf8("smallHouseButton"));
        smallHouseButton->setGeometry(QRect(120, 60, 101, 32));
        largeHouseButton = new QPushButton(frame_2);
        largeHouseButton->setObjectName(QString::fromUtf8("largeHouseButton"));
        largeHouseButton->setGeometry(QRect(120, 90, 101, 32));
        apartmentsButton = new QPushButton(frame_2);
        apartmentsButton->setObjectName(QString::fromUtf8("apartmentsButton"));
        apartmentsButton->setGeometry(QRect(120, 120, 101, 32));
        skyscraperButton = new QPushButton(frame_2);
        skyscraperButton->setObjectName(QString::fromUtf8("skyscraperButton"));
        skyscraperButton->setGeometry(QRect(120, 150, 101, 32));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(540, 150, 241, 121));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 0, 131, 16));
        assignButton = new QPushButton(frame_3);
        assignButton->setObjectName(QString::fromUtf8("assignButton"));
        assignButton->setGeometry(QRect(10, 80, 113, 32));
        unassignButton = new QPushButton(frame_3);
        unassignButton->setObjectName(QString::fromUtf8("unassignButton"));
        unassignButton->setGeometry(QRect(120, 80, 113, 32));
        bwButton = new QPushButton(frame_3);
        bwButton->setObjectName(QString::fromUtf8("bwButton"));
        bwButton->setGeometry(QRect(0, 20, 61, 51));
        bwButton->setStyleSheet(QString::fromUtf8("border-image: url(:/workerIcons/worker.png);\n"
"border: 2px solid #8f8f91;\n"
"border-radius: 6px;"));
        bwButton->setCheckable(true);
        farmerButton = new QPushButton(frame_3);
        farmerButton->setObjectName(QString::fromUtf8("farmerButton"));
        farmerButton->setGeometry(QRect(60, 20, 61, 51));
        farmerButton->setStyleSheet(QString::fromUtf8("border-image: url(:/workerIcons/tractor.png)\n"
""));
        farmerButton->setCheckable(true);
        loggerButton = new QPushButton(frame_3);
        loggerButton->setObjectName(QString::fromUtf8("loggerButton"));
        loggerButton->setGeometry(QRect(120, 20, 61, 51));
        loggerButton->setStyleSheet(QString::fromUtf8("border-image: url(:/workerIcons/axe.png)"));
        minerButton = new QPushButton(frame_3);
        minerButton->setObjectName(QString::fromUtf8("minerButton"));
        minerButton->setGeometry(QRect(180, 20, 61, 51));
        minerButton->setStyleSheet(QString::fromUtf8("border-image: url(:/workerIcons/mine.png)"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(560, 480, 211, 31));
        highScoreButton = new QPushButton(centralwidget);
        highScoreButton->setObjectName(QString::fromUtf8("highScoreButton"));
        highScoreButton->setGeometry(QRect(560, 510, 101, 31));
        highScoreButton_2 = new QPushButton(centralwidget);
        highScoreButton_2->setObjectName(QString::fromUtf8("highScoreButton_2"));
        highScoreButton_2->setGeometry(QRect(670, 510, 101, 31));
        MapWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MapWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MapWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MapWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MapWindow->setStatusBar(statusbar);

        retranslateUi(MapWindow);

        bwButton->setDefault(false);
        farmerButton->setDefault(false);
        loggerButton->setDefault(false);
        minerButton->setDefault(false);


        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QCoreApplication::translate("MapWindow", "MainWindow", nullptr));
        moneyLable->setText(QCoreApplication::translate("MapWindow", "Money", nullptr));
        foodLabel->setText(QCoreApplication::translate("MapWindow", "Food", nullptr));
        woodLabel->setText(QCoreApplication::translate("MapWindow", "Wood", nullptr));
        stoneLabel->setText(QCoreApplication::translate("MapWindow", "Stone", nullptr));
        oreLabel->setText(QCoreApplication::translate("MapWindow", "Ore", nullptr));
        resourcesLabel->setText(QCoreApplication::translate("MapWindow", "Resources", nullptr));
        label_3->setText(QCoreApplication::translate("MapWindow", "Build", nullptr));
        hqButton->setText(QCoreApplication::translate("MapWindow", "HQ", nullptr));
        farmButton->setText(QCoreApplication::translate("MapWindow", "Farm", nullptr));
        sawButton->setText(QCoreApplication::translate("MapWindow", "Saw Mill", nullptr));
        outpustButton->setText(QCoreApplication::translate("MapWindow", "Outpost", nullptr));
        mineButton->setText(QCoreApplication::translate("MapWindow", "Mine", nullptr));
        smallHouseButton->setText(QCoreApplication::translate("MapWindow", "Small House", nullptr));
        largeHouseButton->setText(QCoreApplication::translate("MapWindow", "Large House", nullptr));
        apartmentsButton->setText(QCoreApplication::translate("MapWindow", "Apartments", nullptr));
        skyscraperButton->setText(QCoreApplication::translate("MapWindow", "Skyscraper", nullptr));
        label_8->setText(QCoreApplication::translate("MapWindow", "Worker Management", nullptr));
        assignButton->setText(QCoreApplication::translate("MapWindow", "Assign", nullptr));
        unassignButton->setText(QCoreApplication::translate("MapWindow", "Unassign", nullptr));
        bwButton->setText(QString());
        farmerButton->setText(QString());
        loggerButton->setText(QString());
        minerButton->setText(QString());
        pushButton->setText(QCoreApplication::translate("MapWindow", "End Turn", nullptr));
        highScoreButton->setText(QCoreApplication::translate("MapWindow", "Highscore", nullptr));
        highScoreButton_2->setText(QCoreApplication::translate("MapWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
