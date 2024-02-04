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
    const string INCOMES_FILENAME;
    vector <Transaction> incomes;
    DateOperations dateOperations;
    CMarkup xml;

public:
    FinancesFile(string incomesFilename) : INCOMES_FILENAME(incomesFilename)
    {
        lastIncomeId = 0;
    };

    vector <Transaction> loadIncomesFromFile(int loggedInUserId);
    bool writeNewIncomeInFile(Transaction income);
};

#endif
