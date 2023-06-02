#ifndef ORDERSELECTOR_H
#define ORDERSELECTOR_H

#include <QMainWindow>
#include <wineservice.h>
#include "wine.h"
#include <vector>
#include "wineorderservice.h"

namespace Ui {
class OrderSelector;
}

class OrderSelector : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderSelector(WineService* wineService, WineOrderService* wineorderService,QWidget *parent = nullptr);
    ~OrderSelector();
    void updateTable(std::vector<Wine> wines);
private slots:
    void on_ShowAll_clicked();

    void on_orderButton_clicked();

    void on_CancelButton_clicked();

private:



    Ui::OrderSelector *ui;
    WineService* wineService;
    WineOrderService* wineOrderService;
};

#endif // ORDERSELECTOR_H
