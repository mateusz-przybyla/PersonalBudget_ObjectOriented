#include "InputMethods.h"

string InputMethods::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

double InputMethods::readDouble()
{
    string input = "";
    double number = 0;

    while (true)
    {
        getline(cin, input);

        input = AuxiliaryMethods::replaceCommaWithDot(input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "It is not a number. Type again. " << endl;
    }
    return AuxiliaryMethods::roundDouble(number);
}

char InputMethods::readChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Type again: " << endl;
    }
    return character;
}
