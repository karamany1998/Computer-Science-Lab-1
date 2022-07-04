#include "dialogstreet.h"
#include "ui_dialogstreet.h"

DialogStreet::DialogStreet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStreet)
{
    ui->setupUi(this);
}

DialogStreet::~DialogStreet()
{
    delete ui;
}

void DialogStreet::on_addStreet_clicked()
{
    QString city1 = ui->lineEdit->text();
    QString city2 = ui->lineEdit_2->text();
    this->City1 = city1;
    this->City2 = city2;

}



Street* DialogStreet::getValues(Map* mp)
{
    //use the map to get a pointer to city from string(name of city)
    City* pCity1 = mp->findCity(this->City1);
    City* pCity2 = mp->findCity(this->City2);

    //if the cities don't exist in the map, then we can't have a street(return nullptr)
    if(pCity1 == nullptr || pCity2 == nullptr)return nullptr;

    //otherwise make a pointer to Street between the two cities and return it
    Street* newDialogStreet = new Street(pCity1 , pCity2);
    return newDialogStreet;


}
