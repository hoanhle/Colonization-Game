#ifndef HIGHSCOREDIALOG_HH
#define HIGHSCOREDIALOG_HH

#include <QDialog>

namespace Ui {
class HighScoreDialog;
}

/**
 * @brief The HighScoreDialog class top 5 scores
 */
class HighScoreDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HighScoreDialog(QWidget *parent = nullptr);

    /**
     * @brief display top 5 scores to the leaderboard
     * @param highScoreDb a vecrtor that contain all the points
     * user has achieved
     */
    void setHighScoreInformation(std::vector<int> highScoreDb);
    ~HighScoreDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HighScoreDialog *ui;
};

#endif // HIGHSCOREDIALOG_HH
