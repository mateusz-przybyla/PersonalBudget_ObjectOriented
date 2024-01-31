#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "ConversionMethods.h"

class UsersFile
{
    int lastUserId;
    const string usersFilename;
    CMarkup xml;

public:
    UsersFile(string USERSFILENAME) : usersFilename(USERSFILENAME) {};

    void writeNewUserInFile(User user);
    vector <User> loadUsersFromFile();
    void updatePasswordInFile(User user);
};

#endif
