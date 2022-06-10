/*
 * DVD.cpp
 *
 *  Created on: 10 Jun 2022
 *      Author: mkara
 */


#include "DVD.h"



DVD::DVD(std::string initTitel , int initAltersfreigabe , std::string initGenre) : Medium(initTitel), alterFreigabe(initAltersfreigabe) , genre(initGenre)
{


}



void DVD::ausgabe(std::ostream& out) const
{

	Medium::ausgabe(out);
	out<<"FSK: ab "<<alterFreigabe<<" Jahre"<<std::endl;
	out<<"Genre: "<<genre<<std::endl;

}


bool DVD::ausleihen(Person person, Datum ausleihdatum)
{

	//difference between ausleihdatum and person.getGeburtsdatum is how old person is in months
	int ageMonths = ausleihdatum - person.getGeburtsdatum();

	//to get age in years just divide by 12
	int ageYears = ageMonths/12;


	if(ageYears >= this->alterFreigabe) //
	{

		Medium::ausleihen(person, ausleihdatum);//person could borrow DVD
		return true;
	}
	else
	{

		std::cout<<person.getName()<<" cannot borrow the DVD because he/she is younger than "<<this->alterFreigabe<<" years"<<std::endl;
		return false;
	}

}
