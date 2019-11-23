#ifndef RULESDIALOG_HH
#define RULESDIALOG_HH

#include <QDialog>

namespace Ui {
class RulesDialog;
}

class RulesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RulesDialog(QWidget *parent = nullptr);
    ~RulesDialog();

signals:
    void backToStart();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RulesDialog *ui;
};

#endif // RULESDIALOG_HH
