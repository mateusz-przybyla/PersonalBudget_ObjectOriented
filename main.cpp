#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml");

    personalBudget.loginUser();

    personalBudget.showFinanseBalance();
    personalBudget.addIncome();
    personalBudget.showFinanseBalance();

    return 0;
}
