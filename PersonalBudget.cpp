#include "PersonalBudget.h"

void PersonalBudget::registerUser()
{
    userManager.registerUser();
}

void PersonalBudget::loginUser()
{
    userManager.loginUser();
    if (checkIfUserLoggedIn())
    {
        financeManager = new FinanceManager(userManager.getLoggedInUserId(), INCOMES_FILENAME);
    }
}

void PersonalBudget::changeLoggedInUserPassword()
{
    if (checkIfUserLoggedIn())
    {
        userManager.changeLoggedInUserPassword();
    }
    else
    {
        cout << "Log in before change password." << endl;
        system("pause");
    }
}

void PersonalBudget::addIncome()
{
    if (checkIfUserLoggedIn())
    {
        financeManager->addIncome();
    }
    else
    {
        cout << "Log in before add new income." << endl;
        system("pause");
    }
}

void PersonalBudget::showIncomes()
{
    financeManager->showIncomes();
}

bool PersonalBudget::checkIfUserLoggedIn()
{
    return userManager.checkIfUserLoggedIn();
}
