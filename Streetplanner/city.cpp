#include "city.h"
# include <QGraphicsTextItem >
City::City()
{

}


City::City(QString cityName , int x , int y)
{

    this->name = cityName;
    this->xPos = x;
    this->yPos = y;
}


void City::draw(QGraphicsScene& scene)
{

    scene.addEllipse(this->xPos,this->yPos, 30, 30,QPen(), QBrush(Qt::red , Qt::SolidPattern));
     QGraphicsTextItem * text = new QGraphicsTextItem() ;
     text->setPos(this->xPos , this->yPos);
     text -> setPlainText (this->name);
     scene.addItem ( text );
}

QString City::getName()
{
    return this->name;
}


int City::getX()
{
    return this->xPos;
}

int City::getY()
{
    return this->yPos;
}
