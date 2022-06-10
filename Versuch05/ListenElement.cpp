
/**
 * @file ListenElement.cpp
 * @brief contains implementations of the methods of the class ListenElement
 */



#include "ListenElement.h"

/**
 * @brief Konstruktor, der ein neues Listenelemente mit allen Werten erstellt
 *
 * @param pData Ein Objekt der Klasse Student
 * @param pNext Zeiger auf das naechste Listenelement
 */
ListenElement::ListenElement(Student pData, ListenElement* pNext , ListenElement* pPrev):
    data(pData), next(pNext) , prev(pPrev)
{
}

/**
 * @brief Fuegt ein Objekt der Klasse Student ein
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void ListenElement::setData(Student pData)
{
    data = pData;
}

/**
 * @brief weise next auf pNext zu
 *
 * @param pNext Zeiger auf das naechste Listenelement
 */
void ListenElement::setNext(ListenElement* pNext)
{
    next = pNext;
}

/**
 * @brief weise prev auf pNext zu
 * @param pPrev Zeiger auf das naechste Listenelement
 */
void ListenElement::setPrev(ListenElement* pPrev)
{

	prev = pPrev;

}

/**
 * @brief Gibt ein Objekt der Klasse Student zurueck
 *
 * @return  ein Objekt der Klasse Student
 */
Student ListenElement::getData() const
{
    return data;
}

/**
 * @brief Gibt einen Zeiger auf das naechste Listenelement zurueck
 *
 * @return Zeiger auf das naechste Listenelement
 */
ListenElement* ListenElement::getNext() const
{
    return next;
}



/**
 * @brief Gibt einen Zeiger auf das vorherige Listenelement zurueck
 *
 * @return Zeiger auf das vorherige Listenelement
 */
ListenElement* ListenElement::getPrev() const
{
    return prev;
}
