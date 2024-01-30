#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>

#include "UserManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;

public:
    PersonalBudget() {};

    void registerUser();
    void showUsers();
};

#endif
