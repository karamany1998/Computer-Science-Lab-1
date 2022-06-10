//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXI
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <cmath>

const double PI = atan(1)*4;

int main()
{


    //position1 steht ist 6371km + 0.5574km
    Vektor position1(0,6371.5574 ,0); //start position

    //position2 ist der Erde-Radius
    Vektor position2(0 , 6371  , 0); //earth radius vector

    Vektor sehVektor(0,0,0);		//distance from person to horizon
    Vektor heightOfPlatform(0,555.7, 0);
    Vektor heightOfPerson(0 , 1.7 , 0);
    double stepInRadians = 0.0000001; //rotation of the earth radius vector


    int schritt= 0 ;



    while(true)
    {

    	position2.rotiereUmZ(stepInRadians); //rotate the position2 vector

    	sehVektor = position2.sub(position1);

        double skalarProd = sehVektor.skalarProd(position2);

       //skalarProdukt=0 bedeut ein Winkel von 90 grad
       //hier muessen wir eine Approximation benutzen, da double nicht exakt genau ist


       if(abs(skalarProd)<0.1)
    	{
        	break;
    	}

        schritt++;
    }


    std::cout<<"Sie koennen "<<sehVektor.laenge()<<" km weit sehen"<<std::endl;
    std::cout<<"Sie sind "<<heightOfPlatform.laenge() + heightOfPerson.laenge()<<" Meter hoch" <<std::endl;
    std::cout<<"Der Winkel betraegt "<<position1.winkel(position2)<<" Grad"<<std::endl;
    std::cout<<"Anzahl Schritte: "<<schritt<<std::endl;


    return 0;
}
