#ifndef ASSIGNDIALOG_HH
#define ASSIGNDIALOG_HH

#include <QDialog>

namespace Ui {
class AssignDialog;
}

class AssignDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief assigndialog constructor of this dialog
     * @param workers_ number of total free workers
     * @param parent QWidget parent
     */
    explicit AssignDialog(unsigned int workers_, QWidget *parent = nullptr);
    ~AssignDialog();

    /**
     * @brief getNumberOfWorkers
     * @return number of workers to assign to that building
     */
    int getNumberOfWorkers();

signals:
    void setWorkers(int workerNumber);

private slots:
    void on_assignButton_clicked();

private:
    Ui::AssignDialog *ui;
};

#endif // ASSIGNDIALOG_HH
