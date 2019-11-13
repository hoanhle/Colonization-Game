#ifndef HIGHSCOREDIALOG_HH
#define HIGHSCOREDIALOG_HH

#include <QDialog>

namespace Ui {
class HighScoreDialog;
}

typedef std::pair<std::string, int> playerInfo;

class HighScoreDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HighScoreDialog(QWidget *parent = nullptr);

    void setHighScoreInformation(std::vector<playerInfo> highScoreDb);
    ~HighScoreDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HighScoreDialog *ui;
};

#endif // HIGHSCOREDIALOG_HH
