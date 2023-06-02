#ifndef FINALORDERDIALOG_H
#define FINALORDERDIALOG_H

#include <QDialog>
#include <QLabel>
namespace Ui {
class FinalOrderDialog;
}

class FinalOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FinalOrderDialog(QWidget *parent = nullptr);
    QLabel* getCostLabel();
    ~FinalOrderDialog();

private slots:
    void on_OkButton_clicked();

private:
    Ui::FinalOrderDialog *ui;
};

#endif // FINALORDERDIALOG_H
