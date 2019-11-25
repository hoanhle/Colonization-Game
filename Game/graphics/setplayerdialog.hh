#ifndef SETPLAYERDIALOG_HH
#define SETPLAYERDIALOG_HH

#include <QDialog>

namespace Ui {
class SetPlayerDialog;
}

class SetPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetPlayerDialog(QWidget *parent = nullptr);
    ~SetPlayerDialog();

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
