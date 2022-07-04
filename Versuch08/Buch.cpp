/*
 * Buch.cpp
 *
 * Created on:10/06/2022
 *      Author: Mohamed Elkaramany
 */
#include <string>
#include "Buch.h"
#include "Medium.h"


/**
 * @brief constructor for class Buch

 */
Buch::Buch(std::string initTitel , std::string initAutor) : Medium(initTitel),  autor( initAutor)
{



}

/**
 * @print allows us to print the book
 *
 * @param out the output stream
 */
void Buch::ausgabe(std::ostream& out) const
{

	Medium::ausgabe(out);
	out<< "Autor: "<<this->autor<<std::endl;


}

/**
 *
 * @param person - the object of class person determines who will borrow the book
 * @param ausleihdatum - the date of borrowing
 * @return bool - returns true if a specific criteria for borrowing is met and false otherwise
 */
bool Buch::ausleihen(Person person , Datum ausleihdatum)
{

	return Medium::ausleihen(person, ausleihdatum);

}


Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}

