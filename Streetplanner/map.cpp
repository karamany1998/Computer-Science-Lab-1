#include "map.h"
#include <QDebug>

Map::Map()
{

}



void Map::addCity(City *city)
{
        //add pointer to city in the attribute cities
        this->cities.push_back(city);
        qDebug() << city->getName()<<"was added to map";
}


void Map::draw(QGraphicsScene& scene)
{

       //loop over cities and use the city draw function to draw each city
      for (qsizetype i = 0; i < this->cities.size(); ++i)
      {
            this->cities[i]->draw(scene);
      }

      //loop over streets to draw them
      for (qsizetype i = 0; i < this->streets.size(); ++i)
      {
           this->streets[i]->draw(scene);
      }
}

/**
 * @brief Map::addStreet - function that takes a street between two different cities
 * @param street - pointer to Street Object
 * @return  - true if the cities exist in the map and false if one or both cities do not exist which means street would not be added
 */
bool Map::addStreet(Street* street)
{
    //if map does not have cities , then return false
    if(cities.size()==0)return false;



    bool check = false;
    //go over cities that are saved in the map and check if the cities connecting the street are inside map
    for(int i = 0 ; i<this->cities.size() ; i++)
    {
        //cityFrom found break out of loop

        if(cities[i] == street->getCityFrom())
        {
            check = true;
            break;
        }
    }
    //if not found then return false
    if(!check)return check;

    check = false; // do another check for the other city
    for(int i = 0 ; i<this->cities.size() ; i++)
    {
        //cityTo found break out of loop
        if(cities[i] == street->getCityTo())
        {
            check = true;
            break;
        }
    }
     //if not found then return false
    if(!check)return check;

    //if reach this point, then both cities are inside map
    //add street to Map

    this->streets.push_back(street);
    //street->draw(scene);
    return true;

}



City* Map::findCity(const QString cityName) const
{
    int mapSize = cities.size();    //how many cities in map

    for(int i = 0 ; i<mapSize ; i++)
    {
        if(cities[i]->getName() == cityName)    //if city is found
        {
            return cities[i];                   //return a pointer to city
        }
    }

    return nullptr;
}


QVector<Street*> Map::getStreetList(const City* city) const
{
    int size = this->streets.size();    //size of street
    QVector<Street*> streetWithCity;    //vector of streets that have city

    for(int i = 0 ; i<size ; i++)   //loop over all streets
    {
        if(this->streets[i]->getCityFrom() == city || this->streets[i]->getCityTo() == city)    //if the street is connected to the city
        {
            streetWithCity.push_back(streets[i]);   //add street to list
        }

    }

    return streetWithCity;
}


City* Map::getOppositeCity(const Street* street, const City* city) const
{

    if(street->getCityFrom() == city)   //basically for each street, check if the argument city if From or To and return the opposite city
    {
        return street->getCityTo();
    }
    if(street->getCityTo() == city)
    {
        return street->getCityFrom();
    }

    return nullptr;

}


double Map::getLength(const Street* street) const
{

    //x1 and y1 are the coordinates of the first city
    int x1 = street->getCityFrom()->getX();
    int y1 = street->getCityFrom()->getY();

    //x2 and y2 are the coordinates of the second city
    int x2 = street->getCityTo()->getX();
    int y2 = street->getCityTo()->getY();

    //calculate distance using distance formula sqrt( (x1-x2)^2 + (y1-y2)^2 )
    double dist = (x1-x2)*(x1-x2) + (y1 - y2)*(y1-y2);
    dist = sqrt(dist);
    return dist;

}

QVector<City*> Map::getCities() const
{

    return this->cities;
}
