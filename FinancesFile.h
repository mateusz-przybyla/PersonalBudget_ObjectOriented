#ifndef FINANCEFILE_H
#define FINANCEFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "Transaction.h"
#include "ConversionMethods.h"
#include "DateOperations.h"

class FinancesFile
{
    int lastIncomeId;
    int lastExpenseId;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;
    DateOperations dateOperations;
    CMarkup xml;

public:
    FinancesFile(string incomesFilename, string expensesFilename) : INCOMES_FILENAME(incomesFilename), EXPENSES_FILENAME(expensesFilename)
    {
        lastIncomeId = 0;
        lastExpenseId = 0;
    };

    vector <Transaction> loadIncomesFromFile(int loggedInUserId);
    vector <Transaction> loadExpensesFromFile(int loggedInUserId);
    bool writeNewIncomeInFile(Transaction income);
    bool writeNewExpenseInFile(Transaction expense);
};

#endif
