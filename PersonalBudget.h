#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "FinanceManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    FinanceManager financeManager;

    int loggedInUserId;

public:
    PersonalBudget(string usersFilename) : userManager(usersFilename)
    {
        userManager.loadUsersFromFile();
    };

    void registerUser();
    void loginUser();
    void changeLoggedInUserPassword();
    void showUsers();
    void loadUsersFromFile();

    void addIncome();
    void showIncomes();
};

#endif
