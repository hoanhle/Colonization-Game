#ifndef UNASSIGNDIALOG_HH
#define UNASSIGNDIALOG_HH

#include <QDialog>

namespace Ui {
class UnAssignDialog;
}

/**
 * @brief The UnAssignDialog class displays a dialog for player to free workers from a tile
 */
class UnAssignDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief UnAssignDialog
     * @param workers_ the number of assigned workers in the chosen tile
     * @param parent
     */
    explicit UnAssignDialog(unsigned int workers_, QWidget *parent = nullptr);

    ~UnAssignDialog();

    /**
     * @brief getNumberOfWorkers
     * @return the number of workers that we want to free
     */
    int getNumberOfWorkers();

signals:
    /**
     * @brief freeWorkers freeWorkers signal to send to slot that handles the event
     */
    void freeWorkers(int);

private slots:
    /**
     * @brief on_freeButton_clicked
     */
    void on_freeButton_clicked();

private:
    Ui::UnAssignDialog *ui;
};

#endif // UNASSIGNDIALOG_HH
