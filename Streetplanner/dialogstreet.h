#ifndef DIALOGSTREET_H
#define DIALOGSTREET_H

#include <QDialog>
#include "street.h"
#include "map.h"
#include "QString"

namespace Ui {
class DialogStreet;
}

class DialogStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStreet(QWidget *parent = nullptr);
    ~DialogStreet();
    /**
     * @brief getValues - function that mainwindow calls to get a street connecting the cities the user entered in the DialogStreet
     * @param mp       - map passed by mainwindow in order to know the cities
     * @return Street*  returns pointer to Street
     */
    Street* getValues(Map* mp);

private slots:
    void on_addStreet_clicked();


private:
    Ui::DialogStreet *ui;
    QString City1;
    QString City2;
};

#endif // DIALOGSTREET_H
