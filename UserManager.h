#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "InputMethods.h"
#include "UsersFile.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    UsersFile usersFile;

    User enterNewUserData();
    bool checkUsername(string loginSuggestion);
    int readNewUserId();

public:
    UserManager(string usersFilename) : usersFile(usersFilename)
    {
        loggedInUserId = 0;
        users = usersFile.loadUsersFromFile();
    };

    int getLoggedInUserId();

    void registerUser();
    void loginUser();
    void changeLoggedInUserPassword();
    bool checkIfUserLoggedIn();
    void logoutUser();
};

#endif
