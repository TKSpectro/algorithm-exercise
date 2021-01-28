#include "optima.h"
#include <iostream>

float fx(float x)
{
	return -2 * x;
}
float fy(float y)
{
	return -2 * y;
}

void gradientProcedure()
{
	int i = 0;
	float s = 0.3f;
	float di[2];
	float xi[2] = {1,1};
	float h = 0.001;

	do
	{
		std::cout << "x:" << xi[0] << " " << "y:" << xi[1] << "\n";
		di[0] = fx(xi[0]);
		di[1] = fy(xi[1]);
		xi[0] = xi[0] + s * di[0];
		xi[1] = xi[1] + s * di[1];
	} while(abs(di[0]) > h);
}
