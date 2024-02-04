#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while (true)
    {
        if (!personalBudget.checkIfUserLoggedIn())
        {
            choice = personalBudget.selectAnOptionFromMainMenu();

            switch (choice)
            {
            case '1': personalBudget.registerUser(); break;
            case '2': personalBudget.loginUser(); break;
            case '9': exit(0); break;
            default:
                cout << endl << "No such an option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.selectAnOptionFromUserMenu();

            switch (choice)
            {
                case '1': personalBudget.addIncome(); break;
                case '2': personalBudget.addExpense(); break;
                case '3': personalBudget.showCurrentMonthsBalance(choice); break;
                case '4': personalBudget.showPreviousMonthsBalance(choice); break;
                case '5': personalBudget.showSelectedPeriodBalance(choice); break;
                case '6': personalBudget.changeLoggedInUserPassword(); break;
                //case '7': personalBudget.logoutUser(); break;
            }
        }
    }
    return 0;
}
