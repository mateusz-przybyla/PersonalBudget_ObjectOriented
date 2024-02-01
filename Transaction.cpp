#include "Transaction.h"

void Transaction::setTransactionId(int newTransactionId)
{
    if (transactionId >= 0)
        transactionId = newTransactionId;
}

void Transaction::setUserId(int newUserId)
{
    if (userId >= 0)
        userId = newUserId;
}

void Transaction::setDate(int newDate)
{
    date = newDate;
}

void Transaction::setItem(string newItem)
{
    item = newItem;
}

void Transaction::setAmount(double newAmount)
{
    amount = newAmount;
}

int Transaction::getTransactionId()
{
    return transactionId;
}

int Transaction::getUserId()
{
    return userId;
}

int Transaction::getDate()
{
    return date;
}

string Transaction::getItem()
{
    return item;
}

double Transaction::getAmount()
{
    return amount;
}
