#include "UserManager.h"

void UserManager::registerUser()
{
    User user = enterNewUserData();

    users.push_back(user);
    usersFile.writeNewUserInFile(user);

    cout << endl << "Account created" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserData()
{
    User user;

    user.setUserId(readNewUserId());

    do
    {
        cout << "Enter username: ";
        user.setLogin(InputMethods::readLine());
    } while (checkUsername(user.getLogin()));

    cout << "Enter password: ";
    user.setPassword(InputMethods::readLine());
    cout << "Enter name: ";
    user.setName(InputMethods::readLine());
    cout << "Enter surname: ";
    user.setSurname(InputMethods::readLine());

    return user;
}

int UserManager::readNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::checkUsername(string loginSuggestion)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == loginSuggestion)
        {
            cout << endl << "Such a username exists." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showUsers()
{
    for (auto user : users)
    {
        cout << endl;
        cout << user.getUserId() << endl;
        cout << user.getLogin() << endl;
        cout << user.getPassword() << endl;
        cout << user.getName() << endl;
        cout << user.getSurname() << endl;
    }
}

void UserManager::loadUsersFromFile()
{
    users = usersFile.loadUsersFromFile();
}
