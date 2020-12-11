#include <iostream>

#include "nthRoot.h"
#include "primeNumbers.h"
#include "archimedesPi.h"
#include "karatsuba.h"
#include "integral.h"
#include "linearRegression.h"
#include "differentialEquation.h"
#include "lrElimination.h"
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

void testIntegral()
{
	double a = 0, b = 2;
	int amountIntervalls = 4;
	/*
	cout << "a eingeben\n";
	cin >> a;

	cout << "b eingeben\n";
	cin >> b;

	cout << "amountIntervalls eingeben\n";
	cin >> amountIntervalls;
	cout << "\n";
	*/
	cout << "Rectangular: " << rectangularIntegral(a, b, amountIntervalls) << "\n";
	cout << "Trapezoid: " << trapezoidalIntegral(a, b, amountIntervalls) << "\n";
	cout << "simpsonIntegral: " << simpsonIntegral(a, b, amountIntervalls) << "\n";
}

void testLinearRegression()
{
	cout << "-------------Linear Regression-------------" << "\n";
	cout << "| " << linearRegression() << " | ";
	cout << "\n";
}

void testDifferentialEquation()
{
	double startX = 0;
	double startY = 1;
	double searchedValue = 4;
	double stepWidth = 1;

	cout << "-------------EULER-CAUCHY-------------" << "\n";
	eulerCauchy(startX, startY, searchedValue, stepWidth);
	cout << "\n-------------IMPROVED-EULER-CAUCHY-------------" << "\n";
	improvedEulerCauchy(startX, startY, searchedValue, stepWidth);
	cout << "\n-------------RUNGEKUTTA 2-------------" << "\n";
	rungeKutta2(startX, startY, searchedValue, stepWidth);
	cout << "\n-------------RUNGEKUTTA 4-------------" << "\n";
	rungeKutta4(startX, startY, searchedValue, stepWidth);
}

int main()
{
	eliminate();
}