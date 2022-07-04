#include "mainwindow.h"
#include "city.h"
#include "street.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <QCheckBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    this->mapIO = new MapIoNrw();
    QVector<City* > allCities = map.getCities();
    for(int i = 0 ; i<allCities.size() ; i++)
    {
        ui->comboBox->addItem(allCities[i]->getName());
        ui->comboBox_2->addItem(allCities[i]->getName());
    }





}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString userInput = ui->lineEdit->text();
    bool isNum;
    int x = userInput.toInt(&isNum);
     QMessageBox msgBox ;

     scene.addRect(100, 100 , 100 , 100 , QPen (Qt :: red ) , QBrush (Qt :: red , Qt :: SolidPattern ));



    if(isNum)
    {
        QString strOut = QString("The user inputed the number %1").arg(x+4);
        qDebug() << strOut;
        QString newStr = QString("User Inputed a number: %1").arg(x);
        msgBox.setText(newStr);
        msgBox.exec();

       // scene.addRect(5 , 5 , 100 , 100);

    }
    else
    {
        QString strOut = QString("The user did not input a number %1").arg(userInput);
        qDebug() << strOut;
        msgBox.setText(strOut);
        msgBox.exec();
    }


    }


void MainWindow::on_actionExit_triggered()
{

    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msg;
    QString title = QString("Information: ");
    QString txt = QString("This is the last exercise of praktikum Informatik 1 and focusses on learning the basics of GUI development using Qt");
    msg.about(this,title, txt );
}




//test draw function for city
void MainWindow::on_pushButton_2_clicked()
{


    City city1 = City(QString("Munich") , 30 , 30 );
    City city2 = City(QString("London") , 100 , 100 );


    city1.draw(scene);
    city2.draw(scene);

      qDebug() << "Inside City Draw function";

}



//test function for drawing map
void MainWindow::on_mapDrawTest_clicked()
{
    City c1("city c1", 20,50);
    map.addCity(&c1);

    map.draw(this->scene);

    qDebug() << "Inside Map Draw function";

}

//test function for drawing streets
void MainWindow::on_streetDrawTest_clicked()
{
       Map testMap;
       City *a = new City("a", 0, 0);
       City *b = new City("b", 0, 100);
       City *c = new City("c", 100, 300);
       Street *s = new Street(a, b);
       Street *s2 = new Street(b, c);


       qDebug() << "MapTest: Start Test of the Map";
       {
           qDebug() << "MapTest: adding wrong street";
           bool t1 = testMap.addStreet(s);
           if (t1) {
               qDebug() << "-Error: Street should not bee added, if cities have not been added.";
           }
       }

       {
           qDebug() << "MapTest: adding correct street";
           testMap.addCity(a);
           testMap.addCity(b);
           bool t1 = testMap.addStreet(s);
           if (!t1) {
               qDebug() << "-Error: It should be possible to add this street.";
           }
       }

}




//when check box is clicked
void MainWindow::on_checkBox_clicked()
{
    //if the check box is checked, then hide the test buttons
    if(ui->checkBox->isChecked())
    {
        ui->mapDrawTest->hide();
        ui->pushButton_2->hide();
        ui->streetDrawTest->hide();
    }
    else    //otherwise, show the buttons
    {
        ui->mapDrawTest->show();
        ui->pushButton_2->show();
        ui->streetDrawTest->show();

    }
}

//for Dialog to add City
void MainWindow::on_pushButton_3_clicked()
{
    Dialog addCityDialog;
    //addCityDialog.setModal(true);
    addCityDialog.exec(); //returns either QDialog::Accepted(value = 1) or QDialog::Rejected(value=0)

    City* dialogCity = addCityDialog.getValues();   //get the information passed from user in dialog as a pointer

    //if dialogCity==nullptr, then the user entered a non-int in the x and y coordinates and this would not be accepted an an entry
    if(dialogCity == nullptr)
    {
           qDebug()<<"Enter int values for x and y positions";
    }
    else    //otherwise use the draw function to draw the city
    {
        dialogCity->draw(scene);

        ui->comboBox->addItem(dialogCity->getName());   //when city is added successfully add it to combo box
        ui->comboBox_2->addItem(dialogCity->getName());


    }
}



//when fill map is clicked
void MainWindow::on_fillMap_clicked()
{
    //use the fill map function in the mapIONrw class to fill the private attribute map
    this->mapIO->fillMap(this->map);

    //use the draw function of map to draw the cities and streets added from the map io
    this->map.draw(scene);


    //after map is filled, add the cities to checkBox to allow user to connect streets
    QVector<City* > allCities = map.getCities();
    for(int i = 0 ; i<allCities.size() ; i++)
    {
        ui->comboBox->addItem(allCities[i]->getName());
        ui->comboBox_2->addItem(allCities[i]->getName());
    }

}


void MainWindow::on_pushButton_4_clicked()
{

}


