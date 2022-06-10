/*
 * fib.cpp
 *
 *  Created on: 23 May 2021
 *      Author: mkara
 */
#include <iostream>


unsigned int fib(int n)
{
	if(n<=1)return n;
	else if(n>0)
	{
		return fib(n-1) + fib(n-2);
	}
}


int main()
{

	std::cout<<"Die ersten 25-Fibonnaci Zahlen sind : "<<std::endl;
	for(int i = 0 ; i<=42 ; i++)
	{
		std::cout<<i<<". Zahl :"<<fib(i)<<std::endl;
	}


}




