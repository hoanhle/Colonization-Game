#ifndef UNASSIGNDIALOG_HH
#define UNASSIGNDIALOG_HH

#include <QDialog>

namespace Ui {
class UnAssignDialog;
}

class UnAssignDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UnAssignDialog(unsigned int workers_, QWidget *parent = nullptr);
    ~UnAssignDialog();

    int getNumberOfWorkers();

signals:
    void freeWorkers();

private slots:
    void on_freeButton_clicked();

private:
    Ui::UnAssignDialog *ui;
};

#endif // UNASSIGNDIALOG_HH
