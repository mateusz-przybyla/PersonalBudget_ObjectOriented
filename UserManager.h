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
    UserManager(string usersFilename) : usersFile(usersFilename) {};

    int getLoggedInUserId();

    void registerUser();
    void loginUser();
    void changeLoggedInUserPassword();
    void showUsers();
    void loadUsersFromFile();
};

#endif
