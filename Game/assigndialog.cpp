#include "assigndialog.hh"
#include "ui_assigndialog.h"

assigndialog::assigndialog(unsigned int workers_, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assigndialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Assign Workers");
    ui->workerSpinBox->setMaximum(workers_);
    ui->numberWorkersLabel->setText("You have " + QString::number(workers_)
                                    + " free workers.");
}

assigndialog::~assigndialog()
{
    delete ui;
}

int assigndialog::getNumberOfWorkers()
{
    return ui->workerSpinBox->value();
}

void assigndialog::on_assignButton_clicked()
{
    emit setWorkers();
    accept();
}
