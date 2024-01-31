#include "PersonalBudget.h"

void PersonalBudget::registerUser()
{
    userManager.registerUser();
}

void PersonalBudget::loginUser()
{
    userManager.loginUser();
}

void PersonalBudget::showUsers()
{
    userManager.showUsers();
}

void PersonalBudget::loadUsersFromFile()
{
    userManager.loadUsersFromFile();
}

void PersonalBudget::changeLoggedInUserPassword()
{
    userManager.changeLoggedInUserPassword();
}



