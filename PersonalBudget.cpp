#include "PersonalBudget.h"

void PersonalBudget::registerUser()
{
    User user = enterNewUserData();

    users.push_back(user);
    //writeNewUserInFile(user);

    cout << endl << "Account created" << endl << endl;
    system("pause");
}

User PersonalBudget::enterNewUserData()
{
    User user;

    user.setUserId(readNewUserId());

    do
    {
        cout << "Enter username: ";
        user.setLogin(readLine());
    } while (checkUsername(user.getLogin()));

    cout << "Enter password: ";
    user.setPassword(readLine());
    cout << "Enter name: ";
    user.setName(readLine());
    cout << "Enter surname: ";
    user.setSurname(readLine());

    return user;
}

int PersonalBudget::readNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool PersonalBudget::checkUsername(string loginSuggestion)
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

string PersonalBudget::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

void PersonalBudget::showUsers()
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
