/********************************************************************************
** Form generated from reading UI file 'highscoredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCOREDIALOG_H
#define UI_HIGHSCOREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HighScoreDialog
{
public:
    QLabel *player4;
    QLabel *score1;
    QPushButton *pushButton;
    QLabel *score5;
    QLabel *player2;
    QLabel *score3;
    QLabel *player1;
    QLabel *label;
    QLabel *score2;
    QLabel *score4;
    QLabel *player3;
    QLabel *player5;

    void setupUi(QDialog *HighScoreDialog)
    {
        if (HighScoreDialog->objectName().isEmpty())
            HighScoreDialog->setObjectName(QString::fromUtf8("HighScoreDialog"));
        HighScoreDialog->resize(254, 312);
        player4 = new QLabel(HighScoreDialog);
        player4->setObjectName(QString::fromUtf8("player4"));
        player4->setGeometry(QRect(10, 170, 151, 21));
        score1 = new QLabel(HighScoreDialog);
        score1->setObjectName(QString::fromUtf8("score1"));
        score1->setGeometry(QRect(170, 80, 71, 21));
        pushButton = new QPushButton(HighScoreDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 260, 101, 31));
        score5 = new QLabel(HighScoreDialog);
        score5->setObjectName(QString::fromUtf8("score5"));
        score5->setGeometry(QRect(170, 200, 71, 21));
        player2 = new QLabel(HighScoreDialog);
        player2->setObjectName(QString::fromUtf8("player2"));
        player2->setGeometry(QRect(10, 110, 151, 21));
        score3 = new QLabel(HighScoreDialog);
        score3->setObjectName(QString::fromUtf8("score3"));
        score3->setGeometry(QRect(170, 140, 71, 21));
        player1 = new QLabel(HighScoreDialog);
        player1->setObjectName(QString::fromUtf8("player1"));
        player1->setGeometry(QRect(10, 80, 151, 21));
        label = new QLabel(HighScoreDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 231, 51));
        score2 = new QLabel(HighScoreDialog);
        score2->setObjectName(QString::fromUtf8("score2"));
        score2->setGeometry(QRect(170, 110, 71, 21));
        score4 = new QLabel(HighScoreDialog);
        score4->setObjectName(QString::fromUtf8("score4"));
        score4->setGeometry(QRect(170, 170, 71, 21));
        player3 = new QLabel(HighScoreDialog);
        player3->setObjectName(QString::fromUtf8("player3"));
        player3->setGeometry(QRect(10, 140, 151, 21));
        player5 = new QLabel(HighScoreDialog);
        player5->setObjectName(QString::fromUtf8("player5"));
        player5->setGeometry(QRect(10, 200, 151, 21));

        retranslateUi(HighScoreDialog);

        QMetaObject::connectSlotsByName(HighScoreDialog);
    } // setupUi

    void retranslateUi(QDialog *HighScoreDialog)
    {
        HighScoreDialog->setWindowTitle(QCoreApplication::translate("HighScoreDialog", "Dialog", nullptr));
        player4->setText(QCoreApplication::translate("HighScoreDialog", "Text label", nullptr));
        score1->setText(QCoreApplication::translate("HighScoreDialog", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("HighScoreDialog", "OK", nullptr));
        score5->setText(QCoreApplication::translate("HighScoreDialog", "TextLabel", nullptr));
        player2->setText(QCoreApplication::translate("HighScoreDialog", "Text label", nullptr));
        score3->setText(QCoreApplication::translate("HighScoreDialog", "TextLabel", nullptr));
        player1->setText(QCoreApplication::translate("HighScoreDialog", "Text label", nullptr));
        label->setText(QString());
        score2->setText(QCoreApplication::translate("HighScoreDialog", "TextLabel", nullptr));
        score4->setText(QCoreApplication::translate("HighScoreDialog", "TextLabel", nullptr));
        player3->setText(QCoreApplication::translate("HighScoreDialog", "Text label", nullptr));
        player5->setText(QCoreApplication::translate("HighScoreDialog", "Text label", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HighScoreDialog: public Ui_HighScoreDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCOREDIALOG_H
