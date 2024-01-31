#include "UsersFile.h"

void UsersFile::writeNewUserInFile(User user)
{
    bool fileExist = xml.Load(usersFilename);

    if (!fileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("user");
    xml.IntoElem();
    xml.AddElem("userId", user.getUserId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());

    xml.Save(usersFilename);
}

vector <User> UsersFile::loadUsersFromFile()
{
    vector <User> users;
    bool fileExist = xml.Load(usersFilename);

    if (fileExist)
    {
        while (xml.FindElem("users"))
        {
            User user;
            xml.IntoElem();

            while (xml.FindElem("user"))
            {
                xml.IntoElem();
                xml.FindElem("userId");
                user.setUserId(convertStringToInt(xml.GetData()));
                xml.FindElem("login");
                user.setLogin(xml.GetData());
                xml.FindElem("password");
                user.setPassword(xml.GetData());
                xml.FindElem("name");
                user.setName(xml.GetData());
                xml.FindElem("surname");
                user.setSurname(xml.GetData());

                users.push_back(user);
                xml.OutOfElem();
            }
        }
    }
    return users;
}

int UsersFile::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
