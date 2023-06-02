#include "storageview.h"
#include "ui_storageview.h"


StorageView::StorageView(StorageService *storageService, QWidget *parent):
    QMainWindow(parent),
    storageService(storageService),
    ui(new Ui::StorageView)
{
    ui->setupUi(this);
    auto stor = this->storageService->getAll();
    updateTable(stor);
}

void StorageView::updateTable(const std::vector<Storage>& stor)
{
    QTableWidget* table = this->ui->table;
    table->setRowCount((int)stor.size());
    for (int i = 0; i < table->rowCount(); ++i) {
        for(int j = 0; j < table->columnCount(); ++j) {
            QTableWidgetItem* item = new QTableWidgetItem();
            if (j == 0) {
                QString string = QString::fromStdString(std::to_string(stor[i].getWine().getId()));
                item->setText(string);
            }
            if (j == 1) {
                QString string = QString::fromStdString(stor[i].getWine().getName());
                item->setText(string);
            }
            if (j == 2) {
                QString string = QString::fromStdString(std::to_string(stor[i].getCount()));
                item->setText(string);
            }
            table->setItem(i,j,item);
        }
    }
}

StorageView::~StorageView()
{
    delete ui;
}

void StorageView::on_CloseButton_clicked()
{
    auto parent = dynamic_cast<QMainWindow*>(this->parent());
    this->hide();
    parent->show();
}

