#include <iostream>
#include <stdexcept>

#include "BankAccount.cpp"

using namespace std;

int main()
{
    double num;

    while (true)
    {
        cin >> num;

        if (num > 0)
        {
            break;
        }
    }

    try
    {
        BankAccount acc("Alice", num);
        BankAccount acc1("jac", num);
        BankAccount acc2("john", num);

        acc1.deposit(300.0);

        cout << acc1.getAccountCount() << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << '\n';
    }

    return 0;
}