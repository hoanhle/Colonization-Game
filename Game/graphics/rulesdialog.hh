#ifndef RULESDIALOG_HH
#define RULESDIALOG_HH

#include <QDialog>

namespace Ui {
class RulesDialog;
}

/**
 * @brief The RulesDialog class display the rule for players to read
 */
class RulesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RulesDialog(QWidget *parent = nullptr);

    ~RulesDialog();

signals:
    /**
     * @brief back to the start dialog
     */
    void backToStart();

private slots:
    /**
     * @brief on_pushButton_clicked
     */
    void on_pushButton_clicked();

private:
    Ui::RulesDialog *ui;
};

#endif // RULESDIALOG_HH
