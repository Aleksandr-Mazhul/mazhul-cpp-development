#include "BankAccount.h"
#include <cmath>
#include <stdexcept>
#include <string>
#include <ostream>


BankAccount::BankAccount(const std::string &ownerName, double initialDeposit)
    : ownerName(ownerName), balance(initialDeposit), accountNumber(generateAccountNumber()) {

    validateEmptyString(ownerName,"BankAccount: owner name cannot be empty");
    validateAmountPositive(initialDeposit,"BankAccount: initial deposit cannot be positive");

    accountCount++;
}

BankAccount::BankAccount(const std::string &ownerName) : BankAccount(ownerName, 0.0) {}

int BankAccount::getAccountCount() {
    return accountCount;
}

const std::string &BankAccount::getOwnerName() const {
    return ownerName;
}

void BankAccount::deposit(const double amount) {
    validateAmountPositive(amount,"BankAccount: deposit cannot be positive");

    validateAmountFinite(amount ,"BankAccount: amount cannot be finite");

    balance += amount;
}

void BankAccount::withdraw(const double amount) {
    validateAmountPositive(amount,"BankAccount: amount must be positive and not exceed the current balance");

    if (amount > balance) {
        throw std::invalid_argument("BankAccount: amount must be lower than balance");
    }

    validateAmountFinite(amount ,"BankAccount: amount cannot be finite");

    balance -= amount;
}

void BankAccount::transfer(BankAccount &targetAccount, const double amount) {
    if (this ==  &targetAccount) {
        throw std::logic_error("BankAccount: cannot transfer to the given account");
    }
    validateAmountPositive(amount, "BankAccount: amount cannot be negative");
    validateAmountFinite(amount, "BankAccount: amount cannot be finite");

    withdraw(amount);
    try {
        targetAccount.deposit(amount);
    } catch (const std::exception &ex) {
        deposit(amount);
    }
}

double BankAccount::getBalance() const {
    return balance;
}

const Operation *BankAccount::getOperation(size_t i) const {
    if (i >= historySize) {
        return nullptr;
    }
    return &history[i];
}

std::string BankAccount::generateAccountNumber() {
    static int nextAccountNumber = 1000;
    return "BANK-" + std::to_string(nextAccountNumber++);
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

void BankAccount::validateEmptyString(const std::string& name, const std::string& message) {
    if (name.empty())
    {
        throw std::invalid_argument(message);
    }
}

void BankAccount::validateAmountPositive(double value, const std::string& message) {
    if (value < 0) {
        throw std::invalid_argument(message);
    }
}

void BankAccount::validateAmountFinite(double value, const std::string& message) {
    if (!std::isfinite(value)) {
        throw std::invalid_argument(message);
    }
}

std::ostream& operator<< (std::ostream& os, const BankAccount& account) {
    return os << "[#"
    << account.getAccountNumber() << ", "
    << account.getOwnerName() << ", "
    << account.getBalance() << "]"
    << std::endl;
}

std::ostream& operator<< (std::ostream& os, const OperationType& operation) {
    switch (operation) {
        case OperationType::Deposit: os << "Deposit"; break;
            case OperationType::Withdraw: os << "Withdraw"; break;
            case OperationType::TransferIn: os << "TransferIn"; break;
            case OperationType::TransferOut: os << "TransferOut"; break;
    }
    return os;
}

std::ostream& operator<< (std::ostream& os, const Operation& operation) {
    return os << "Operation type: " << operation.type << ", amount: " << operation.amount << ", date: " << operation.date << std::endl;
}
