#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <math.h>

using namespace std;

class AuxiliaryMethods
{
public:
    static double roundDouble(double number);
    static string replaceCommaWithDot(string text);
    static string readNumber(string text, int signPosition);
};

#endif
