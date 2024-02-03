#include "ConversionMethods.h"

int ConversionMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double ConversionMethods::convertStringToDouble(string number)
{
    double numberDouble;
    istringstream iss(number);
    iss >> numberDouble;

    return numberDouble;
}
