/*
 * Magazin.h
 *
 *  Created on: 10 Jun 2022
 *      Author: mkara
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"
#include "Datum.h"
#include <string>

class Magazin : public Medium
{

private:

	Datum date;
	std::string sparte;



public:

	/**
	 *
	 * @param initTitel - string that determines the title of the magazine
	 * @param initDatumAusgabe - when the magazine was publish
	 * @param initSparte -
	 */
	Magazin(std::string initTitel, Datum initDatumAusgabe , std::string initSparte);

	/**
	 *
	 * @param out - type ostream& and this is used to print out the magazine
	 */
	virtual void ausgabe(std::ostream& out) const;

	/**
	 *
	 * @param person - who will borrow the magazine
	 * @param ausleihdatum - date of borrowing
	 * @return bool - true if borrowing successful and false otherwise
	 */
	virtual bool ausleihen(Person person, Datum ausleihdatum);



};



#endif /* MAGAZIN_H_ */
