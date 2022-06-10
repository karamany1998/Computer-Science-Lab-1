//////////////////////////////////////////////////////////////////////////////
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
/**
Praktikum Informatik 1 MMXXII
 *
 * @file Vektor.cpp
 *Inhalt: Implementation of the different methods for the class Vektor
 *
 */


//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <cmath>
#include <math.h>       /* acos */
const double PI = atan(1)*4;

///@class class Vektor is a 3D vector class and has various methods

/**
 * @brief Constructor for a vector
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

/**
 * @brief Destructor for a vector
 */
Vektor::~Vektor()
{

}

/**
 * @brief Function that the components of the vector
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}


/**
 * @brief Funktion, die die Laenge eines Vektor bestimmt
 * @return laenge eines Vektor als double
 */
double Vektor::laenge() const
{

	double ans = (this->x)*(this->x) +  (this->y)*(this->y) +  (this->z)*(this->z);
	ans = sqrt(abs(ans));
	return ans;
}


/**
 * @brief Funktion, die zwei Vektor subtrahiert
 * @param input  -ein Vektor, der wir von einem anderen subtrahiert wird
 * @return ein Vektor
 */
Vektor Vektor::sub(const Vektor& input) const
{

	double xNew = this->x - input.x;
	double yNew = this->y - input.y;
	double zNew = this->z - input.z;

	Vektor vec(xNew,yNew, zNew);
	return vec;
}

/**
 * @brief Funktion, die das Skalarprodukt zweier vektoren berechnent
 * @param input  -ein Vektor
 * @return der Wert des Skalarprodukts als double
 */
double Vektor::skalarProd(const Vektor& input) const
{
	double xNew = this->x * input.x;
	double yNew = this->y * input.y;
	double zNew = this->z * input.z;

	double ans = xNew + yNew + zNew;
	return ans;


}


/**
 * @brief Funktion, die die Winkel zwischen zwei vektoren berechnent
 * wir benuzten den Mathematischen Formel : cos(winkel) = (skalarProdukt)/(laengeVektor1 * laengeVektor2))
 * @param input  ein Vektor
 * @return der Wert der Winkel als double und in Grad
 */
double Vektor::winkel(const Vektor& input) const
{

	double skalarProdukt = this->skalarProd(input);
	double laengeMult = this->laenge() * input.laenge();

	//cos(winkel) = (skalarProdukt)/(laengeVektor1 * laengeVektor2))
	//winkel = acos(skalarProdukt / laengeVektor1 * laengeVektor2)
	double ans = acos(skalarProdukt / laengeMult);
	ans = ans*(180/PI);
	return ans;
}


/**
 * @brief Funktion, die ein 3D Vektor um die z-Achse rotiert
 * wir benutzen hier eine Rotation-Matrix
 * @param rad, wie viel Radian den Vektor rotiert muss
 */
void Vektor::rotiereUmZ(const double rad)
{
	this->x = cos(rad)*(this->x) -sin(rad)*(this->y);
	this->y = sin(rad)*(this->x) + cos(rad)*(this->y);
	///this->z does not change

}





