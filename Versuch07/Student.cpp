//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"



/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 */
void Student::ausgabe(std::ostream& out) const
{
    out << name << ", MatNr. " << matNr << ", geb. am "
              << geburtstag << ", wohnhaft in " << adresse
              << std::endl;
}


/**
 * @brief overloaded < operator for class Student
 *
 * @return bool
 */
bool Student::operator<(const Student& student)
{

	if(this->matNr < student.getMatNr())
	{
		return true;
	}
	return false;
}



/**
 * @brief overloaded > operator for class Student
 *
 * @return bool
 */
bool Student::operator>(const Student& student)
{

	if(this->matNr > student.getMatNr())
	{
		return true;
	}
	return false;
}



/**
 * @brief overloaded == operator for class Student
 *
 * @return bool
 */

bool Student::operator==( const Student & student )
{
		if ( this->matNr == student.matNr)
			return true ;
		else
			return false ;
}
