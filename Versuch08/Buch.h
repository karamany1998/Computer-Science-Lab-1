/*
 * Buch.h
 *
 *  Created on:10/06/2022
 *      Author: Mohamed Elkaramany
 */
#include <string>
#include "Medium.h"
#ifndef BUCH_H_
#define BUCH_H_


/**
 * @class Buch
 * contains the private variables of the class Buch and definitions for the class methods
 */
class Buch : public Medium
{

private:
	std::string autor;


public:
	/**
	 * @brief constructor for class Buch

	 */
	Buch(std::string initTitel , std::string initAutor);

	/**
	 *
	 * @param person - the object of class person determines who will borrow the book
	 * @param ausleihdatum - the date of borrowing
	 * @return bool - returns true if a specific criteria for borrowing is met and false otherwise
	 */
	virtual bool ausleihen(Person person, Datum ausleihdatum);



	/**
	 * @print allows us to print the book
	 *
	 * @param out the output stream
	 */
	virtual void ausgabe(std::ostream& out) const;

	/**
	 * @brief - destructor for class Buch
	 */
	virtual ~Buch();


};

#endif /* BUCH_H_ */
