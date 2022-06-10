
/**
 *@file Student.h
 *contains the private variables of the class Student and class methods
 *
 *
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>



/**
 * @class Student
 * contains the private variables of the class student and definitions for the class methods
 */

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe(std::ostream& out) const;

    bool operator<(const Student& student) ;
    bool operator==( const Student & student );
    bool operator>(const Student& student) ;
private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

#endif
