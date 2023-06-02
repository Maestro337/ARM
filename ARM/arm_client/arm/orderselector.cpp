#include "orderselector.h"
#include "ui_orderselector.h"
#include <QCheckBox>
#include <finalorderdialog.h>
#include "nothingdialog.h"
OrderSelector::OrderSelector(WineService* wineservice,WineOrderService* wineOrderService,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrderSelector),
    wineService(wineservice),
    wineOrderService(wineOrderService)
{
    ui->setupUi(this);
    auto wines = this->wineService->getAll();
    this->updateTable(wines);
}

OrderSelector::~OrderSelector()
{
    delete wineService;
    delete wineOrderService;
    delete ui;
}

void OrderSelector::updateTable(std::vector<Wine> wines)
{
    QTableWidget* table = this->ui->table;
    table->setRowCount((int)wines.size());
    for (int i = 0; i < table->rowCount(); ++i) {
        for(int j = 0; j < table->columnCount(); ++j) {
            QTableWidgetItem* item = new QTableWidgetItem();
            if (j == 0) {
                QString string = QString::fromStdString(std::to_string(wines[i].getId()));
                item->setText(string);
            }
            if (j == 1) {
                QString string = QString::fromStdString(wines[i].getName());
                item->setText(string);
            }
            if (j == 2) {

                QString string = QString::fromStdString(std::to_string(wines[i].getPrice()));
                item->setText(string);
            }
            if (j == 3) {
                auto props = wines[i].getProperties();
                QString string;
                for (auto& p : props) {
                    string.append(p.c_str());
                    string.append(' ');
                }
                item->setText(string);
            }
            if (j == 4) {
                QCheckBox* btn_edit = new QCheckBox();
                table->setCellWidget(i, j, btn_edit);
            }
            else {

                table->setItem(i,j,item);
            }
        }
    }
}

void OrderSelector::on_ShowAll_clicked()
{
    auto sugar = this->ui->SugarSelector->currentText();
    auto color = this->ui->ColorSelector->currentText();
    auto res = std::vector<Wine>();
    auto wines = this->wineService->getAll();
    for (auto& wine : wines) {
        if (wine.getProperties().find(color.toStdString()) != wine.getProperties().end()) {
            if (wine.getProperties().find(sugar.toStdString()) != wine.getProperties().end()) {
                res.push_back(wine);
            }
        }
    }
    this->updateTable(res);
    auto mainWindow = dynamic_cast<QMainWindow*>(this->parent());
    mainWindow->show();
}


void OrderSelector::on_orderButton_clicked()
{
    auto table = this->ui->table;
    std::vector<int> orderIds;
    int cost = 0;
    for (int i = 0; i < table->rowCount(); ++i) {
        QCheckBox* widget = dynamic_cast<QCheckBox*>(table->cellWidget(i,4));
        if (widget->isChecked()) {
            orderIds.push_back(table->item(i,0)->text().toInt());
            cost += table->item(i,2)->text().toInt();
        }
    }
    if (cost == 0) {
        auto dialog = new NothingDialog();
        dialog->setModal(true);
        dialog->exec();
        return;
    }
    wineOrderService->orderByIds(orderIds);

    FinalOrderDialog* dialog = new FinalOrderDialog(this);
    auto label = dialog->getCostLabel();
    QString str = "Стоимость вашего заказа составляет: ";
    str.append(QString::fromStdString(std::to_string(cost) + "\n"));
    str.append("Забрать можете на пункте выдачи заказов");
    label->setText(str);
    dialog->setModal(true);
    dialog->exec();
}


void OrderSelector::on_CancelButton_clicked()
{
    auto parent = dynamic_cast<QMainWindow*>(this->parent());
    this->hide();
    parent->show();
}

