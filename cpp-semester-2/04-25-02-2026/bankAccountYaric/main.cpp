#include <iostream>
#include "BankAccount.cpp"
#include "BankAccount.h"

using namespace std;


static void printMenu()
{
    std::cout << "\n--- Menu ---\n"
              << "1. Open account\n"
              << "2. Deposit\n"
              << "3. Withdraw\n"
              << "4. Transfer between accounts\n"
              << "5. Balance by account number\n"
              << "6. Show account (details and history)\n"
              << "7. Show all accounts\n"
              << "0. Exit\n"
              << "Choice: ";
}

// int main()
// {
//     BankService bank;
//
//     // Initial set of accounts for demo
//     std::string idAlice = bank.openAccount("Alice", 100.0);
//     std::string idBob = bank.openAccount("Bob", 50.0);
//     std::string idCarol = bank.openAccount("Carol", 200.0);
//     std::string idDave = bank.openAccount("Dave", 75.0);
//     std::string idEve = bank.openAccount("Eve", 150.0);
//     std::cout << "Demo accounts created. IDs: Alice=" << idAlice << ", Bob=" << idBob << ", Carol=" << idCarol
//               << ", Dave=" << idDave << ", Eve=" << idEve << std::endl;
//
//     int choice = -1;
//     while (choice != 0)
//     {
//         printMenu();
//         std::cin >> choice;
//         if (std::cin.fail())
//         {
//             std::cin.clear();
//             std::cin.ignore(10000, '\n');
//             std::cout << "Enter a menu option number.\n";
//             continue;
//         }
//
//         try
//         {
//             switch (choice)
//             {
//             case 1: {
//                 std::string name;
//                 double deposit = 0;
//                 std::cout << "Owner name: ";
//                 std::cin >> name;
//                 std::cout << "Initial deposit: ";
//                 std::cin >> deposit;
//                 std::string id = bank.openAccount(name, deposit);
//                 std::cout << "Account opened. Account number: " << id << std::endl;
//                 break;
//             }
//             case 2: {
//                 std::string id;
//                 double amount;
//                 std::cout << "Account number: ";
//                 std::cin >> id;
//                 std::cout << "Deposit amount: ";
//                 std::cin >> amount;
//                 bank.deposit(id, amount);
//                 std::cout << "Deposited. New balance: " << bank.getBalance(id) << std::endl;
//                 break;
//             }
//             case 3: {
//                 std::string id;
//                 double amount;
//                 std::cout << "Account number: ";
//                 std::cin >> id;
//                 std::cout << "Withdrawal amount: ";
//                 std::cin >> amount;
//                 bank.withdraw(id, amount);
//                 std::cout << "Withdrawn. New balance: " << bank.getBalance(id) << std::endl;
//                 break;
//             }
//             case 4: {
//                 std::string fromId, toId;
//                 double amount;
//                 std::cout << "Sender account number: ";
//                 std::cin >> fromId;
//                 std::cout << "Recipient account number: ";
//                 std::cin >> toId;
//                 std::cout << "Transfer amount: ";
//                 std::cin >> amount;
//                 bank.transfer(fromId, toId, amount);
//                 std::cout << "Transfer done. Balances: " << fromId << " = " << bank.getBalance(fromId)
//                           << ", " << toId << " = " << bank.getBalance(toId) << std::endl;
//                 break;
//             }
//             case 5: {
//                 std::string id;
//                 std::cout << "Account number: ";
//                 std::cin >> id;
//                 std::cout << "Balance: " << bank.getBalance(id) << std::endl;
//                 break;
//             }
//             case 6: {
//                 std::string id;
//                 std::cout << "Account number: ";
//                 std::cin >> id;
//                 BankAccount* acc = bank.findById(id);
//                 if (!acc)
//                 {
//                     std::cout << "Account not found.\n";
//                     break;
//                 }
//                 std::cout << *acc << std::endl;
//                 std::cout << "Operation history:\n";
//                 printAccountHistory(*acc);
//                 break;
//             }
//             case 7: {
//                 const size_t n = bank.getAccountCount();
//                 if (n == 0)
//                     std::cout << "No accounts.\n";
//                 else
//                 {
//                     std::cout << "Accounts (" << n << "):\n";
//                     for (size_t i = 0; i < n; ++i)
//                     {
//                         const BankAccount* acc = bank.getAccountAt(i);
//                         if (acc)
//                             std::cout << "  " << *acc << std::endl;
//                     }
//                 }
//                 break;
//             }
//             case 0:
//                 std::cout << "Goodbye.\n";
//                 break;
//             default:
//                 std::cout << "Unknown menu option.\n";
//                 break;
//             }
//         }
//         catch (const std::exception& e)
//         {
//             std::cerr << "Error: " << e.what() << std::endl;
//         }
//     }
//
//     return 0;
// }
int main() {
    cout << "=== TEST 1: Create accounts ===" << endl;

    BankAccount acc1("Alice", 1000.0);
    BankAccount acc2("Bob", 500.0);
    BankAccount acc3("Charlie");

    cout << "Account 1: " << acc1;
    cout << "Account 2: " << acc2;
    cout << "Account 3: " << acc3;

    cout << "\n=== TEST 2: Deposit money ===" << endl;
    cout << "Alice balance before deposit: " << acc1.getBalance() << endl;
    acc1.deposit(500.0);
    cout << "Alice balance after deposit +500: " << acc1.getBalance() << endl;
    cout << acc1;

    cout << "\n=== TEST 3: Withdraw money ===" << endl;
    cout << "Bob balance before withdrawal: " << acc2.getBalance() << endl;
    acc2.withdraw(200.0);
    cout << "Bob balance after withdrawal -200: " << acc2.getBalance() << endl;
    cout << acc2;

    cout << "\n=== TEST 4: Transfer money ===" << endl;
    cout << "Before transfer:" << endl;
    cout << acc1;
    cout << acc2;

    acc1.transfer(acc2, 300.0);

    cout << "After transfer 300 from Alice to Bob:" << endl;
    cout << acc1;
    cout << acc2;

    cout << "\n=== TEST 5: Error handling ===" << endl;

    cout << "Try to withdraw more than balance:" << endl;
    cout << "Bob balance: " << acc2.getBalance() << ", try to withdraw 1000" << endl;
    try {
        acc2.withdraw(1000.0);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nTry to transfer to yourself:" << endl;
    try {
        acc1.transfer(acc1, 100.0);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n=== FINAL ACCOUNT STATUS ===" << endl;
    cout << "Total accounts created: " << BankAccount::getAccountCount() << endl;
    cout << acc1;
    cout << acc2;
    cout << acc3;

    return 0;
}
