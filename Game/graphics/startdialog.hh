#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>
#include "graphics/rulesdialog.hh"

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

signals:
    /**
     * @brief openRules signal to open ruleDialog
     */
    void openRules();

    /**
     * @brief openCredit signal to open creditDialog
     */
    void openCredit();

    /**
     * @brief openSetPlayers signal to open setplayerdialog
     */
    void openSetPlayers();

private slots:
    void on_startButton_clicked();
    void on_ruleButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::StartDialog *ui;

};

#endif // STARTDIALOG_HH
