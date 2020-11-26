#include "linearRegression.h"
#include <iostream>
#include <math.h>
#include <string>

std::string linearRegression()
{
	std::pair<double, double> pairs[11];
	pairs[0] = std::make_pair(1905, 7.7);
	pairs[1] = std::make_pair(1915, 8.0);
	pairs[2] = std::make_pair(1925, 7.9);
	pairs[3] = std::make_pair(1935, 8.1);
	pairs[4] = std::make_pair(1945, 8.3);
	pairs[5] = std::make_pair(1955, 8.1);
	pairs[6] = std::make_pair(1965, 7.9);
	pairs[7] = std::make_pair(1975, 8.3);
	pairs[8] = std::make_pair(1985, 8.5);
	pairs[9] = std::make_pair(1995, 9.0);
	pairs[10] = std::make_pair(2005, 9.2);
	
	double result = 0;

	double sumXiYi = 0;
	double averageX = 0;
	double averageY = 0;
	double sumXiSquared = 0;

	for(int i = 0; i < sizeof(pairs) / sizeof(*pairs); i++)
	{
		sumXiYi += pairs[i].first * pairs[i].second;

		averageX += pairs[i].first;
		averageY += pairs[i].second;

		sumXiSquared += pow(pairs[i].first, 2);
	}

	double nominator = 0;
	double denominator = 0;
	double n = sizeof(pairs) / sizeof(*pairs);
	averageX = averageX / n;
	averageY = averageY / n;

	nominator = sumXiYi - n * averageX * averageY;
	denominator = sumXiSquared - n * pow(averageX, 2);

	double b = nominator / denominator;
	double a = averageY - b * averageX;

	return std::string("a ") + std::to_string(a) + " b " + std::to_string(b);
}
