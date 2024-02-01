#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>

#include "Transaction.h"
#include "InputMethods.h"
#include "DateOperations.h"

class FinanceManager
{
    int lastIncomeId;
    vector <Transaction> incomes;
    DateOperations dateOperations;

    Transaction enterNewIncomeData(int loggedInUserId);
    int readNewIncomeId();

public:
    FinanceManager() {};

    void addIncome(int loggedInUserId);
    void showIncomes();
};

#endif
