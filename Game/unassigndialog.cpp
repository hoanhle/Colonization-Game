#include "unassigndialog.hh"
#include "ui_unassigndialog.h"

UnAssignDialog::UnAssignDialog(unsigned int workers_, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnAssignDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Free Workers");
    ui->workerSpinBox->setMaximum(workers_);
    ui->numberWorkersLabel->setText("You have " + QString::number(workers_)
                                    + " assigned workers in this block.");
}

UnAssignDialog::~UnAssignDialog()
{
    delete ui;
}

int UnAssignDialog::getNumberOfWorkers()
{
    return ui->workerSpinBox->value();
}

void UnAssignDialog::on_freeButton_clicked()
{
    emit freeWorkers();
    accept();
}
