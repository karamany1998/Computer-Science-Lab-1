//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
// Written by: Mohamed Elkaramany- SS2022 - 423765
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    int iErste = 0;
    int iZweite = 0;

    std::cout << "Bitte Geben Sie ein Zahl iErste ein:"<<std::endl;
    std::cin>>iErste;

    std::cout <<"Bitte Geben Sie ein Zahl iZweite ein:"<<std::endl;
    std::cin>>iZweite;

    int iSumme = iErste + iZweite;
    int iQuotient = iErste/iZweite;

    std::cout<<"Die Summe von iErste und iZweite ist: "<<iSumme<<std::endl;
    std::cout<<"Die Quotient von iErste und iZweite ist: "<<iQuotient<<std::endl;

    double dSumme = iErste + iZweite;
    double dQuotient = iErste/iZweite;

    std::cout<<"dSumme: "<<iSumme<<std::endl;
    std::cout<<"dQuotient: "<<iQuotient<<std::endl;


    double dSummeCast = (double)iErste + (double)iZweite;
    double dQuotientCast = (double)iErste/ (double)iZweite;

    std::cout<<"Summe mit explizit Cast ist : "<<dSummeCast<<std::endl;
    std::cout<<"Quotient mit explizit Cast ist : "<<dQuotientCast<<std::endl;


    /*
     * Es gibt ein Underschied zB bei iErste=5 und iZweite=2 in dQuotient und dQuotientCase
     * und es liegt darin, dass bei kein Cast die Zahl iErste/iZweite ein Int wird(also 2.5 wird 2) und dann wird
     * zu dQuotient zugewiesen.
     * bei dQuotientCast haben wir eine double/double und das ergibt auch ein double als dQuotientCast=2.5
     */



    std::string sVorname;
    std::string sNachname;

    std::cout<<"Bitte Geben Sie Ihren Vorname ein :";
    std::cin>>sVorname;
    std::cout<<std::endl;

    std::cout<<"Bitte Geben Sie Ihren Nachname ein :";
    std::cin>>sNachname;
    std::cout<<std::endl;

    std::string sVornameName = sVorname + " " + sNachname;
    std::string sNameVorname = sNachname+", "+sVorname;

    std::cout<<"Die Form Vorname Nachname: "<<sVornameName<<std::endl;
    std::cout<<"Die Form Nachname, Vorname: "<<sNameVorname<<std::endl;



    {

    	int iFeld[2] = {1,2};
    	std::cout<<"Das feld[2] besteht aus "<<iFeld[0]<<" "<<iFeld[1]<<std::endl;

    	int spielfeld[2][3] = { {1,2,3} , {4,5,6} };

    	std::cout<<"Das spielfeld besteht aus \n"<<"Erste Zeile: "<<spielfeld[0][0]<<" "<<spielfeld[0][1]<<" "<<spielfeld[0][2]<<std::endl;
    	std::cout<<"Zweite Zeile : "<<spielfeld[1][0]<<" "<<spielfeld[1][1]<<" "<<spielfeld[1][2]<<std::endl;


    	int iZweite = 1;
    	std::cout<<"iZweite ist :";
    	std::cout<<iZweite<<std::endl;

    }


    std::cout<<"iZweite ist :";
    std::cout<<iZweite<<std::endl;


    int iName1 = sVorname[0];
    int iName2 = sVorname[1];

    std::cout<<"Die erste und zweite Buchstaben sind als ASCII-Zahlen: "<<iName1<<" "<<iName2<<std::endl;

    //use %32 to get consider lower and uppercase letters in one line
    int pos1 = (iName1)%32;
    int pos2 = (iName2)%32;
    std::cout<<pos1 << " "<<pos2<<std::endl;


    /*
    if(iName1>=97){

    	std::cout<<"Die Position des ersten Buchstabe ist: "<<iName1%97<<std::endl;
    }
    else{

    	std::cout<<"Die Position des ersten Buchstabe ist: "<<iName1%65<<std::endl;
    }

    if(iName2 >=97){
    	std::cout<<"Die Position des zweiten Buchstabe ist: "<<iName2%97<<std::endl;

    }
    else{

    	std::cout<<"Die Position des zweiten Buchstabe ist: "<<iName2%65<<std::endl;
    }
    */
    return 0;

}
