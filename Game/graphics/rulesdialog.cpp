#include "rulesdialog.hh"
#include "ui_rulesdialog.h"

RulesDialog::RulesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RulesDialog)
{
    ui->setupUi(this);
    ui->label->setWordWrap(true);
    this->setWindowTitle("HOW TO PLAY");
}

RulesDialog::~RulesDialog()
{
    delete ui;
}

void RulesDialog::on_pushButton_clicked()
{
    hide();
    emit backToStart();
}
