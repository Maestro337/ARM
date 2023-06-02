#include "mixselector.h"
#include <QCheckBox>
#include <string>
#include "ui_mixselector.h"
#include "ingredient.h"
#include "finalorderdialog.h"
#include "nothingdialog.h"
MixSelector::MixSelector(IngredientService* ingredientService,MixOrderService* mixOrderService,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MixSelector),
    ingredientService(ingredientService),
    mixorderservice(mixOrderService)
{
    ui->setupUi(this);
    auto ingredients = this->ingredientService->getAll();
    this->updateTable(ingredients);
}

MixSelector::~MixSelector()
{
    delete mixorderservice;
    delete ingredientService;
    delete ui;
}

void MixSelector::updateTable(const std::vector<Ingredient>& ingredients)
{
    QTableWidget* table = this->ui->table;
    table->setRowCount((int)ingredients.size());
    for (int i = 0; i < table->rowCount(); ++i) {
        for(int j = 0; j < table->columnCount(); ++j) {
            QTableWidgetItem* item = new QTableWidgetItem();
            if (j == 0) {
                QString string = QString::fromStdString(std::to_string(ingredients[i].getId()));
                item->setText(string);
            }
            if (j == 1) {
                QString string = QString::fromStdString(ingredients[i].getName());
                item->setText(string);
            }
            if (j == 2) {
                QString string = QString::fromStdString(std::to_string(ingredients[i].getPrice()));
                item->setText(string);
            }
            if (j == 3) {
                QCheckBox* btn_edit = new QCheckBox();
                table->setCellWidget(i, j, btn_edit);
            }
            else {

                table->setItem(i,j,item);
            }
        }
    }
}

void MixSelector::on_CancelButton_clicked()
{
    auto parent = dynamic_cast<QMainWindow*>(this->parent());
    this->hide();
    parent->show();
}


void MixSelector::on_mixButton_clicked()
{
    auto table = this->ui->table;
    std::vector<int> orderIds;
    int cost = 0;
    for (int i = 0; i < table->rowCount(); ++i) {
        QCheckBox* widget = dynamic_cast<QCheckBox*>(table->cellWidget(i,3));
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
    mixorderservice->orderByIds(orderIds);
    FinalOrderDialog* dialog = new FinalOrderDialog(this);
    auto label = dialog->getCostLabel();
    QString str = "Стоимость вашего заказа составляет: ";
    str.append(QString::fromStdString(std::to_string(cost) + "\n"));
    str.append("Забрать можете на пункте выдачи заказов");
    label->setText(str);
    dialog->setModal(true);
    dialog->exec();

}

