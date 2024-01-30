#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>

#include "Markup.h"
#include "User.h"
#include "InputMethods.h"

class UsersFile
{
    int lastUserId;
    string usersFilename;

public:
    UsersFile()
    {
        usersFilename = "users.xml";
    }

    void writeNewUserInFile(User user);
};

#endif
