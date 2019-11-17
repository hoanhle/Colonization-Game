#ifndef ASSIGNDIALOG_HH
#define ASSIGNDIALOG_HH

#include <QDialog>

namespace Ui {
class assigndialog;
}

class assigndialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief assigndialog constructor of this dialog
     * @param workers_ number of free workers
     * @param parent QWidget parent
     */
    explicit assigndialog(unsigned int workers_, QWidget *parent = nullptr);
    ~assigndialog();

    int getNumberOfWorkers();

signals:
    void setWorkers();

private slots:
    void on_assignButton_clicked();

private:
    Ui::assigndialog *ui;
};

#endif // ASSIGNDIALOG_HH
