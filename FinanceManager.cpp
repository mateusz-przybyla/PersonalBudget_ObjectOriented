#include "FinanceManager.h"

void FinanceManager::addIncome()
{
    Transaction income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = enterNewIncomeData();

    incomes.push_back(income);

    if (financesFile.writeNewIncomeInFile(income))
        cout << endl << "New income was added." << endl << endl;
    else
       cout << "Error. Failed to add new income to file." << endl;
    system("pause");
}

Transaction FinanceManager::enterNewIncomeData()
{
    Transaction income;

    income.setTransactionId(readNewIncomeId());
    income.setUserId(LOGGED_IN_USER_ID);
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

void FinanceManager::showFinanseBalance(char choice)
{
    string startDate = "", endDate = "";
    //double sumOfIncomes = 0, sumOfExpenses = 0;

    startDate = dateOperations.readStartDate(choice);
    endDate = dateOperations.readEndDate(choice);
    dateOperations.checkOrderOfEnteredDates(startDate, endDate);

    system("cls");
    if ((!incomes.empty()))
    {
        cout << ">>> TRANSACTIONS SEARCHING <<<" << endl;
        cout << "------------------------------" << endl;
        cout << "From " << startDate << " to " << endDate << " found: ";
        cout << endl << endl << "-> incomes: " << endl;
        selectSortedTransactions(dateOperations.mergeDateWithoutDashes(startDate), dateOperations.mergeDateWithoutDashes(endDate), incomes);
        //sumOfIncomes = sumTransactions(mergeDateWithoutDashes(startDate), mergeDateWithoutDashes(endDate), incomes);
        //cout << endl << "------------------------------" << endl;
        //cout << "Sum of incomes: " << sumOfIncomes << " zl" << endl;
        //cout << endl << endl << "-> expenses: " << endl;
        //selectSortedTransactions(mergeDateWithoutDashes(startDate), mergeDateWithoutDashes(endDate), expenses);
        //sumOfExpenses = sumTransactions(mergeDateWithoutDashes(startDate), mergeDateWithoutDashes(endDate), expenses);
        //cout << endl << "------------------------------" << endl;
        //cout << "Sum of expenses: " << sumOfExpenses << " zl" << endl;
        //cout << endl << "==============================" << endl;
        //cout << "Balance (Incomes - Expenses): " << sumOfIncomes - sumOfExpenses << " zl" << endl;
    }
    else
        cout << endl << "No transactions on the list." << endl << endl;

    cout << endl << endl;
    system("pause");
}

void FinanceManager::selectSortedTransactions(int startDate, int endDate, vector <Transaction> transactions)
{
    sort(transactions.begin(), transactions.end(), [](Transaction &lhs, Transaction &rhs)
    {
        return lhs.getDate() < rhs.getDate();
    });

    for (vector <Transaction>::iterator itr = transactions.begin(); itr != transactions.end(); itr++)
    {
        if (((itr -> getDate()) >= startDate) && ((itr -> getDate()) <= endDate))
            showTransactionData(*itr);
    }
}

void FinanceManager::showTransactionData(Transaction transaction)
{
    cout << endl;
    cout << transaction.getTransactionId() << "|";
    cout << transaction.getUserId() << "|";
    cout << dateOperations.splitDateByDashes(transaction.getDate()) << "|";
    cout << transaction.getItem() << "|";
    cout << transaction.getAmount() << "|";
}
