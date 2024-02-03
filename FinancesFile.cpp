#include "FinancesFile.h"

vector <Transaction> FinancesFile::loadIncomesFromFile(int loggedInUserId)
{
    vector <Transaction> incomes;
    bool fileExist = xml.Load(INCOMES_FILENAME);

    if (fileExist)
    {
        while (xml.FindElem("incomes"))
        {
            xml.IntoElem();
            while (xml.FindElem("income"))
            {
                xml.IntoElem();
                xml.FindElem("userId");
                if (ConversionMethods::convertStringToInt(xml.GetData()) == loggedInUserId)
                {
                    Transaction income;

                    xml.ResetMainPos();
                    xml.FindElem("incomeId");
                    income.setTransactionId(ConversionMethods::convertStringToInt(xml.GetData()));
                    xml.FindElem("userId");
                    income.setUserId(ConversionMethods::convertStringToInt(xml.GetData()));
                    xml.FindElem("date");
                    income.setDate(ConversionMethods::convertStringToInt(xml.GetData()));
                    xml.FindElem("item");
                    income.setItem(xml.GetData());
                    xml.FindElem("amount");
                    income.setAmount(ConversionMethods::convertStringToDouble(xml.GetData()) / 100);

                    incomes.push_back(income);
                    lastIncomeId = income.getTransactionId();
                }
                xml.OutOfElem();
            }
        }
    }
    return incomes;
}

bool FinancesFile::writeNewIncomeInFile(Transaction income)
{
    bool fileExist = xml.Load(INCOMES_FILENAME);

    if (!fileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getTransactionId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", income.getDate());
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount() * 100);

    if (xml.Save(INCOMES_FILENAME))
        return true;
    else
        return false;
}
