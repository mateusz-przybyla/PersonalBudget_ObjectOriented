#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");

    personalBudget.showUsers();

    //personalBudget.registerUser();

    //personalBudget.showUsers();

    personalBudget.loginUser();

    personalBudget.changeLoggedInUserPassword();

    personalBudget.showUsers();

    return 0;
}
