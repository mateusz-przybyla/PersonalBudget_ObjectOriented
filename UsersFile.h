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
    const string usersFilename;
    CMarkup xml;

public:
    UsersFile(string USERSFILENAME) : usersFilename(USERSFILENAME) {};

    void writeNewUserInFile(User user);
    vector <User> loadUsersFromFile();
    int convertStringToInt(string number);
};

#endif
