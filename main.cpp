#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    personalBudget.loginUser();
    personalBudget.showExpenses();
    //personalBudget.showFinanseBalance();
    personalBudget.addExpense();
    //personalBudget.addExpense();
    personalBudget.showExpenses();
    //personalBudget.showFinanseBalance();

    return 0;
}
