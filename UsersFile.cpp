#include "UsersFile.h"

void UsersFile::writeNewUserInFile(User user)
{
    CMarkup xml;
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
