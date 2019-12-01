#ifndef SETPLAYERDIALOG_HH
#define SETPLAYERDIALOG_HH

#include <QDialog>

namespace Ui {
class SetPlayerDialog;
}

/**
 * @brief The SetPlayerDialog class display the dialog to set number of players
 */
class SetPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetPlayerDialog(QWidget *parent = nullptr);

    ~SetPlayerDialog();

    /**
     * @brief get the number of players
     * @return
     */
    int getNumberOfPlayers();

signals:
    /**
     * @brief startGame signal to open mapwindow
     */
    void startGame(int playerNumbers);

private slots:
    void on_setButton_clicked();

private:
    Ui::SetPlayerDialog *ui;
};

#endif // SETPLAYERDIALOG_HH
