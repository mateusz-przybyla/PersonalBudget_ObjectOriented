#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"

using namespace std;

class PersonalBudget
{
    int loggedInUserId;
    vector <User> users;
    string usersFilename;

    User enterNewUserData();
    bool checkUsername(string loginSuggestion);
    int readNewUserId();
    string readLine();
    void writeNewUserInFile(User user);

public:
    PersonalBudget()
    {
        usersFilename = "users.xml";
    }

    void registerUser();
    void showUsers();
};

#endif
