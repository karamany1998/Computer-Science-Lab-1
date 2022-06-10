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


	DVD(std::string initTitel , int initAltersfreigabe , std::string initGenre);
	virtual void ausgabe(std::ostream& out) const;

	virtual bool ausleihen(Person person, Datum ausleihdatum);


};



#endif /* DVD_H_ */
