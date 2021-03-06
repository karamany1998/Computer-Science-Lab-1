/**
 * Praktikum Informatik 1 MMXXII
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
    // Hier erfolgt jetzt Ihre Implementierung ...


	//falls stein ausserhalb des Feldes return false, sonst return true
	if(posX>= GROESSE_X || posY>=GROESSE_Y || posX<0 || posY<0)
	{
		return false;
	}
    return true;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return  boolean
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1
    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
        	if(i==0 && j==0)continue;  //wenn no moves could be made skip this iteration and go to next
        	int newSpalte = posX + i;
        	int newZeile = posY + j;

        	if(!aufSpielfeld(newSpalte , newZeile))continue;	//skip if we are not on the board

        	//falls einen benachbarten gegner gibt, dann untersucht diese Richtung bis einen eignen Stein gefunden wird
        	if(spielfeld[newZeile][newSpalte] == gegner)
        	{
        		newSpalte+=i;
        		newZeile+=j;
        		while(aufSpielfeld(newSpalte , newZeile))
        		{
        			if(spielfeld[newZeile][newSpalte] == aktuellerSpieler)
        			{
        				return true;
        			}
        			if(spielfeld[newZeile][newSpalte] == 0)	///falls leeres feld gefunden, dann versuch eine neue Richtung
        			{
        				break;
        			}
        			newSpalte+=i;
        			newZeile+=j;

        		}
        	}

        }
    }
    return false;	//wenn alle Richtungen untersucht werden und keinen eignen Stein gefunden, dann return false
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 *	this function would go in all directions(horizontal, vertical and diagonal) and would check if there are opposing disks between
 *	the current players disks, if yes, then it would change all the opposing disks to the same color as the current player disks.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 * @return void
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;
    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
     for (int j = -1; j <= 1; j++)
     {
    	 for (int i = -1; i <= 1; i++)
         {
    		 if(i==0 && j==0)continue;
             int newSpalte = posX + i;
             int newZeile = posY + j;
             if(!aufSpielfeld(newSpalte , newZeile))continue;	//skip if we are not on the board

             //falls einen benachbarten gegner gibt, dann untersucht diese Richtung bis einen eignen Stein gefunden wird
             if(spielfeld[newZeile][newSpalte] == gegner)
             {
            	newSpalte+=i;
            	newZeile+=j;
            	//solange Stein sich auf Spielfeld befindet
            	while(aufSpielfeld(newSpalte , newZeile))
            	{
            		//ueberpruefe, ob jetzt einen eignen Stein gefunden
            	    if(spielfeld[newZeile][newSpalte] == aktuellerSpieler)
            		{
            		 //falls ja, dann aendern alle gegner Steine, bis Start stein erreicht
            		 while(newSpalte != posX || newZeile!=posY)
            		 {
            			 //geh zurueck in die selbe Richtung und aendert die gegnerische Steine in eigene Steine
            			spielfeld[newZeile][newSpalte] = aktuellerSpieler;
            			newSpalte-=i;//gehe zuruck in x und y Richtungen
            			newZeile-=j;
            		 }
            		 spielfeld[posY][posX] = aktuellerSpieler;
            		 break;

            		}
            		if(spielfeld[newZeile][newSpalte] == 0)	///falls leeres feld gefunden, dann versuch eine neue Richtung
            		{
            			break;
            		}

            		//keep moving in this direction
            		newSpalte+=i;
            		newZeile+=j;
            	 }
              }
         	}
     }
}


/**
 * @brief Function that counts possible plays
 *
 * this function would go over all elements in the board and check if a possible play could be made at that position
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return number of plays that the current player can make
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
	///counter for plays
	int numZug = 0 ;
    for(int i = 0 ; i<GROESSE_Y ; i++)
    {
    	for(int j = 0 ; j<GROESSE_X ; j++)
    	{
    		///if play could be made, increment by 1
    		if(zugGueltig(spielfeld , aktuellerSpieler , j, i))
    		{
    			numZug++;
    		}
    	}
    }
    
    return numZug;
}


/**
 * @brief a function that manages a play for a human player
 *
 *
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return boolean
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX = 0 ;
    int posY = 0 ;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}


/*!
 * @brief Function that manages the game between the two players whether Human or Computer
 *
*@param spielerTyp[2] - Array, das Typ von Spielern bestimmt(Mensch oder Computer)
*@return void
*/
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);
    int Runde = 1;
    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);


    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    while(moeglicheZuege(spielfeld , 3-aktuellerSpieler)>0 || moeglicheZuege(spielfeld , aktuellerSpieler)>0)
    {



    	//fuehre menschlicherZug() nur wenn, aktuellerSpieler einen Zug machen kann
    	// moeglicheZuege(spielfeld, aktuellerSpieler) ==0 -> keine Ausfuehurng fuer aktuellerSpieller
    	if(moeglicheZuege(spielfeld , aktuellerSpieler))
    	{
    		// bestimmt, ob mensch oder computer den spieler machen

    		if(spielerTyp[0] == MENSCH)
    		{
    			menschlicherZug(spielfeld , aktuellerSpieler);
    		}
    		else if(spielerTyp[1] == COMPUTER)
    		{
    			computerZug(spielfeld , aktuellerSpieler);
    		}
    		/*
    		if(spielerTyp[0] == MENSCH && aktuellerSpieler==1)
    		{
    			menschlicherZug(spielfeld , aktuellerSpieler);
    		}
    		else if(spielerTyp[0] == COMPUTER && aktuellerSpieler==1)
    		{
    			computerZug(spielfeld , aktuellerSpieler);
    		}
    		else if(spielerTyp[1] == MENSCH && aktuellerSpieler==2)
    		{
    		    menschlicherZug(spielfeld , aktuellerSpieler);
    		}
    		else if(spielerTyp[1] == COMPUTER && aktuellerSpieler==2)
    		{
    		    computerZug(spielfeld , aktuellerSpieler);
    		}
    		*/
    		//
    	}

    	aktuellerSpieler = 3-aktuellerSpieler; //change player(1->2 , 2->1)
    	zeigeSpielfeld(spielfeld);
    	std::cout<<std::endl;
    	std::cout<<"Runden : "<<Runde<<std::endl;
    	Runde++;
    }

    ///wer hat den Spiel gewonnen?
    switch (gewinner(spielfeld))
    {
    	case 0 :
    		std::cout<<"The Game ended in a draw "<<std::endl;
    		break;
    	case 1:
    		std::cout<<"Player 1 has won "<<std::endl;
    		break;
    	case 2:
    		std::cout<<"Player 2 has won "<<std::endl;
    		break;
    }
}

int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    int spielfeld[GROESSE_Y][GROESSE_X];

    initialisiereSpielfeld(spielfeld);

    zeigeSpielfeld(spielfeld);

    int playerOne = 2;
    int playerTwo = 2 ;

    std::cout<<"Wilkommen zum Reversi!!!"<<std::endl;
    std::cout<<"Ist Player1 einen Mensch oder Computer? (1)=Mensch (2)=Computer"<<std::endl;

    std::cin>>playerOne;



    std::cout<<"Ist Player2 einen Mensch oder Computer? (1)=Mensch (2)=Computer"<<std::endl;

    std::cin>>playerTwo;


    int spielerTyp[2] = { playerOne, playerTwo };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    spielen(spielerTyp);
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    
    return 0;
}
