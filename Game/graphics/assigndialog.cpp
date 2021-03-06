#include "assigndialog.hh"
#include "ui_assigndialog.h"

AssignDialog::AssignDialog(unsigned int workers_, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AssignDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Assign Workers");
    ui->workerSpinBox->setMaximum(workers_);
    ui->numberWorkersLabel->setText("You can assign maximum " + QString::number(workers_)
                                    + " workers.");
}

AssignDialog::~AssignDialog()
{
    delete ui;
}

int AssignDialog::getNumberOfWorkers()
{
    return ui->workerSpinBox->value();
}

void AssignDialog::on_assignButton_clicked()
{
    int workerNumber = getNumberOfWorkers();
    emit setWorkers(workerNumber);
    accept();
}
