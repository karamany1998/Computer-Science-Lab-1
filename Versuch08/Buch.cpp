/*
 * Buch.cpp
 *
 * Created on:10/06/2022
 *      Author: Mohamed Elkaramany
 */
#include <string>
#include "Buch.h"
#include "Medium.h"

Buch::Buch(std::string initTitel , std::string initAutor) : Medium(initTitel),  autor( initAutor)
{



}


void Buch::ausgabe(std::ostream& out) const
{

	Medium::ausgabe(out);
	out<< "Autor: "<<this->autor<<std::endl;


}

bool Buch::ausleihen(Person person , Datum ausleihdatum)
{

	return Medium::ausleihen(person, ausleihdatum);

}


Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}

