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

void FinanceManager::addExpense()
{
    Transaction expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = enterNewExpenseData();

    expenses.push_back(expense);

    if (financesFile.writeNewExpenseInFile(expense))
        cout << endl << "New expense was added." << endl << endl;
    else
       cout << "Error. Failed to add new expense to file." << endl;
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

Transaction FinanceManager::enterNewExpenseData()
{
    Transaction expense;

    expense.setTransactionId(readNewExpenseId());
    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setDate(dateOperations.readSelectedTransactionDate());

    while (expense.getItem().empty())
    {
        char choice;
        choice = showTypesOfExpenses();

        switch (choice)
        {
            case '1': expense.setItem("food"); break;
            case '2': expense.setItem("vehicles"); break;
            case '3': expense.setItem("home"); break;
            case '4': expense.setItem("health"); break;
            case '5': expense.setItem("events"); break;
            case '6': expense.setItem("holiday/journeys"); break;
            case '7': expense.setItem("other"); break;
            default:
                cout << endl << "There is no such option! Try again." << endl << endl;
                system("pause");
                break;
        }
    }
    cout << "Enter amount: ";
    expense.setAmount(InputMethods::readDouble());

    return expense;
}

char FinanceManager::showTypesOfExpenses()
{
    char choice;

    system("cls");
    cout << "Select an expense category: " << endl;
    cout << "-> 1. food" << endl;
    cout << "-> 2. vehicles" << endl;
    cout << "-> 3. home" << endl;
    cout << "-> 4. health" << endl;
    cout << "-> 5. events" << endl;
    cout << "-> 6. holiday/journeys" << endl;
    cout << "-> 7. other" << endl << endl;
    cout << "Your choice: ";
    choice = InputMethods::readChar();

    return choice;
}

int FinanceManager::readNewIncomeId()
{
    if (incomes.empty())
        return 1;
    else
        return incomes.back().getTransactionId() + 1;
}

int FinanceManager::readNewExpenseId()
{
    if (expenses.empty())
        return 1;
    else
        return expenses.back().getTransactionId() + 1;
}

void FinanceManager::showFinanseBalance(char choice)
{
    string startDate = "", endDate = "";
    double sumOfIncomes = 0;

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
        sumOfIncomes = sumTransactions(dateOperations.mergeDateWithoutDashes(startDate), dateOperations.mergeDateWithoutDashes(endDate), incomes);
        cout << endl << "------------------------------" << endl;
        cout << "Sum of incomes: " << sumOfIncomes << " zl" << endl;
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

double FinanceManager::sumTransactions(int startDate, int endDate, vector <Transaction> transactions)
{
    double sum = 0;

    for (vector <Transaction>::iterator itr = transactions.begin(); itr != transactions.end(); itr++)
    {
        if (((itr -> getDate()) >= startDate) && ((itr -> getDate()) <= endDate))
            sum += itr -> getAmount();
    }
    return sum;
}

void FinanceManager::showExpenses()
{
    for (auto expense : expenses)
    {
        cout << endl;
        cout << expense.getTransactionId() << endl;
        cout << expense.getUserId() << endl;
        cout << expense.getDate() << endl;
        cout << expense.getItem() << endl;
        cout << expense.getAmount() << endl;
    }
    system("pause");
}
