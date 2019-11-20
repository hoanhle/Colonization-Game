#include "startdialog.hh"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    ui->label->setWordWrap(true);
    this->setWindowTitle("START GAME");
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_startButton_clicked()
{
    hide();
    emit openSetPlayers();

}


void StartDialog::on_ruleButton_clicked()
{
    emit openRules();
}
