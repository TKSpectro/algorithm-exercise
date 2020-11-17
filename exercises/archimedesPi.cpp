#include "archimedesPi.h"
#include<math.h>
#include<iostream>
#include<cmath>

double calculatePi()
{
    double s = 1.0;
    double numberOfSides = 6.0;
    puts("number of sides |  approximate value of pi");
    while(numberOfSides < 4000)
    {
        printf("%9.0f       |       %18.16f\n", numberOfSides, numberOfSides * s / 2.0);
        double h = s / 2.0;
        double z = sqrt(1.0 - h * h);
        s = sqrt(h * h + (1.0 - z) * (1.0 - z));
        numberOfSides *= 2;
    }

    return s;
}

double calculatePiNew()
{
    // length of one side of the nEck
    double sn = 2;
    double s2n = 0;
    double n = 2;

    double pi = 1;
    double secondPi = 0;

    while(abs(pi - secondPi) > 0.000001)
    {
        secondPi = pi;

        // use archimedes formula (page 15 script 2)
        s2n = sqrt(pow(sn, 2) / (2 + 2 * sqrt(1 - pow(sn, 2) / 4)));
        pi = s2n * n;
        std::cout << pi << "\n";

        // edge of new figure becomes inital
        sn = s2n;
        n *= 2;
    }

    return pi;
}