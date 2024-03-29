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
    vector <Transaction> expenses;
    DateOperations dateOperations;
    FinancesFile financesFile;

    Transaction enterNewIncomeData();
    Transaction enterNewExpenseData();
    char showTypesOfExpenses();
    int readNewIncomeId();
    int readNewExpenseId();
    void showTransactionData(Transaction transaction);
    void selectSortedTransactions(int startDate, int endDate, vector <Transaction> transactions);
    double sumTransactions(int startDate, int endDate, vector <Transaction> transactions);

public:
    FinanceManager(int loggedInUserId, string incomesFilename, string expensesFilename) : LOGGED_IN_USER_ID(loggedInUserId), financesFile(incomesFilename, expensesFilename)
    {
        incomes = financesFile.loadIncomesFromFile(LOGGED_IN_USER_ID);
        expenses = financesFile.loadExpensesFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();
    void showFinanseBalance(char choice);
};

#endif
