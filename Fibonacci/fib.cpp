/*
 * fib.cpp
 *
 *  Created on: 30 Apr 2022
 *      Author: mkara
 */

#include <iostream>

/*
 * fib ist eine rekursive Funktion, die fib(n-1) und fib(n-2) aufruft.
 * dann wenn fib den Base-Case erreicht also mit n=0 oder n=1, gibt den wert 0 bzw. 1 zurueck
 */
int fib(int n)
{
	if(n==0 || n==1)	//base case
	{
		return n;
	}
	else		//rekursionsschritt
	{
		return fib(n-1) + fib(n-2);
	}
}

int main()
{


	for(int i = 0 ; i<=25 ; i++){

		std::cout << fib(i) << std::endl;
	}



}



