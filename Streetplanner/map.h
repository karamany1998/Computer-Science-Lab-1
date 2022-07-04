#ifndef MAP_H
#define MAP_H

#include <QList>
#include <QVector>
#include "city.h"
#include "abstractmap.h"
#include "street.h"

class Map : public AbstractMap
{
public:
    /**
     * @brief Map - Default constructor for class map
     */
    Map();

    /**
     * @brief addCity - function that takes a pointer to city and adds this pointer to the private attribute cities
     */
    void addCity(City*);

    /**
     * @brief draw - function that draws all the cities in the map
     * @param scene
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief addStreet - function to add the street to the private attribute streets
     * @return bool - if cities inside Street do not exist in map, then return false , otherwise return true
     */
    virtual bool addStreet(Street*);



    /**
     * @brief findCity - function that searches QVector<City*> cities for a city with same name as argument passed in
     * @param cityName - name of city as a QString type
     * @return City* pointer to city
     */
    virtual City* findCity(const QString cityName) const;


    virtual QVector<Street*> getStreetList(const City* city) const ;
    virtual City* getOppositeCity(const Street* street, const City* city) const;

    /**
     * @brief getLength - function that determines the length of the street using the distance forumla
     * @param street
     * @return double - lenght of the street
     */
    virtual double getLength(const Street* street) const;


    /**
     * @brief getCities - helper function
     * @return QVector<City* >
     */
    QVector<City* > getCities() const;


private:
    QVector<City*> cities;
    QVector<Street*> streets;
};

#endif // MAP_H
