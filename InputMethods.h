#ifndef INPUTMETHODS_H
#define INPUTMETHODS_H

#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

class InputMethods
{
public:
    static string readLine();
    static double readDouble();
    static char readChar();

    static double roundDouble(double number);
    static string replaceCommaWithDot(string text);
};

#endif
