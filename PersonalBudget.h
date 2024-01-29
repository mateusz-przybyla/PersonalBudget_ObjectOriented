#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>

#include "User.h"

using namespace std;

class PersonalBudget
{
    int loggedInUserId;
    vector <User> users;

    User enterNewUserData();
    bool checkUsername(string loginSuggestion);
    int readNewUserId();
    string readLine();

public:
    void registerUser();
    void showUsers();
};

#endif
