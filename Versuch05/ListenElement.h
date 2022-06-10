
/**@class ListenElement - a node in a list
 * 		  has 3 membervariables. Data(a Student), a pointer to next element and a pointer to previous element
 *
 */


#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"



class ListenElement
{
private:
    Student data;
    ListenElement* next;
    ListenElement* prev;

public:
    ListenElement(Student pData, ListenElement* pNext , ListenElement* pPrev);

    void setData(Student pData);
    void setNext(ListenElement* pNext);
    void setPrev(ListenElement* pPrev);

    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrev() const;
};

#endif
