#include "PersonalBudget.h"

void PersonalBudget::registerUser()
{
    userManager.registerUser();
}

void PersonalBudget::loginUser()
{
    userManager.loginUser();
    if (checkIfUserLoggedIn())
        financeManager = new FinanceManager(userManager.getLoggedInUserId(), INCOMES_FILENAME, EXPENSES_FILENAME);
}

void PersonalBudget::changeLoggedInUserPassword()
{
    if (checkIfUserLoggedIn())
        userManager.changeLoggedInUserPassword();
    else
    {
        cout << "Log in before change password." << endl;
        system("pause");
    }
}

void PersonalBudget::logoutUser()
{
    userManager.logoutUser();
    delete financeManager;
    financeManager = NULL;
}

void PersonalBudget::addIncome()
{
    if (checkIfUserLoggedIn())
        financeManager->addIncome();
    else
    {
        cout << "Log in before add new income." << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense()
{
    if (checkIfUserLoggedIn())
        financeManager->addExpense();
    else
    {
        cout << "Log in before add new expense." << endl;
        system("pause");
    }
}

void PersonalBudget::showCurrentMonthsBalance(char choice)
{
    if (checkIfUserLoggedIn())
        financeManager->showFinanseBalance(choice);
    else
    {
        cout << "Log in before show current months transactions balance." << endl;
        system("pause");
    }
}

void PersonalBudget::showPreviousMonthsBalance(char choice)
{
    if (checkIfUserLoggedIn())
        financeManager->showFinanseBalance(choice);
    else
    {
        cout << "Log in before show previous months transactions balance." << endl;
        system("pause");
    }
}

void PersonalBudget::showSelectedPeriodBalance(char choice)
{
    if (checkIfUserLoggedIn())
        financeManager->showFinanseBalance(choice);
    else
    {
        cout << "Log in before show selected period transactions balance." << endl;
        system("pause");
    }
}

bool PersonalBudget::checkIfUserLoggedIn()
{
    return userManager.checkIfUserLoggedIn();
}

char PersonalBudget::selectAnOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "     >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "-> 1. Create an account" << endl;
    cout << "-> 2. Sign in" << endl;
    cout << "-> 9. Close app" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = InputMethods::readChar();

    return choice;
}

char PersonalBudget::selectAnOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << "======================================" << endl;
    cout << ">>>>>>>>>>>>>> USER MENU <<<<<<<<<<<<<" << endl;
    cout << "======================================" << endl << endl;
    cout << "-> 1. Add new income" << endl;
    cout << "-> 2. Add new expense" << endl;
    cout << "-> 3. Show current month's balance" << endl;
    cout << "-> 4. Show previous month's balance" << endl;
    cout << "-> 5. Show selected period balance" << endl;
    cout << "======================================" << endl;
    cout << "-> 6. Change password" << endl;
    cout << "-> 7. Sign out" << endl;
    cout << "======================================" << endl;
    cout << "Your choice: ";
    choice = InputMethods::readChar();

    return choice;
}
