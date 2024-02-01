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
    income.setDate(readSelectedTransactionDate());

    cout << "Enter purpose: ";
    income.setItem(InputMethods::readLine());
    cout << "Enter amount: ";
    income.setAmount(InputMethods::readDouble());

    return income;
}

int FinanceManager::readSelectedTransactionDate()
{
    char choice;
    string date = "";

    cout << "Select date: " << endl;
    cout << "-> 1. today's date" << endl;
    cout << "-> 2. other date" << endl << endl;
    cout << "Your choice: ";
    choice = InputMethods::readChar();

    switch(choice)
    {
    case '1':
        date = readTodaysDate();
        break;
    case '2':
        do
        {
            cout << "Enter date in YYYY-MM-DD format: ";
            date = InputMethods::readLine();
        } while (!checkIfEnteredDateIsCorrect(date));
        break;
    default:
        cout << "No such an option. Today's date was selected by default." << endl;
        date = readTodaysDate();
        system("pause");
        break;
    }
    return mergeDateWithoutDashes(date);
}

string FinanceManager::readTodaysDate()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream ss;
    ss << put_time(localTime, "%Y-%m-%d");

    return ss.str();
}

string FinanceManager::readDay(string date)
{
    int position = date.find_last_of('-') + 1;
    string day = readNumber(date, position);

    return day;
}

string FinanceManager::readMonth(string date)
{
    int position = date.find_first_of('-') + 1;
    string month = readNumber(date, position);

    return month;
}

string FinanceManager::readYear(string date)
{
    int position = 0;
    string year = readNumber(date, position);

    return year;
}

string FinanceManager::readNumber(string text, int signPosition)
{
    string number = "";
    while (isdigit(text[signPosition]))
    {
        number += text[signPosition];
        signPosition++;
    }
    return number;
}

bool FinanceManager::checkIfEnteredDateIsCorrect(string date)
{
    int enteredDay = 0, enteredMonth = 0, enteredYear = 0;

    enteredDay = ConversionMethods::convertStringToInt(readDay(date));
    enteredMonth = ConversionMethods::convertStringToInt(readMonth(date));
    enteredYear = ConversionMethods::convertStringToInt(readYear(date));

    int enteredDate = 0;
    enteredDate = mergeDateWithoutDashes(date);

    int currentDate = 0;
    currentDate = mergeDateWithoutDashes(readTodaysDate());

    if ((checkNumberOfDaysInMonth(enteredDay, enteredMonth, enteredYear)) && (enteredDate <= currentDate) && (enteredDate >= 20000101))
        return true;
    else
    {
        cout << "Incorrect date. Try again." << endl;
        return false;
    }
}

bool FinanceManager::checkNumberOfDaysInMonth(int day, int month, int year)
{
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
    {
        if ((day >= 1) && (day <= 31))
            return true;
    }
    else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
    {
        if ((day >= 1) && (day <= 30))
            return true;
    }
    else if (month == 2)
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {
            if ((day >= 1) && (day <= 29))
                return true;
        }
        else
        {
            if ((day >= 1) && (day <= 28))
                return true;
        }
    }
    return false;
}

string FinanceManager::replaceCommaWithDot(string text)
{
    if (!text.empty())
    {
        for (size_t i = 0; i < text.length(); i++)
        {
            if (text[i] == ',')
                text.replace(i, 1, ".");
        }
    }
    return text;
}

int FinanceManager::mergeDateWithoutDashes(string date)
{
    string mergedDate = "";

    mergedDate = readYear(date) + readMonth(date) + readDay(date);

    return ConversionMethods::convertStringToInt(mergedDate);
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
