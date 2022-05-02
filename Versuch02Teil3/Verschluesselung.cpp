///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXI
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	for(int i = 0 ; i<wort.length() ; i++)
	{
		char encryptedLetter;
		if((int)wort[i] >= 97){	//falls wort[i] eine kleine Buchstabe ist

			wort[i] = toupper(wort[i]);
			encryptedLetter = tolower(schluessel[1][wort[i]-'A']);
			wort[i] = encryptedLetter;
			continue;
		}
	   encryptedLetter = schluessel[1][wort[i]-'A'];
		wort[i] = encryptedLetter;
	}

	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	for(int i = 0 ; i<wort.length() ; i++)
	{
		char decryptedLetter;
		if((int)wort[i] >= 97){	//falls wort[i] eine kleine Buchstabe ist

			wort[i] = toupper(wort[i]);
			decryptedLetter = tolower(schluessel[1][wort[i]-'A']);
			wort[i] = decryptedLetter;
			continue;
		}
	   decryptedLetter = schluessel[1][wort[i]-'A'];
		wort[i] = decryptedLetter;
	}
	return wort;
}

int main()
{
	char lutVerschluesseln[2][26] = { {'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' ,'Z'} ,
									  {'N' , 'J' , 'F' , 'A' , 'Z' , 'H' , 'C' , 'P' , 'L' , 'D' , 'R' , 'U' , 'W' , 'Y' , 'E' , 'B' , 'S' , 'G' , 'Q' , 'T' , 'I' , 'O' , 'M' , 'K' , 'V' , 'X'}};


	char lutEntschluesseln[2][26] = { {'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' ,'Z'} ,
									  {'D' , 'P' , 'G' , 'J' , 'O' , 'C' , 'R' , 'F' , 'U'  , 'B' , 'X' ,'I',  'W' , 'A' , 'V' , 'H' , 'S' , 'K' , 'Q' , 'T' , 'L' , 'Y' , 'M' , 'Z' , 'N' , 'E'}
	};

 	string word;
 	cout<<"Bitte Geben Sie ein Wort ein, um es zu entschluessen"<<std::endl;
 	cin>>word;

 	string encryptedWord = verschluesseln(lutVerschluesseln,word);
 	string decryptedWord = entschluesseln(lutEntschluesseln ,encryptedWord);

 	cout<<word<<endl;
 	cout<<encryptedWord<<endl;
 	cout<<decryptedWord<<endl;



	return 0;
}
