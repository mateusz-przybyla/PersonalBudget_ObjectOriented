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

string DateOperations::splitDateByDashes(int date)
{
    string mergedDate = ConversionMethods::convertIntToString(date);
    string splitedDate = "";

    for (size_t i = 0; i < mergedDate.length(); i++)
    {
        splitedDate += mergedDate[i];

        if ((i == 3) || (i == 5))
            splitedDate += '-';
    }
    return splitedDate;
}

string DateOperations::readStartDate(char choice)
{
    string currentDate = "", startDate = "";
    currentDate = readTodaysDate();

    switch (choice)
    {
    case '1':
        startDate = currentDate;
        startDate.replace(8, 2, "01");
        break;
    case '2':
        startDate = currentDate;
        startDate.replace(8, 2, "01");
        startDate.replace(5, 2, readPreviousMonth(currentDate));
        startDate.replace(0, 4, checkPreviousYear(currentDate));
        break;
    case '3':
        do
        {
            cout << endl << "Enter start date in YYYY-MM-DD format: ";
            startDate = InputMethods::readLine();
        } while (!checkIfEnteredDateIsCorrect(startDate));
        break;
    }
    return startDate;
}

string DateOperations::readEndDate(char choice)
{
    string currentDate = "", endDate = "";
    currentDate = readTodaysDate();

    switch (choice)
    {
    case '1':
        endDate = currentDate;
        break;
    case '2':
        endDate = currentDate;
        endDate.replace(8, 2, calculateHowManyDaysPerPreviousMonth(currentDate));
        endDate.replace(5, 2, readPreviousMonth(currentDate));
        endDate.replace(0, 4, checkPreviousYear(currentDate));
        break;
    case '3':
        do
        {
            cout << "Enter end date in YYYY-MM-DD format: ";
            endDate = InputMethods::readLine();
        } while (!checkIfEnteredDateIsCorrect(endDate));
        break;
    }
    return endDate;
}

string DateOperations::readPreviousMonth(string date)
{
    string month = "";
    string monthsTable[12] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};

    month = readMonth(date);

    for (int i = 0; i < 12; i++)
    {
        if (month == monthsTable[0])
        {
            month = monthsTable[11];
            break;
        }
        else if (month == monthsTable[i])
        {
            month =  monthsTable[i - 1];
            break;
        }
    }
    return month;
}

string DateOperations::checkPreviousYear(string date)
{
    int month = 0, year = 0;
    month = ConversionMethods::convertStringToInt(readMonth(date));
    year = ConversionMethods::convertStringToInt(readYear(date));

    if (month == 1)
        year -= 1;

    return ConversionMethods::convertIntToString(year);
}

string DateOperations::calculateHowManyDaysPerPreviousMonth(string date)
{
    int days = 0, month = 0, year = 0;
    month = ConversionMethods::convertStringToInt(readPreviousMonth(date));
    year = ConversionMethods::convertStringToInt(readYear(date));

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        days = 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else if (month == 2)
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            days = 29;
        else
            days = 28;
    }
    return ConversionMethods::convertIntToString(days);
}

void DateOperations::checkOrderOfEnteredDates(string &startDate, string &endDate)
{
    int startDateInt = 0, endDateInt = 0;
    string helper = "";

    startDateInt = mergeDateWithoutDashes(startDate);
    endDateInt = mergeDateWithoutDashes(endDate);

    if (startDateInt > endDateInt)
    {
        helper = startDate;
        startDate = endDate;
        endDate = helper;
    }
}
