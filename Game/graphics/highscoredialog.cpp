#include "highscoredialog.hh"
#include "ui_highscoredialog.h"

HighScoreDialog::HighScoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighScoreDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("High Scores");
}

void HighScoreDialog::setHighScoreInformation(std::vector<playerInfo> highScoreDb)
{
    if (highScoreDb.size() == 0){
           ui->label->setText("You have no points to show");
           return;
       }

       ui->label->setText("Your top scores");

       // Number of peple having high scores
       int k = 0;

       // Update high score Info on the dialog
       ui->player1->setText(QString::fromStdString(highScoreDb[0].first)); k++;
       ui->score1->setText(QString::number(highScoreDb[0].second));
       if (k == highScoreDb.size()) return;
       ui->player2->setText(QString::fromStdString(highScoreDb[1].first)); k++;
       ui->score2->setText(QString::number(highScoreDb[1].second));
       if (k == highScoreDb.size()) return;
       ui->player3->setText(QString::fromStdString(highScoreDb[2].first)); k++;
       ui->score3->setText(QString::number(highScoreDb[2].second));
       if (k == highScoreDb.size()) return;
       ui->player4->setText(QString::fromStdString(highScoreDb[3].first)); k++;
       ui->score4->setText(QString::number(highScoreDb[3].second));
       if (k == highScoreDb.size()) return;
       ui->player5->setText(QString::fromStdString(highScoreDb[4].first)); k++;
       ui->score5->setText(QString::number(highScoreDb[4].second));
}


HighScoreDialog::~HighScoreDialog()
{
    delete ui;
}

void HighScoreDialog::on_pushButton_clicked()
{
    accept();
}
