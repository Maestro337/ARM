#include "finalorderdialog.h"
#include "ui_finalorderdialog.h"
#include <QMainWindow>

FinalOrderDialog::FinalOrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FinalOrderDialog)
{
    ui->setupUi(this);
}

QLabel *FinalOrderDialog::getCostLabel()
{
    return this->ui->costLabel;
}

FinalOrderDialog::~FinalOrderDialog()
{
    delete ui;
}

void FinalOrderDialog::on_OkButton_clicked()
{
    auto parent = dynamic_cast<QMainWindow*>(this->parent());
    auto parent_parent = dynamic_cast<QMainWindow*>(parent->parent());
    parent_parent->show();
    parent->hide();
    this->hide();

}

