/*!
 * Praktikum Informatik 1 MMXXII
 *
 * @file Person.cpp
 */
 
#include "Person.h"

/**
 *
 * @param initName - name of person
 * @param initGeburtsdatum - date of birth of person
 */
Person::Person(std::string initName, Datum initGeburtsdatum)
: name(initName)
, geburtsdatum(initGeburtsdatum)
{
}

// Destruktor
Person::~Person()
{
}

/**
 * @brief getter function for geGeburtsdatum
 * @return Datum - data of birth of Person
 */
Datum Person::getGeburtsdatum() const
{
    return geburtsdatum;
}

/**
 * @brief getter function to return name of person
 * @return string - name of person
 */
std::string Person::getName() const
{
    return name;
}
