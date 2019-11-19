#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>

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
    void startGame();

private slots:
    void on_startButton_clicked();

private:
    Ui::StartDialog *ui;
};

#endif // STARTDIALOG_HH
