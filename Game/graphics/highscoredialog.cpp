#include "highscoredialog.hh"
#include "ui_highscoredialog.h"
#include "iostream"

HighScoreDialog::HighScoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighScoreDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("High Scores Leaderboard");
}

void HighScoreDialog::setHighScoreInformation(std::vector<int> highScoreDb)
{
   if (highScoreDb.size() == 0){
       ui->label->setText("You have no points to show");
       return;
   }

   ui->label->setText("Your top scores");

   // Number of peple having high scores
   int k = 0;

   std::cout << highScoreDb[0];
   // Update high score Info on the dialog
   ui->score1->setText("1st place: " + QString::number(highScoreDb[0]) + " turns"); k++;
   if (k == highScoreDb.size()) return;
   ui->score2->setText("2nd place: " + QString::number(highScoreDb[1]) + " turns"); k++;
   if (k == highScoreDb.size()) return;
   ui->score3->setText("3rd place: " + QString::number(highScoreDb[2]) + " turns"); k++;
   if (k == highScoreDb.size()) return;
   ui->score4->setText("4th place: " + QString::number(highScoreDb[3]) + " turns"); k++;
   if (k == highScoreDb.size()) return;
   ui->score5->setText("5th place: " + QString::number(highScoreDb[4]) + " turns"); k++;
}


HighScoreDialog::~HighScoreDialog()
{
    delete ui;
}

void HighScoreDialog::on_pushButton_clicked()
{
    accept();
}
