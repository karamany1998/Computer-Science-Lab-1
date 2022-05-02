/*
 * Variablen.cpp
 *
 *  Created on: 10 May 2021
 *      Author: mkara
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXI
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int iErste = 0;
    int iZweite = 0;

    // Hier folgt Ihr eigener Code

    int iSumme = 0 ;
    int iQuotient = 0 ;

    std::cout <<"Geben Sie zwei ganze Zahlen ein!" << std::endl;

    std::cout<<"Erste Zahl : ";
    std::cin>>iErste;
    std::cout<<std::endl;

    std::cout<<"Zweite Zahl :";
    std::cin>>iZweite;
    std::cout<<std::endl;

    iSumme = iErste + iZweite;
    iQuotient = iErste/iZweite;


    std::cout << "Die Summe der beiden eingegebenen Zahlen ist: "<< iSumme << std::endl;
    std::cout << "Die iQuotient der beiden eingegebenen Zahlen ist: "<<iQuotient <<std::endl;



    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite;

    std::cout << "Die Summe der beiden eingegebenen Zahlen ist: "<< dSumme << std::endl;
    std::cout << "Die iQuotient der beiden eingegebenen Zahlen ist: "<<dQuotient <<std::endl;


    double dSummeCast = (double)iErste + (double)iZweite;
    double dQuotientCast = (double)iErste / (double)iZweite;

    std::cout<<" Die Summe der gecastet eingegebenen Zahlen ist: "<<dSummeCast << std::endl;
    std::cout<<" Die Quotient der gecastet eingegebenen Zahlen ist: "<<dQuotientCast<<std::endl;


  std::cout <<"Geben Sie Ihre Vornamen  ein"<<std::endl;

  std::string sVorname;
  std::cin>>sVorname;

  std::cout <<"Geben Sie Ihre Nachnamen ein" <<std::endl;

  std::string sNachname;
  std::cin>>sNachname;

  std::string sVornameName = sVorname + " "+sNachname;
  std::string sNameVorname = sNachname+", "+sVorname;

  std::cout << " Vorname Nachname "<<sVornameName<<std::endl;
  std::cout<< " Name, Vorname "<<sNameVorname<<std::endl;



  std::cout<<endl;
  //Unterpunkt a
  {

   int iFeld[2] = { 1, 2};

   std::cout<<"Die Elemente der Feld iFeld sind "<<iFeld[0]<<" "<<iFeld[1]<<std::endl;
  }


  //Unterpunkt b
  {
	  int spieldFeld[2][3] = {{1,2,3} , {4,5,6}};
	  cout<<"Die Elemente des Feldes spielfeld sind :"<<std::endl;
	  std::cout<<spieldFeld[0][0]<<" "<<spieldFeld[0][1]<<" "<<spieldFeld[0][2]<<std::endl;
	  std::cout<<spieldFeld[1][0]<<" "<<spieldFeld[1][1]<<" "<<spieldFeld[1][2]<<std::endl;
   }

  //Unterpunkt c
  {
	 const int iZweite = 1 ;
	 std::cout<<"Der Wert der Konstante iZweite ist: "<<iZweite<<std::endl;
  }

  std::cout<<"Jetzt sind wir ausserhalb die Bloecke"<<std::endl;
  std::cout<<"iZweite ist die Zahl : ";
  std::cout<<iZweite<<std::endl;

  int iName1 = sVorname[0];
  int iName2 = sVorname[1];

  std::cout<<"Der erste Buchstabe der Vorname entricht in ASCII die Zahl: "<<iName1<<std::endl;
  std::cout<<"Der zweite Buchstabe der Vorname entricht in ASCII die Zahl: "<<iName2<<std::endl;


  int pos1 = iName1%32;
  int pos2 = iName2%32;

  std::cout<<pos1<<std::endl;
  std::cout<<pos2<<std::endl;




    return 0;

}





