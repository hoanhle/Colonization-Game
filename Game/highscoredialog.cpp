#include "highscoredialog.hh"
#include "ui_highscoredialog.h"

HighScoreDialog::HighScoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighScoreDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("High Scores");
}

void HighScoreDialog::setHighScoreInformation(std::map<std::string, int> highScoreDb)
{
   if (highScoreDb.size() == 0){
       ui->label->setText("You have no points to show");
       return;
   }

   ui->label->setText("Your top scores");

   // Number of peple having high scores
   std::map<std::string, int>::size_type numPeople = 0;

}

HighScoreDialog::~HighScoreDialog()
{
    delete ui;
}

void HighScoreDialog::on_pushButton_clicked()
{

}
