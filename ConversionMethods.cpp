#include "ConversionMethods.h"

string ConversionMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

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
