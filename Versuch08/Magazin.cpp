/*
 * Magazin.cpp
 *
 *  Created on: 10 Jun 2022
 *      Author: mkara
 */



#include "Magazin.h"




Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe , std::string initSparte): Medium(titel), date(initDatumAusgabe) , sparte(initSparte)
{



}


void Magazin::ausgabe(std::ostream& out) const
{

	Medium::ausgabe(out);
	out<<"Ausgabe: "<<date<<std::endl;
	out<<"Sparte: "<<sparte<<std::endl;
}



bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{

	//check first if the magazine medium is not borrowed before
	bool st = Medium::ausleihen(person, ausleihdatum);
	if(!st)return false;	//if borrowed before, then return false


	//if the magazine got published within a month(new edition), then cannot borrow
	if(ausleihdatum - this->date <= 1)
	{
		std::cout<<"This magazine is the new edition and cannot be borrowed"<<std::endl;
		return false;
	}

	Medium::ausleihen( person, ausleihdatum); //person would borrow the magazine starting from ausleihdatum
	return true;

}
