#include "primeNumbers.h"
#include<iostream>
#include<list>
#include<vector>

void outputPrimeNumbersWithListUpTo(int range)
{
	// Schreibe alle Zahlen von 2 bis n in eine Liste
	std::list<int> numberList;
	for(int i = 2; i <= range; i++)
	{
		numberList.push_back(i);
	}
	// Lösche alle nicht Primzahlen aus der Liste
	for (int i = 2; i <= floor(sqrt(range)); i++)
	{
		for(int k = i; k <= floor(range / i); k++)
		{
			numberList.remove(i * k);
			//std::cout << "Removed: " << i * k << "\n";
		}
	}

	// Gebe die komplette List aus
	std::cout << "| ";
	for(auto const& i : numberList)
	{
		std::cout << i << " | ";
	}
}
void outputPrimeNumbersWithArrayUpTo(int range)
{
	int* primeList = new int[range];

	for(int i = 2; i <= range; i++)
	{
		primeList[i] = i;
	}

	for(int i = 2; i < sqrt(range); i++)
	{
		for(int k = i; k <= (range / i); k++)
		{
			primeList[k * i] = 0;
			//std::cout << "Removed: " << i * k << "\n";
		}
	}
	std::cout << "| ";
	for(int i = 2; i <= range; i++)
	{
		if(primeList[i] != 0)
			std::cout << primeList[i] << " | ";
	}

	primeList = nullptr;
	delete[] primeList;
}
