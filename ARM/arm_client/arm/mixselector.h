#ifndef MIXSELECTOR_H
#define MIXSELECTOR_H

#include <QMainWindow>
#include "ingredientservice.h"
#include "mixorderservice.h"
namespace Ui {
class MixSelector;
}

class MixSelector : public QMainWindow
{
    Q_OBJECT

public:
    explicit MixSelector(IngredientService* ingredientService,MixOrderService* mixOrderService,QWidget *parent = nullptr);
    ~MixSelector();
    void updateTable(const std::vector<Ingredient>& ingredients);
private slots:
    void on_CancelButton_clicked();

    void on_mixButton_clicked();

private:
    Ui::MixSelector *ui;
    IngredientService* ingredientService;
    MixOrderService* mixorderservice;
};

#endif // MIXSELECTOR_H
