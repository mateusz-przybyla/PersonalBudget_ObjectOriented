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

public:
    PersonalBudget(string usersFilename, string incomesFilename) : userManager(usersFilename), INCOMES_FILENAME(incomesFilename)
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
    void showFinanseBalance();
};

#endif
