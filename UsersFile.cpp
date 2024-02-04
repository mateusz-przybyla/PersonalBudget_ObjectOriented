#include "UsersFile.h"

void UsersFile::writeNewUserInFile(User user)
{
    bool fileExist = xml.Load(USERS_FILENAME);

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

    xml.Save(USERS_FILENAME);
}

vector <User> UsersFile::loadUsersFromFile()
{
    vector <User> users;
    bool fileExist = xml.Load(USERS_FILENAME);

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
                user.setUserId(ConversionMethods::convertStringToInt(xml.GetData()));
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

void UsersFile::updatePasswordInFile(User user)
{
    bool fileExist = xml.Load(USERS_FILENAME);

    if (fileExist)
    {
        while (xml.FindElem("users"))
        {
            xml.IntoElem();

            while (xml.FindElem("user"))
            {
                xml.IntoElem();
                xml.FindElem("userId");
                if (ConversionMethods::convertStringToInt(xml.GetData()) == user.getUserId())
                {
                    xml.FindElem("password");
                    xml.RemoveElem();
                    xml.AddElem("password", user.getPassword());
                    xml.Save(USERS_FILENAME);
                }
                xml.OutOfElem();
            }
        }
    }
}
