#include "InputMethods.h"

string InputMethods::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}
