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
        financeManager = new FinanceManager(userManager.getLoggedInUserId(), INCOMES_FILENAME, EXPENSES_FILENAME);
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

void PersonalBudget::addExpense()
{
    if (checkIfUserLoggedIn())
    {
        financeManager->addExpense();
    }
    else
    {
        cout << "Log in before add new expense." << endl;
        system("pause");
    }
}

void PersonalBudget::showFinanseBalance()
{
    char choice = '1';
    financeManager->showFinanseBalance(choice);
}

bool PersonalBudget::checkIfUserLoggedIn()
{
    return userManager.checkIfUserLoggedIn();
}
