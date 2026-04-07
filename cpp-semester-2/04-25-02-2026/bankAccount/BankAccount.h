#pragma once

#include <ctime>
#include <string>

enum class OperationType {
    Deposit,
    Withdraw,
    TransferOut,
    TransferIn,
};

struct Operation {
    OperationType type;
    double amount;
    std::string accountNumber;
    std::time_t date;
};

/**
 * Stub of BankAccount: same public interface as BankAccount.
 * Bank account with owner name and balance; supports deposit, withdraw, and transfer.
 * In this stub, all methods except the constructors are not implemented and throw std::logic_error.
 */
class BankAccount {
public:
    /**
     * Constructs an account with the given owner name and initial deposit.
     * @param ownerName non-empty owner name
     * @param initialDeposit initial balance (must be >= 0)
     * @throws std::invalid_argument if ownerName is empty or initialDeposit is negative
     */
    BankAccount(const std::string &ownerName, double initialDeposit);

    /**
     * Constructs an account with the given owner name and zero initial balance.
     * Delegates to the two-parameter constructor.
     * @param ownerName non-empty owner name
     * @throws std::invalid_argument if ownerName is empty
     */
    BankAccount(const std::string &ownerName);

    /**
     * Returns the total number of accounts created so far (shared across all instances).
     * Not implemented; throws std::logic_error.
     * @throws std::logic_error always
     */
    static int getAccountCount();

    /**
     * Returns the owner name of this account.
     * Not implemented; throws std::logic_error.
     * @throws std::logic_error always
     */
    const std::string &getOwnerName() const;

    /**
     * Adds the given amount to the balance.
     * @param amount must be positive (in the real BankAccount)
     * @throws std::invalid_argument if amount <= 0 (in the real BankAccount)
     * Not implemented; this stub always throws std::logic_error.
     * @throws std::logic_error always
     */
    void deposit(double amount);

    /**
     * Subtracts the given amount from the balance.
     * @param amount must be positive and not exceed the current balance (in the real BankAccount)
     * @throws std::invalid_argument if amount <= 0 (in the real BankAccount)
     * @throws std::runtime_error if amount > balance (insufficient funds) (in the real BankAccount)
     * Not implemented; this stub always throws std::logic_error.
     * @throws std::logic_error always
     */
    void withdraw(double amount);

    /**
     * Transfers the given amount from this account to targetAccount.
     * On failure of the credit step, the debit is rolled back (in the real BankAccount).
     * @param targetAccount the account to credit (must not be this account in the real BankAccount)
     * @param amount must be positive and not exceed the current balance (in the real BankAccount)
     * @throws std::invalid_argument if amount <= 0 (in the real BankAccount)
     * @throws std::logic_error if targetAccount is this account (in the real BankAccount)
     * @throws std::runtime_error if amount > balance (insufficient funds) (in the real BankAccount)
     * Not implemented; this stub always throws std::logic_error.
     * @throws std::logic_error always
     */
    void transfer(BankAccount &targetAccount, double amount);

    /**
     * Returns the current balance.
     * Not implemented; throws std::logic_error.
     * @throws std::logic_error always
     */
    double getBalance() const;

    std::string getAccountNumber() const;

    const Operation *getOperation(size_t i) const;

    std::string

private:
    static void validateEmptyString(const std::string &name, const std::string &message);
    static void validateAmountPositive(double value, const std::string &message);
    static void validateAmountFinite(double value, const std::string &message);
    static std::string generateAccountNumber();

    inline static int accountCount{0};
    static constexpr int maxHistoryOperation{100};

    std::string ownerName;
    double balance;
    std::string accountNumber;
    int historySize{0};
    Operation history[maxHistoryOperation];
};
