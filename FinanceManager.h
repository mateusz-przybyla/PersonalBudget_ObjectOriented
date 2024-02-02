#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>

#include "Transaction.h"
#include "InputMethods.h"
#include "DateOperations.h"

class FinanceManager
{
    const int LOGGED_IN_USER_ID;
    vector <Transaction> incomes;
    DateOperations dateOperations;

    Transaction enterNewIncomeData();
    int readNewIncomeId();

public:
    FinanceManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId) {};

    void addIncome();
    void showIncomes();
};

#endif
