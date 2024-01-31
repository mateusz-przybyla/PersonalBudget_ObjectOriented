#include "PersonalBudget.h"

void PersonalBudget::registerUser()
{
    userManager.registerUser();
}

void PersonalBudget::showUsers()
{
    userManager.showUsers();
}

void PersonalBudget::loadUsersFromFile()
{
    userManager.loadUsersFromFile();
}
