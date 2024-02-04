#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "FinanceManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    FinanceManager *financeManager;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;

public:
    PersonalBudget(string usersFilename, string incomesFilename, string expensesFilename) : userManager(usersFilename), INCOMES_FILENAME(incomesFilename), EXPENSES_FILENAME(expensesFilename)
    {
        financeManager = NULL;
    };
    ~PersonalBudget()
    {
        delete financeManager;
        financeManager = NULL;
    }

    void registerUser();
    void loginUser();
    void changeLoggedInUserPassword();
    bool checkIfUserLoggedIn();

    void addIncome();
    void addExpense();
    void showFinanseBalance();
};

#endif
