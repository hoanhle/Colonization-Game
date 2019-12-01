#ifndef WINDIALOG_HH
#define WINDIALOG_HH

#include <QDialog>

namespace Ui {
class WinDialog;
}

/**
 * @brief The WinDialog class displays the dialog to ask if the player want to play again
 */
class WinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinDialog(QWidget *parent = nullptr);

    ~WinDialog();

private slots:
    /**
     * @brief on_yesButton_clicked players want to play the game again
     */
    void on_yesButton_clicked();

    /**
     * @brief on_noButton_clicked players want to end game
     */
    void on_noButton_clicked();

private:
    Ui::WinDialog *ui;
};

#endif // WINDIALOG_HH
