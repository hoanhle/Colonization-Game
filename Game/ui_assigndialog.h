/********************************************************************************
** Form generated from reading UI file 'assigndialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNDIALOG_H
#define UI_ASSIGNDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AssignDialog
{
public:
    QLabel *label;
    QSpinBox *workerSpinBox;
    QPushButton *assignButton;
    QLabel *numberWorkersLabel;

    void setupUi(QDialog *AssignDialog)
    {
        if (AssignDialog->objectName().isEmpty())
            AssignDialog->setObjectName(QString::fromUtf8("AssignDialog"));
        AssignDialog->resize(480, 227);
        label = new QLabel(AssignDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 191, 31));
        workerSpinBox = new QSpinBox(AssignDialog);
        workerSpinBox->setObjectName(QString::fromUtf8("workerSpinBox"));
        workerSpinBox->setGeometry(QRect(260, 71, 151, 31));
        assignButton = new QPushButton(AssignDialog);
        assignButton->setObjectName(QString::fromUtf8("assignButton"));
        assignButton->setGeometry(QRect(170, 130, 121, 31));
        numberWorkersLabel = new QLabel(AssignDialog);
        numberWorkersLabel->setObjectName(QString::fromUtf8("numberWorkersLabel"));
        numberWorkersLabel->setGeometry(QRect(50, 50, 191, 16));

        retranslateUi(AssignDialog);

        QMetaObject::connectSlotsByName(AssignDialog);
    } // setupUi

    void retranslateUi(QDialog *AssignDialog)
    {
        AssignDialog->setWindowTitle(QCoreApplication::translate("AssignDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AssignDialog", "Enter the number of workers you want to assign:", nullptr));
        assignButton->setText(QCoreApplication::translate("AssignDialog", "Assign", nullptr));
        numberWorkersLabel->setText(QCoreApplication::translate("AssignDialog", "You have 10 free workers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssignDialog: public Ui_AssignDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNDIALOG_H
