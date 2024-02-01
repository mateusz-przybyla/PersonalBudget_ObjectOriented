#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");

    personalBudget.loginUser();
    personalBudget.addIncome();
    personalBudget.addIncome();
    personalBudget.showIncomes();

    return 0;
}
