#include "nthRoot.h"
#include<math.h>
#include<iostream>
float calculateNthRootOld(double num, double n)
{
    // Starting number
    double startNum = num;
    // current number
    double curNum = num;
    // old number
    double oldNum;
    // Accuracy, smaller -> higher accuracy
    double eps(10e-6);
    // N-th root
    oldNum = (startNum / pow(curNum, n - 1) - curNum) / n;
    while(oldNum >= eps || oldNum <= -eps)
    {
        curNum = curNum + oldNum;
        //oldNum = ((n - 1) * pow(curNum, n) + startNum) / n * pow(curNum, n - 1);
        oldNum = (startNum / pow(curNum, n - 1) - curNum) / n;
    }
    return curNum;
}

float calculateNthRootNew(double num, double n)
{
    double start = 1.0;
    double accuracy = 0.02;
    double x = 0;
    double diff = 1;

    while(diff > accuracy)
    {
        x = ((n - 1) * pow(start, n) + num) / (n * pow(start, n - 1));
        diff = abs(start - x);
        start = x;
    }

    return x;
}