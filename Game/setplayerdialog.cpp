#include "setplayerdialog.hh"
#include "ui_setplayerdialog.h"
#include "startdialog.hh"

SetPlayerDialog::SetPlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetPlayerDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("SET NUMBER OF PLAYERS");
    ui->playersSpinBox->setMinimum(2);
    ui->playersSpinBox->setMaximum(4);
}

SetPlayerDialog::~SetPlayerDialog()
{
    delete ui;
}

int SetPlayerDialog::getNumberOfPlayers()
{
    return ui->playersSpinBox->value();
}

void SetPlayerDialog::on_setButton_clicked()
{
    hide();
    emit startGame();
}
