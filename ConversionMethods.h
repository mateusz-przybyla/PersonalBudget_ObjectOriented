#ifndef CONVERSIONMETHODS_H
#define CONVERSIONMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class ConversionMethods
{
public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static double convertStringToDouble(string number);
};

#endif
