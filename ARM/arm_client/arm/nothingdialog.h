#ifndef NOTHINGDIALOG_H
#define NOTHINGDIALOG_H

#include <QDialog>

namespace Ui {
class NothingDialog;
}

class NothingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NothingDialog(QWidget *parent = nullptr);
    ~NothingDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NothingDialog *ui;
};

#endif // NOTHINGDIALOG_H
