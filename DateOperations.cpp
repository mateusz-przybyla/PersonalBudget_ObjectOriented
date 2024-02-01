#include "DateOperations.h"

int DateOperations::readSelectedTransactionDate()
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

string DateOperations::readTodaysDate()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream ss;
    ss << put_time(localTime, "%Y-%m-%d");

    return ss.str();
}

string DateOperations::readDay(string date)
{
    int position = date.find_last_of('-') + 1;
    string day = AuxiliaryMethods::readNumber(date, position);

    return day;
}

string DateOperations::readMonth(string date)
{
    int position = date.find_first_of('-') + 1;
    string month = AuxiliaryMethods::readNumber(date, position);

    return month;
}

string DateOperations::readYear(string date)
{
    int position = 0;
    string year = AuxiliaryMethods::readNumber(date, position);

    return year;
}

bool DateOperations::checkIfEnteredDateIsCorrect(string date)
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

bool DateOperations::checkNumberOfDaysInMonth(int day, int month, int year)
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

int DateOperations::mergeDateWithoutDashes(string date)
{
    string mergedDate = "";

    mergedDate = readYear(date) + readMonth(date) + readDay(date);

    return ConversionMethods::convertStringToInt(mergedDate);
}
