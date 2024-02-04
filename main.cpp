#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    personalBudget.loginUser();

    personalBudget.showFinanseBalance();
    personalBudget.addExpense();
    personalBudget.addExpense();
    personalBudget.showFinanseBalance();

    return 0;
}
