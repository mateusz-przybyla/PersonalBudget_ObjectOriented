#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>

#include "Transaction.h"
#include "InputMethods.h"
#include "DateOperations.h"
#include "FinancesFile.h"

class FinanceManager
{
    const int LOGGED_IN_USER_ID;
    vector <Transaction> incomes;
    DateOperations dateOperations;
    FinancesFile financesFile;

    Transaction enterNewIncomeData();
    int readNewIncomeId();

public:
    FinanceManager(int loggedInUserId, string incomesFilename) : LOGGED_IN_USER_ID(loggedInUserId), financesFile(incomesFilename)
    {
        incomes = financesFile.loadIncomesFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void showIncomes();
};

#endif
