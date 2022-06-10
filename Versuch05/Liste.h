//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII

//Code written by Mohamed Elkaramany(423765)
/**

 *
 * @file Liste.h
 *Inhalt: Headerdatei der Klasse Liste
 * Beinhaltet die Klasse Liste und die Definitionen ihrer Methoden
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

/**
 * @class Liste
 *
 * 	class Liste is a doubly-linked list with private elements front and back which contain a pointer to the first and last element
 * 	respectively
 * 	it also has different methods that you could apply to the list
 */
class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung
    void pushBack(Student pData);
    void pushFront(Student pData);
    void popFront();
    bool empty();
    Student dataFront();
    void ausgabeVorwaerts() const;
    void ausgabeRuckwaerts() const;

    ListenElement* loescheStudent(unsigned int matNum);
};

#endif /*LISTE_H_*/
