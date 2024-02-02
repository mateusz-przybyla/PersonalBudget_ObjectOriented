#ifndef INPUTMETHODS_H
#define INPUTMETHODS_H

#include <iostream>
#include <sstream>

#include "AuxiliaryMethods.h"

using namespace std;

class InputMethods
{
public:
    static string readLine();
    static double readDouble();
    static char readChar();
};

#endif
