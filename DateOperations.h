#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include <iostream>
#include <ctime>
#include <iomanip>

#include "ConversionMethods.h"
#include "InputMethods.h"
#include "AuxiliaryMethods.h"

class DateOperations
{
    string readTodaysDate();
    string readDay(string date);
    string readMonth(string date);
    string readYear(string date);
    bool checkIfEnteredDateIsCorrect(string date);
    bool checkNumberOfDaysInMonth(int day, int month, int year);
    int mergeDateWithoutDashes(string date);

public:
    DateOperations() {};

    int readSelectedTransactionDate();
};

#endif
