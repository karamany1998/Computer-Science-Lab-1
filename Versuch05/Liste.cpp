//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 SS2022
//Code written by Mohamed Elkaramany(423765)

//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr , nullptr);

    if (front == nullptr)            // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	//put pData at the end
        back->setNext(neuesElement);

        neuesElement->setPrev(back);
        //neuesElement is now the last element
        back = neuesElement;

    }
}



/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr , nullptr);

    if (front == nullptr)          // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	//put neuesElement at the beginning of the list
    	neuesElement->setNext(front);
    	front->setPrev(neuesElement);
        front = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enthält nur ein Listenelement
    {
        delete front;                                        // Listenelement löschen
        front = nullptr;	///make sure that front and back are pointing to nullptr
        back = nullptr;
    }
    else
    {
    	//let front point to second element in the list
        front = front->getNext();

        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
	//cursor ist ein Zeiger auf das erste Element
    ListenElement* cursor = front;

    //as long as cursor is not null(i.e. there are still elements in the list), then stay in the loop
    while (cursor != nullptr)
    {
    	//print out the information of the current student
    	cursor->getData().ausgabe();
    	//go to next element in the list
        cursor = cursor->getNext();
    }
}


/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRuckwaerts() const
{
	//cursor ist ein Zeiger auf das letzte Element
    ListenElement* cursor = back;

    //as long as cursor is not null(i.e. there are still elements in the list), then stay in the loop
    while (cursor != nullptr)
    {
    	//print out the information of the current student
    	cursor->getData().ausgabe();
    	//go to previous element in the list
        cursor = cursor->getPrev();
    }
}



/**
 * @brief suche einen Student mit Matrikelnummer matNum und loscht ihn, prev und next Elementen werden auch behandelt
 *@param matNum - the matriculation number of the student that would get deleted
 * @return zeiger auf listenElement mit diesem Nummer
 */
ListenElement* Liste::loescheStudent(unsigned int matNum)
{

	ListenElement* currElement = front;

	//as long as there are elements left
	while(currElement != nullptr)
	{
		//student found-->make sure to handle the edge cases
		if(currElement->getData().getMatNr() == matNum)
		{

			//Liste hat nur ein Element
			if(currElement->getNext() == nullptr && currElement->getPrev() == nullptr)
			{
				//make sure that front and back point to null
				front = nullptr;
				back = nullptr;

				return currElement;
			}

			///if last element
			if(currElement->getNext() == nullptr)
			{
				back = currElement->getPrev();
				back->setNext(nullptr);
				return currElement;
			}

			///if first element
			if(currElement->getPrev() == nullptr)
			{
				front = currElement->getNext();
				front->setPrev(nullptr);
				return currElement;
			}

			//non-edge cases(student in the middle of list)
			currElement->getPrev()->setNext(currElement->getNext());
			currElement->getNext()->setPrev(currElement->getPrev());


			return currElement;
		}
		currElement = currElement->getNext();
	}

	//wenn student nicht gefunden, dann gibt einen nullptr zurueck
	return nullptr;
}
