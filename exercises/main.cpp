#include <iostream>

#include "nthRoot.h"
#include "primeNumbers.h"
#include "archimedesPi.h"
#include "karatsuba.h"
using namespace std;

void testNthRoot()
{
	cout << "-------------NTH ROOT-------------" << "\n";
	cout << "| " << calculateNthRootNew(16, 2) << " | ";
	cout << "\n";
}

void testPrimeNubmersWithArray()
{
	cout << "-------------PRIME NUMBERS WITH ARRAY-------------" << "\n";
	outputPrimeNumbersWithArrayUpTo(20);
	cout << "\n";
}

void testPrimeNubmersWithList()
{
	cout << "-------------PRIME NUMBERS WITH LIST-------------" << "\n";
	outputPrimeNumbersWithListUpTo(20);
	cout << "\n";
}

void testCalculatePi()
{
	cout << "-------------CALCULATE PI WITH ARCHIMEDES-------------" << "\n";
	calculatePi();
}

void testCalculatePiNew()
{
	cout << "-------------CALCULATE PI WITH ARCHIMEDES-------------" << "\n";
	calculatePiNew();
}

void testKaratsuba()
{
	cout << "-------------KARATSUBA-------------" << "\n";
	cout << "Test values: 1234 * 5678";
	cout << "| " << karatsuba(1234, 5678) << " | ";
	cout << "\n";
}

int main()
{
	//testCalculatePiNew();
	testKaratsuba();
}