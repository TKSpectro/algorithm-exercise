#include "integral.h"
#include<math.h>
#include<iostream>
double f(double valueForX)
{
	// for function x²
	return pow(valueForX, 2);
}

double rectangularIntegral(double a, double b, int amountIntervalls)
{
	double deltaX = (a - b) / amountIntervalls;
	double untersumme = 0, obersumme = 0, result = 0;

	// calculate untersumme
	for(int i = 0; i < amountIntervalls; ++i)
	{
		untersumme += f(a + (i * deltaX)) * deltaX;
	}
	// calculate obersumme
	for(int i = 0; i < amountIntervalls; ++i)
	{
		obersumme += f(a + ((i + 1) * deltaX)) * deltaX;
	}
	// returns the average of unter and obersumme
	return abs((untersumme + obersumme) / 2);
}

double trapezoidalIntegral(double a, double b, int amountIntervalls)
{
	double deltaX = (a - b) / amountIntervalls;
	double result = 0;

	// calculate values from 1 to n-1
	for(int i = 1; i <= amountIntervalls - 1; ++i)
	{
		result += f(a + (i * deltaX));
	}
	// add first and last
	result += f(a) / 2;
	result += f(b) / 2;

	return abs(result * deltaX);
}

double simpsonIntegral(double a, double b, int amountIntervalls)
{
	double deltaX = (a - b) / amountIntervalls;
	double result = 0;

	// add first and last
	result += f(a);
	result += f(b);

	for(int i = 0; i < amountIntervalls; ++i)
	{
		// is even
		if(i % 2 == 0)
		{
			result += 2 * f(a + (i * deltaX));
		}
		// is odd
		else
		{
			result += 4 * f(a + (i * deltaX));
		}
	}

	result *= deltaX / 3;

	return result;
}