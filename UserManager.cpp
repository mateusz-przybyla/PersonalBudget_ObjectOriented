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

void UserManager::loginUser()
{
    string enteredLogin = "", enteredPassword = "";

    cout << endl << "Enter username: ";
    enteredLogin = InputMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == enteredLogin)
        {
            for (int attempt = 3; attempt > 0; attempt--)
            {
                cout << "Enter password. Attempts left: " << attempt << ": ";
                enteredPassword = InputMethods::readLine();

                if (itr -> getPassword() == enteredPassword)
                {
                    loggedInUserId = itr -> getUserId();
                    cout << endl << "You logged in." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "You have entered the wrong password 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with that username." << endl << endl;
    system("pause");
    return;
}

void UserManager::changeLoggedInUserPassword()
{
    string newPassword = "";
    cout << endl << "Enter new password: ";
    newPassword = InputMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == loggedInUserId)
        {
            itr -> setPassword(newPassword);
            //updatePasswordInFile(*itr, loggedInUserId);
            cout << "Password was changed." << endl << endl;
            system("pause");
        }
    }
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
