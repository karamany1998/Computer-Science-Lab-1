/** @mainpage
 *
 * Praktikum Informatik 1 SS2022
 * Versuch 6: Standard Template Library
 *Code written by Mohamed Elkaramany(423765)
 */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Student.h"
#include <vector>

using namespace std;


ostream& operator<<(ostream& out , Student& student1)
{

	student1.ausgabe(out);
	return out;
}

int main()
{
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;
    /*

    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
        studentenListe.push_back(student);
    }
	*/


    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  <<"(4) Datenbank in umgekehrter Reihenfolge ausgeben "<<std::endl
				  <<"(5) Datenelement löschen "<<std::endl
				  <<"(6) Datenelement vorne hinzufügen" << std::endl
				  <<"(7) Daten aus einer Datei einlesen " <<std::endl
				  <<"(8) Daten in eine Datei sichern" << std::endl
				  <<"(9) Sortiere die StudentenListe" <<std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);	//add student to back of vector
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())	//if the list is not empty
                    {
                        student = studentenListe.at(0);	//student at first index
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        //student.ausgabe();
                        cout << student;
                        studentenListe.erase(studentenListe.begin());	//use STL to erase the student
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    //studentenListe.ausgabeVorwaerts();

                    vector<Student>::iterator it;
                    for(it = studentenListe.begin() ; it != studentenListe.end() ; it++)
                    {
                    	//it->ausgabe();
                    	cout << *it;

                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

               //Datenbank in umgekehrter Reihenfolge ausgeben
            case '4':
            	if(!studentenListe.empty())
            	{
            		std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
            		//studentenListe.ausgabeRuckwaerts();

            		vector<Student>::reverse_iterator revIt;
            		for(revIt = studentenListe.rbegin() ; revIt != studentenListe.rend() ; revIt++)
            		{
            			//revIt->ausgabe();
            			cout << *revIt;

            		}


            	}
            	else
            	{

            		std::cout << "Die Liste ist leer!\n\n";
            	}
            	break;

            //student mit bestimmten matrikelnummer von dem System loeschen
            case '5':

            	{

            		unsigned int matNum;
            		std::cout<<"Bitte geben Sie eine Matrikelnummer, um die StudentenInformation zu loeschen"<<std::endl;
            		std::cin>>matNum;
            		Student cmp = Student(matNum , "" , "" , "");

            		if(!studentenListe.empty())
            		{

            			//ListenElement* searchedStudent = studentenListe.loescheStudent(matNum);
            			vector<Student>::iterator it= std::find(studentenListe.begin() , studentenListe.end() , cmp);

            			if(it != studentenListe.end() ) // student found
            			{

            				std::cout<<"The following student will be deleted from the system : "<<std::endl;
            				std::cout << *it << std::endl;

            				studentenListe.erase(it);

            				std::cout<<"The Student Database after deletion..."<<std::endl;
            				for(auto student : studentenListe)
            				{
            					std::cout<<student;
            				}

            			}
            			else
            			{
            				std::cout << "Student not found! "<<std::endl;
            			}




            		 }
            		 else
            		 {

            			std::cout<<"die Liste ist leere. Es kann kein Studenten geloescht werden"<<std::endl;

            		 }

            	}
            	break;

            //student am Anfang der Liste hinzufuegen
            case '6':
            {
            	unsigned int matNr = 0;
            	std::string name = "";
            	std::string geburtstag = "";
            	std::string adresse = "";

            	std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
            	getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

            	std::cout << "Geburtsdatum: ";
            	getline(std::cin, geburtstag);

            	std::cout << "Adresse: ";
            	getline(std::cin, adresse);

            	std::cout << "Matrikelnummer: ";
            	std::cin >> matNr;
            	std::cin.ignore(10, '\n');

            	student = Student(matNr, name, geburtstag, adresse);

            	studentenListe.insert(studentenListe.begin() , student);

            }
            break;

            //(7) Daten aus einer Datei einlesen
            case '7':
            {

            	ifstream input;
            	input.open("studenten.txt");

            	int matNum;
            	input>>matNum;
            	while(!input.eof()) //as long as we can read from input file
            	{


            		//read student information from studenten.txt

            		input.ignore (1, '\n');

            		string name;
            		getline(input , name);

            		string birthday;
            		getline(input , birthday);

            		string address;
            		getline(input, address);


            		//add student from file to vector
            		studentenListe.push_back(Student(matNum, name, birthday, address));

            		input>>matNum;

            	}





            }
            break;

            //(8) Daten in eine Datei sichern
            case '8':
            {

            	cout<<"Where do you want to save the information?"<<endl;
            	string fileName;
            	cin>>fileName;

            	ofstream output;
            	output.open(fileName , ios::out);

            	for(auto student : studentenListe)
            	{

            		output<<student.getMatNr()<<endl;
            		output<<student.getName()<<endl;
            		output<<student.getGeburtstag()<<endl;
            		output<<student.getAdresse()<<endl;

            	}



            }
            break;


            //(9) Sortiere die StudentenListe
            case '9':
            {
            	/*
            	sort takes two iterators and sorts based on the < operator, so the students will be sorted
            	according to their matrikelnummer
            	*/

            	std::sort(studentenListe.begin() , studentenListe.end());

            }
            break;
            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
