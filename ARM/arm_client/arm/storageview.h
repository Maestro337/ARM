#ifndef STORAGEVIEW_H
#define STORAGEVIEW_H

#include <QMainWindow>
#include <storageservice.h>

namespace Ui {
class StorageView;
}

class StorageView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StorageView(StorageService* storageService,QWidget *parent = nullptr);
    ~StorageView();

    void updateTable(const std::vector<Storage> &ingredients);
private slots:
    void on_CloseButton_clicked();

private:
    StorageService* storageService;
    Ui::StorageView *ui;
};

#endif // STORAGEVIEW_H
