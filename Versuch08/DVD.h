/*
 * DVD.h
 *
 *  Created on: 10 Jun 2022
 *      Author: mkara
 */

#ifndef DVD_H_
#define DVD_H_


#include "Medium.h"


class DVD : public Medium
{


private:
	int alterFreigabe;
	std::string genre;



public:

	/**
	 *
	 * @param initTitel - the title of the book
	 * @param initAltersfreigabe - determines how old the user has to be to borrow DVD
	 * @param initGenre	- genre of the dvd
	 */
	DVD(std::string initTitel , int initAltersfreigabe , std::string initGenre);
	virtual void ausgabe(std::ostream& out) const;


	/**
	 *
	 * @param person - class Person who will borrow DVD
	 * @param ausleihdatum - date
	 * @return bool - true if borrowing is successful, false otherwise
	 */
	virtual bool ausleihen(Person person, Datum ausleihdatum);


};



#endif /* DVD_H_ */
