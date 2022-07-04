#include "street.h"

Street::Street()
{





}


 Street::Street(City* cityA , City* cityB)
 {

    this->cityFrom = cityA;
     this->cityTo = cityB;

 }


 void Street::draw(QGraphicsScene& scene)
 {
    // scene.addEllipse(this->xPos,this->xPos, 30, 30,QPen(), QBrush(Qt::red , Qt::SolidPattern));

    cityFrom->draw(scene);
    cityTo->draw(scene);
    scene.addLine(cityFrom->getX(), cityFrom->getY(), cityTo->getX(), cityTo->getY(),  QPen());

 }

 void Street::drawRed(QGraphicsScene& scene)
 {
     cityFrom->draw(scene);
     cityTo->draw(scene);
     scene.addLine(cityFrom->getX(), cityFrom->getY(), cityTo->getX(), cityTo->getY(),  QPen(Qt::red));

 }

 City* Street::getCityFrom() const
 {

     return this->cityFrom;
 }

 City* Street::getCityTo() const
 {
     return this->cityTo;
 }
