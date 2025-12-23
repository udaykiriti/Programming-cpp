#include <bits/stdc++.h>
using namespace std;

class BankAccount {
    double balance;

public:
    BankAccount(double initialBalance) {
        if (initialBalance < 0)
            throw invalid_argument("Initial balance cannot be negative.");
        balance = initialBalance;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Withdrawal amount must be positive.");
        if (amount > balance)
            throw runtime_error("Insufficient balance.");
        balance -= amount;
        cout << "Withdrawal successful. New balance: " << balance << endl;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    try {
        BankAccount myAccount(5000);
        myAccount.withdraw(1000);
        myAccount.withdraw(10000);        
    }
    catch (const invalid_argument& e) {
        cout << "Invalid input error: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Runtime error: " << e.what() << endl;
    }
    return 0;
}
