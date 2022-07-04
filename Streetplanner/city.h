#ifndef CITY_H
#define CITY_H

#include "QString"
#include "QGraphicsScene"

class City
{
public:
    /**
     * @brief City Default Constructor
     */
    City();

    /**
     * @brief City Constructor with name and position as(x,y) coordinates
     * @param name - the name of the city as a QString
     * @param x    - x coordinate of the city position
     * @param y   y coordinate of the city position
     */
    City(QString name, int x, int y);


    /**
     * @brief draw - function to draw the city as a circle on the QGraphicsView
     * @param scene - type QGraphicsScene and is used to interact with the QGraphicsView to display items on the GUI
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief getName - getter fucntion to get city name
     * @return  QString
     */
    QString getName();

    /**
     * @brief getX - getter function to return city x coordinate
     * @return int
     */
    int getX();

    /**
     * @brief getY - getter function to return city y coordinate
     * @return int
     */
    int getY();


private:
    QString name;
    int xPos;
    int yPos;

};

#endif // CITY_H
