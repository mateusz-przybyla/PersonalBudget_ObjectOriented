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

void PersonalBudget::addIncome()
{
    financeManager.addIncome(userManager.getLoggedInUserId());
}

void PersonalBudget::showIncomes()
{
    financeManager.showIncomes();
}
