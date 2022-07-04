#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "city.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    City* getValues();

private slots:
   // void on_addCityDialog_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