//test abstract map
void MainWindow::on_testAbstractMap_clicked()
{
        Map testMap;
        City *a = new City("a", 0, 0);
        City *b = new City("b", 0, 100);
        City *c = new City("c", 100, 300);
        Street *s = new Street(a, b);
        Street *s2 = new Street(b, c);


        qDebug() << "MapTest: Start Test of the Map";
        {
            qDebug() << "MapTest: adding wrong street";
            bool t1 = testMap.addStreet(s);
            if (t1) {
                qDebug() << "-Error: Street should not bee added, if cities have not been added.";
            }
        }

        {
            qDebug() << "MapTest: adding correct street";
            testMap.addCity(a);
            testMap.addCity(b);
            bool t1 = testMap.addStreet(s);
            if (!t1) {
                qDebug() << "-Error: It should be possible to add this street.";
            }
        }

        {
            qDebug() << "MapTest: findCity";
            City* city = testMap.findCity("a");
            if (city != a)
                qDebug() << "-Error: City a could not be found.";

            city = testMap.findCity("b");
            if (city != b)
                qDebug() << "-Error: City b could not be found.";

            city = testMap.findCity("c");
            if (city != nullptr)
                qDebug() << "-Error: If city could not be found 0 should be returned.";
        }

        testMap.addCity(c);
        testMap.addStreet(s2);

        {
            qDebug() << "MapTest: getOppositeCity";
            const City *city = testMap.getOppositeCity(s, a);
            if (city != b)
                qDebug() << "-Error: Opposite city should be b.";

            city = map.getOppositeCity(s, c);
            if (city != nullptr)
                qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
        }

        {
            qDebug() << "MapTest: streetLength";
            double l = testMap.getLength(s2);
            double expectedLength = 223.6;
            // compare doubles with 5% tolerance
            if (l < expectedLength * 0.95 || l > expectedLength *1.05)
                qDebug() << "-Error: Street Length is not equal to the expected.";

        }

        {
            qDebug() << "MapTest: getStreetList";
            QVector<Street*> streetList1 = testMap.getStreetList(a);
            QVector<Street*> streetList2 = testMap.getStreetList(b);
            if (streetList1.size() != 1) {
                qDebug() << "-Error: One street should be found for city a.";
            }
            else if (*streetList1.begin() != s) {
                    qDebug() << "-Error: The wrong street has been found for city a.";
            }

            if (streetList2.size() != 2)
                qDebug() << "-Error: Two streets should be found for city b.";
        }

        qDebug() << "MapTest: End Test of the Map.";
}


//test dijkstra between 3 cities a->b->c
void MainWindow::on_testDijkstra_clicked()
{


    qDebug()<<"testDijkstra";

    //the map used to test Dikstra's algorith,
    Map testMapDijkstra;
    qDebug()<<"city a ";

    //initialize 3 cities
    City *a = new City("a", 0, 0);
    qDebug()<<"city b ";
    City *b = new City("b", 0, 100);
    qDebug()<<"city c ";
    City *c = new City("c", 100, 300);


    qDebug()<<"first street: a->b";
    //connect city a to b and city b to c in streets s and s2 respectively
    Street *s = new Street(a, b);
    qDebug()<<"second street: b->c";
    Street *s2 = new Street(b, c);

    //add cities to map
    testMapDijkstra.addCity(a);
    testMapDijkstra.addCity(b);
    testMapDijkstra.addCity(c);

    testMapDijkstra.addStreet(s);
    testMapDijkstra.addStreet(s2);


    qDebug()<<"check if there's a connection between a and c";
    /*
    use Dikstra's algorithm
    search is a static function, so we don't need to have an object of class Dijkstra, we can use the scope resolution operator
    to access the function directly
    */
    QVector<Street*> connection = Dijkstra::search(testMapDijkstra , a->getName() , c->getName());


    if(connection.size() != 0 )
    {
        for(int i = 0 ; i<connection.size() ; i++)
        {
            qDebug() << connection[i]->getCityFrom()->getName() <<"connected to " << connection[i]->getCityTo()->getName();
            connection[i]->drawRed(scene);
        }
    }



}

/**
 * @brief MainWindow::on_runDijkstra_clicked allows us to use Dijkstra's algorithm to find a path between two cities
*/
void MainWindow::on_runDijkstra_clicked()
{

    //QString source =  ui->dijkstraSource->text();
    //QString target = ui->dijkstraTarget->text();

    //! use combo box to take source city and target city for dijkstra
    QString source = ui->comboBox->currentText();
    QString target = ui->comboBox_2->currentText();


    //Dijkstra will return a vector of Street pointers
    QVector<Street*> connection = Dijkstra::search(map , source ,target);

    //if there's a connection, then print it out on the console
    if(connection.size() != 0 )
    {
        for(int i = 0 ; i<connection.size() ; i++)
        {
            qDebug() << connection[i]->getCityFrom()->getName() <<"connected to " << connection[i]->getCityTo()->getName();
            connection[i]->drawRed(scene);
        }
    }
    else    //otherwise no connection between cities
    {
        qDebug() << "No Connection Between inputs" ;
    }

}



/**
 * @brief MainWindow::on_addStreet_clicked - uses a Dialog to add a street between two cities
 */
void MainWindow::on_addStreet_clicked()
{
    DialogStreet addStreetDialog;
    //addStreetDialog.setModal(true);
    addStreetDialog.exec(); //returns either QDialog::Accepted(value = 1) or QDialog::Rejected(value=0)

    Street* dialogStreet = addStreetDialog.getValues(&map);   //get the information passed from user in dialog as a pointer

    //if dialogStreet==nullptr, then the user entered a false input(eg. cities don't exist)
    if(dialogStreet == nullptr)
    {
           qDebug()<<"Please Enter correct values for cities as could not find information about the cities in our map";
    }
    else    //otherwise use the draw function to draw the city
    {
        qDebug() << "Street Added Successfully";
        map.addStreet(dialogStreet);

        //draw street(comment out if you want)
        dialogStreet->draw(scene);
    }

}

//no need to consider this
void MainWindow::on_comboBox_activated(const QString &arg1)
{



}

