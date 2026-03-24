#include "BankAccount.h"
#include <ostream>
#include <cmath>
#include <stdexcept>

using namespace std;

int BankAccount::count = 0;

BankAccount::BankAccount(const std::string& ownerName, double initialDeposit)
    : ownerName(ownerName)
    , balance(initialDeposit)
    ,history{}
    ,accountNumber(generateAccountNumber(ownerName))
{
    ValidateEmptyString(ownerName, "BankAccount cant be empty");
    validateAmountPositive(initialDeposit, "Initial deposit cannot be negative");

    count++;

}

BankAccount::BankAccount(const std::string& ownerName)
    : BankAccount(ownerName, 0.0)
{
}

int BankAccount::getAccountCount()
{
    return count;
}

const std::string& BankAccount::getOwnerName() const
{
    return ownerName;
}

const std::string& BankAccount::getAccountNumber() const
{
    return accountNumber;
}

void BankAccount::deposit(double amount)
{
    validateAmountPositive(amount, "Amount cannot be negative");
    isAmountInfinite(amount, "Amount must be finite");

    balance += amount;

    addToHistory(OperationType::Deposit, amount, "");
}

void BankAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        throw invalid_argument("withdraw amount must be positive");
    }

    isAmountInfinite(amount, "Cant be infinite");

    if (amount > balance)
    {
        throw runtime_error("insufficient funds");
    }

    balance -= amount;

    addToHistory(OperationType::Withdraw, amount, "");
}

void BankAccount::transfer(BankAccount& targetAccount, double amount)
{
    if (this == &targetAccount)
    {
        throw logic_error("cannot transfer to the same account");
    }

    validateAmountPositive(amount, "Amount must be positive");
    isAmountInfinite(amount, "Amount must be finite");

    if (amount > balance)
    {
        throw runtime_error("insufficient funds");
    }

    balance -= amount;
    targetAccount.balance += amount;

    addToHistory(OperationType::TransferOut, amount, targetAccount.ownerName);
    targetAccount.addToHistory(OperationType::TransferIn, amount, ownerName);
}

double BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::addToHistory(OperationType type, double amount, const std::string& accountNumber)
{
    if (historySize >= 100)
    {
        return;
    }
    Operation operation;

    operation.type = type;
    operation.amount = amount;
    operation.accountNumber = accountNumber;
    operation.date = std::time(nullptr);

    history[historySize] = operation;

    historySize++;
}

size_t BankAccount::getHistorySize() const
{
    return historySize;
}

const Operation* BankAccount::getOperation(size_t i) const
{
    if (i >= historySize)
    {
        return nullptr;
    }

    return &history[i];
}

std::string BankAccount::generateAccountNumber(std::string accountNumber)
{
    return accountNumber.substr(0, 3) + to_string(BankId + count);
}

void BankAccount::ValidateEmptyString(const string& name, const string& message)
{
    if (name.empty())
    {
        throw invalid_argument(message);
    }
}

void BankAccount::validateAmountPositive(double value, const string& message)
{
    if (value < 0)
    {
        throw invalid_argument(message);
    }
}

void BankAccount::isAmountInfinite(double amount, const string& message)
{
    if (!std::isfinite(amount))
    {
        throw invalid_argument(message);
    }
}



std::ostream& operator << (std::ostream& os, const BankAccount& account)
{
    return os <<  "[#"  << account.getAccountNumber() << ", " << account.getOwnerName()<< ", " << account.getBalance()<< "$" << "]" <<endl;
}


std::ostream& operator << (std::ostream& os, const OperationType& operation)
{
    switch (operation)
    {
        case OperationType::Deposit: os << "Deposit"; break;
        case OperationType::Withdraw: os << "Withdraw"; break;
        case OperationType::TransferOut: os << "TransferOut"; break;
        case OperationType::TransferIn: os << "TransferIn"; break;
    }
    return os;
}

std::ostream& operator << (std::ostream& os, const Operation& operation)
{
    return os <<  "OperationType: "  << operation.type << ", amount" << operation.amount<< ", date" << operation.date <<endl;
}

