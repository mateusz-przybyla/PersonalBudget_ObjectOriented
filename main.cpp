#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml");

    personalBudget.loginUser();

    personalBudget.showIncomes();
    personalBudget.addIncome();
    personalBudget.addIncome();
    personalBudget.showIncomes();

    return 0;
}
