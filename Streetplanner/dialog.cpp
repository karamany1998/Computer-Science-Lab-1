#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
   getValues();
}


City* Dialog::getValues()
{
    QString cityString = ui->lineEdit->text();
    QString xPos = ui->lineEdit_2->text();
    QString yPos = ui->lineEdit_3->text();
    bool isNumX;
    bool isNumY;
    int x = xPos.toInt(&isNumX);
    int y = yPos.toInt(&isNumY);

    if(!isNumX || !isNumY)
    {
        return nullptr; // if user entered false data, then return nullptr
    }


    City* city = new City(cityString , x , y);

    return city;
}

