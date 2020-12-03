#include "differentialEquation.h"
#include <iostream>

double df(double x, double y)
{
    return 2 * y * x;
}

double eulerCauchy(double startX,  double startY, double searchedValue, double stepWidth)
{
    double x = startX;
    double y = startY;

    for(int i = 0; i < searchedValue / stepWidth; i++)
    {
        y = df(x, y) * stepWidth + y;
        x += stepWidth;
    }

    std::cout << "X: " << x << " Y: " << y;

    return x;
}

double improvedEulerCauchy(double startX, double startY, double searchedValue, double stepWidth)
{
    double x = startX;
    double y = startY;

    for(int i = 0; i < searchedValue / stepWidth; i++)
    {
        y = df(x + (stepWidth / 2), y + (stepWidth / 2) * df(x, y)) * stepWidth + y;
        x += stepWidth;
    }

    std::cout << "X: " << x << " Y: " << y;

    return x;
}

double rungeKutta2(double startX, double startY, double searchedValue, double stepWidth)
{
    double x = startX;
    double y = startY;

    double k1 = 0;
    double k2 = 0;
    double deltaY = 0;

    for(int i = 0; i < searchedValue / stepWidth; i++)
    {
        k1 = df(x, y);
        k2 = df(x + stepWidth, y + stepWidth * k1);
        deltaY = (stepWidth / 2) * (k1 + k2);
        y = y + deltaY;

        x += stepWidth;
    }

    std::cout << "X: " << x << " Y: " << y;

    return x;
}

double rungeKutta4(double startX, double startY, double searchedValue, double stepWidth)
{
    double x = startX;
    double y = startY;

    double k1 = 0;
    double k2 = 0;
    double k3 = 0;
    double k4 = 0;
    double deltaY = 0;

    for(int i = 0; i < searchedValue / stepWidth; i++)
    {
        k1 = df(x, y);
        k2 = df(x + stepWidth / 2, y + stepWidth * (k1 / 2));
        k3 = df(x + stepWidth / 2, y + stepWidth * (k2 / 2));
        k4 = df(x + stepWidth, y + stepWidth * k3);
        deltaY = (stepWidth / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
        y = y + deltaY;

        x += stepWidth;
    }

    std::cout << "X: " << x << " Y: " << y;

    return x;
}
