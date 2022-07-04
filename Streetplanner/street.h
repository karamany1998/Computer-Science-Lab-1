#ifndef STREET_H
#define STREET_H

#include "city.h"
#include "QMap"
#include "QGraphicsScene"


class Street
{
public:
    /**
     * @brief Street - constructor for class street
     */
    Street();

    /**
     * @brief Street - constructor that takes in two pointer to cities
     */
    Street(City* , City*);

    /**
     * @brief draw - function that draws the street as a line
     * @param scene
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief drawRed - function used to draw the street in red to determine path taken using dijkstra's algorithm
     * @param scene
     */
    void drawRed(QGraphicsScene& scene);

    /**
     * @brief getCityFrom - getter
     * @return
     */
    City* getCityFrom() const;

    /**
     * @brief getCityTo - getter
     * @return
     */
    City* getCityTo() const;


private:
    //QMap<City* , QList<City*>> streetConnections;  //implement the connections between cities as a adjacency list
                                      //where streetConnections[CityA] is a list of all cities that are connected to CityA

    City* cityFrom;
    City* cityTo;
};

#endif // STREET_H
