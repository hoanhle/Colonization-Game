#include "windialog.hh"
#include "ui_windialog.h"

WinDialog::WinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Game end!");
}

WinDialog::~WinDialog()
{
    delete ui;
}

void WinDialog::on_yesButton_clicked()
{
    accept();
}

void WinDialog::on_noButton_clicked()
{
    reject();
}
