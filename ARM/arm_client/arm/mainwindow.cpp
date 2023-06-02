#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "orderselector.h"
#include "wineserviceimpl.h"
#include "mixselector.h"
#include "wineorderserviceimpl.h"
#include "ingredientserviceimpl.h"
#include <mixorderserviceimpl.h>
#include "storageview.h"
#include "storageserviceimpl.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OrderButton_clicked()
{
    this->hide();
    QMainWindow* window = new OrderSelector(new WineServiceImpl(), new WineOrderServiceImpl(),this);
    window->show();
}


void MainWindow::on_MixButton_clicked()
{
    auto mixWindow = new MixSelector(new IngredientServiceImpl(), new MixOrderServiceImpl(),this);
    mixWindow->show();
    this->hide();
}


void MainWindow::on_StorageButton_clicked()
{
    auto storageView = new StorageView(new StorageServiceImpl,this);
    storageView->show();
    this->hide();
}

