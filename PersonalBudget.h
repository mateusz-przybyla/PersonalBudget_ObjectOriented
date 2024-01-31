#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;

public:
    PersonalBudget(string usersFilename) : userManager(usersFilename)
    {
        userManager.loadUsersFromFile();
    };

    void registerUser();
    void showUsers();
    void loadUsersFromFile();
};

#endif
