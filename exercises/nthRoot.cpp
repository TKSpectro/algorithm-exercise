#include "nthRoot.h"
#include<math.h>
#include<iostream>

float nthRoot(double number, double n)
{
    double start = 1.0;
    double accuracy = 0.02;
    double x = 0;
    double diff = 1;

    while(diff > accuracy)
    {
        x = ((n - 1) * pow(start, n) + number) / (n * pow(start, n - 1));
        diff = abs(start - x);
        start = x;
    }

    return x;
}