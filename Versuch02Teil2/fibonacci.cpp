//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{
    int previousFib = 1;
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 2; i <= n; i++)		//i should start at 2 because we already finished i=0 and i=1 in previous if-statements
    {

        int newFib = previousFib + currentFib ;
        int temp = previousFib;  //add temp
        previousFib = newFib ;
        currentFib = temp ; //set currentFib to temp instead of previousFib;
    }
    return currentFib ;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 0; i <= 12 ; i ++)		//i=1 to i=0 veraendern
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;
}
