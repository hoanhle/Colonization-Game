#ifndef WINDIALOG_HH
#define WINDIALOG_HH

#include <QDialog>

namespace Ui {
class WinDialog;
}

class WinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinDialog(QWidget *parent = nullptr);
    ~WinDialog();

private slots:
    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::WinDialog *ui;
};

#endif // WINDIALOG_HH
