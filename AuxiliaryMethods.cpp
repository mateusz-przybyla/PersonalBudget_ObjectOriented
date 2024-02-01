#include "AuxiliaryMethods.h"

double AuxiliaryMethods::roundDouble(double number)
{
    return round(number * 100) / 100;
}

string AuxiliaryMethods::replaceCommaWithDot(string text)
{
    if (!text.empty())
    {
        for (size_t i = 0; i < text.length(); i++)
        {
            if (text[i] == ',')
                text.replace(i, 1, ".");
        }
    }
    return text;
}

string AuxiliaryMethods::readNumber(string text, int signPosition)
{
    string number = "";
    while (isdigit(text[signPosition]))
    {
        number += text[signPosition];
        signPosition++;
    }
    return number;
}
