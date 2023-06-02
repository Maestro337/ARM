#include "nothingdialog.h"
#include "ui_nothingdialog.h"

NothingDialog::NothingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NothingDialog)
{
    ui->setupUi(this);
}

NothingDialog::~NothingDialog()
{
    delete ui;
}

void NothingDialog::on_pushButton_clicked()
{
    this->hide();
}

