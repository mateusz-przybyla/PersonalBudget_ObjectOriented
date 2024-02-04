#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

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
    void showTransactionData(Transaction transaction);
    void selectSortedTransactions(int startDate, int endDate, vector <Transaction> transactions);

public:
    FinanceManager(int loggedInUserId, string incomesFilename) : LOGGED_IN_USER_ID(loggedInUserId), financesFile(incomesFilename)
    {
        incomes = financesFile.loadIncomesFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void showFinanseBalance(char choice);
};

#endif
