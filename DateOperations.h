#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "ConversionMethods.h"
#include "InputMethods.h"

class DateOperations
{
    string readTodaysDate();
    string readDay(string date);
    string readMonth(string date);
    string readYear(string date);
    string readNumber(string text, int signPosition);
    bool checkIfEnteredDateIsCorrect(string date);
    bool checkNumberOfDaysInMonth(int day, int month, int year);

    int mergeDateWithoutDashes(string date);

public:
    DateOperations() {};

    int readSelectedTransactionDate();
};

#endif
