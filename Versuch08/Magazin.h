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

	Magazin(std::string initTitel, Datum initDatumAusgabe , std::string initSparte);

	virtual void ausgabe(std::ostream& out) const;

	virtual bool ausleihen(Person person, Datum ausleihdatum);



};



#endif /* MAGAZIN_H_ */
