#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>

#include "Transaction.h"
#include "InputMethods.h"
#include "ConversionMethods.h"

class FinanceManager
{
    int lastIncomeId;
    vector <Transaction> incomes;

    Transaction enterNewIncomeData(int loggedInUserId);
    int readNewIncomeId();

    int readSelectedTransactionDate();
    string readTodaysDate();
    string readDay(string date);
    string readMonth(string date);
    string readYear(string date);
    string readNumber(string text, int signPosition);
    bool checkIfEnteredDateIsCorrect(string date);
    bool checkNumberOfDaysInMonth(int day, int month, int year);

    string replaceCommaWithDot(string text);
    int mergeDateWithoutDashes(string date);

public:
    FinanceManager() {};

    void addIncome(int loggedInUserId);
    void showIncomes();
};

#endif
