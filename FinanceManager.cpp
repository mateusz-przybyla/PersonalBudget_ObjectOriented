#include "FinanceManager.h"

void FinanceManager::addIncome(int loggedInUserId)
{
    Transaction income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = enterNewIncomeData(loggedInUserId);

    incomes.push_back(income);

    //if (writeNewIncomeInFile(income))
        //cout << endl << "New income was added." << endl << endl;
    //else
       //cout << "Error. Failed to add new income to file." << endl;
    system("pause");
}

Transaction FinanceManager::enterNewIncomeData(int loggedInUserId)
{
    Transaction income;

    income.setTransactionId(readNewIncomeId());
    income.setUserId(loggedInUserId);
    income.setDate(dateOperations.readSelectedTransactionDate());

    cout << "Enter purpose: ";
    income.setItem(InputMethods::readLine());
    cout << "Enter amount: ";
    income.setAmount(InputMethods::readDouble());

    return income;
}

int FinanceManager::readNewIncomeId()
{
    if (incomes.empty())
        return 1;
    else
        return incomes.back().getTransactionId() + 1;
}

void FinanceManager::showIncomes()
{
    for (auto income : incomes)
    {
        cout << endl;
        cout << income.getTransactionId() << endl;
        cout << income.getUserId() << endl;
        cout << income.getDate() << endl;
        cout << income.getItem() << endl;
        cout << income.getAmount() << endl;
    }
}
