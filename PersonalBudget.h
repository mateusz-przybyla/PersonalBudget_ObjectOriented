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

public:
    PersonalBudget(string usersFilename) : userManager(usersFilename)
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
    void showIncomes();
};

#endif
