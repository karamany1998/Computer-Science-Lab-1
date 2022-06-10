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

		if(wort[i]<'A' || wort[i]>'z') // falls nicht buchstabe, dann betrachte das Zeichen nicht
		{
			continue;
		}
		if((int)wort[i] >= 97){	//falls wort[i] eine kleine Buchstabe ist

			wort[i] = toupper(wort[i]);	//change to upper case

			wort[i] =tolower(schluessel[1][wort[i]-'A']);
			continue;
		}
		wort[i] = schluessel[1][wort[i]-'A'];
	}

	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	for(int i = 0 ; i<wort.length() ; i++)
	{
		if(wort[i]<'A' || wort[i]>'z') // falls nicht buchstabe, dann betrachte das Zeichen nicht
		{
					continue;
		}

		if((int)wort[i] >= 97){	//falls wort[i] eine kleine Buchstabe ist

			wort[i] = toupper(wort[i]);

			wort[i] = tolower(schluessel[1][wort[i]-'A']);
			continue;
		}

		wort[i] = schluessel[1][wort[i]-'A'];
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
 	getline(cin , word);
 	//cin>>word;

 	string encryptedWord = verschluesseln(lutVerschluesseln,word);
 	string decryptedWord = entschluesseln(lutEntschluesseln ,encryptedWord);

 	std::cout<<"The encrypted word is :"<<encryptedWord<<endl;

 	std::cout<<"The Decryped word is :"<<decryptedWord<<endl;



	return 0;
}
