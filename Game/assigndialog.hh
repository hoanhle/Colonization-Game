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
     * @param workers_ number of free workers
     * @param parent QWidget parent
     */
    explicit AssignDialog(unsigned int workers_, QWidget *parent = nullptr);
    ~AssignDialog();

    int getNumberOfWorkers();

signals:
    void setWorkers();

private slots:
    void on_assignButton_clicked();

private:
    Ui::AssignDialog *ui;
};

#endif // ASSIGNDIALOG_HH
