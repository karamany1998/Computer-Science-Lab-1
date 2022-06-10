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

class Buch : public Medium
{

private:
	std::string autor;


public:
	Buch(std::string initTitel , std::string initAutor);

	virtual bool ausleihen(Person person, Datum ausleihdatum);
	virtual void ausgabe(std::ostream& out) const;
	virtual ~Buch();


};

#endif /* BUCH_H_ */
