/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


struct Person{

	std::string sNachname;
	std::string sVorname;
	int iGeburtsjahr;
	int iAlter;

};
int main()
{



	Person nBenutzer;

	std::cout<<"Bitte Geben Sie ihren Vorname ein: ";
	std::cin>>nBenutzer.sVorname;
	std::cout<<std::endl;

	std::cout<<"Bitte Geben Sie ihren Nachname ein: ";
	std::cin>>nBenutzer.sNachname;
	std::cout<<std::endl;


	std::cout<<"Bitte Geben Sie ihren Geburtsjahr ein: ";
	std::cin>>nBenutzer.iGeburtsjahr;
	std::cout<<std::endl;


	std::cout<<"Bitte Geben Sie ihren Alter ein: ";
	std::cin>>nBenutzer.iAlter;
	std::cout<<std::endl;



	std::cout<<"Der Benutzer hat die folgende Dateien eingegeben:"<<std::endl;
	std::cout<<"Vorname :"<<nBenutzer.sVorname<<std::endl;
	std::cout<<"Nachname :"<<nBenutzer.sNachname<<std::endl;
	std::cout<<"Geburtsjahr :"<<nBenutzer.iGeburtsjahr<<std::endl;
	std::cout<<"Alter :"<<nBenutzer.iAlter<<std::endl;

	std::cout<<"-----------------------------------------------------------------"<<std::endl;

	Person nKopieEinzeln;
	Person nKopieGesamt = nBenutzer;

	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;


	std::cout<<"nKopieEinzeln hat die folgende Dateien eingegeben:"<<std::endl;
	std::cout<<"Vorname :"<<nKopieEinzeln.sVorname<<std::endl;
	std::cout<<"Nachname :"<<nKopieEinzeln.sNachname<<std::endl;
	std::cout<<"Geburtsjahr :"<<nKopieEinzeln.iGeburtsjahr<<std::endl;
	std::cout<<"Alter :"<<nKopieEinzeln.iAlter<<std::endl;

	std::cout<<"-----------------------------------------------------------------"<<std::endl;

	std::cout<<"nKopieGesamt hat die folgende Dateien eingegeben:"<<std::endl;
	std::cout<<"Vorname :"<<nKopieGesamt.sVorname<<std::endl;
	std::cout<<"Nachname :"<<nKopieGesamt.sNachname<<std::endl;
	std::cout<<"Geburtsjahr :"<<nKopieGesamt.iGeburtsjahr<<std::endl;
	std::cout<<"Alter :"<<nKopieGesamt.iAlter<<std::endl;
    return 0;

}
