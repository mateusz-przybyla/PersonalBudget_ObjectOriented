#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <sstream>
#include <vector>

#include "Markup.h"
#include "User.h"

class UsersFile
{
    int lastUserId;
    string usersFilename;
    CMarkup xml;

public:
    UsersFile()
    {
        usersFilename = "users.xml";
    }

    void writeNewUserInFile(User user);
    vector <User> loadUsersFromFile();
    int convertStringToInt(string number);
};

#endif
