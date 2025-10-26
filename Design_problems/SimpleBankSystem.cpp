
// Problem link - https://leetcode.com/problems/simple-bank-system/?envType=daily-question&envId=2025-10-26

#include<bits/stdc++.h>
using namespace std;

class Bank {
public:
    vector<long long> bal;
    int n;
    Bank(vector<long long>& balance) {
        n = balance.size();
        this->bal = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > n || account2 > n || bal[account1 - 1] < money){
            return false;
        }

        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > n) return false;
        bal[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n || bal[account - 1] < money) return false;
        bal[account - 1] -= money;
        return true;
    }
};

int main(){
    // Test case
    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank* bank = new Bank(balance);
    
    cout << "Initial balances: ";
    for(int i = 0; i < balance.size(); i++) {
        cout << bank->bal[i] << " ";
    }
    cout << endl << endl;
    
    // Test withdraw
    cout << "Withdraw 10 from account 3: " << (bank->withdraw(3, 10) ? "Success" : "Failed") << endl;
    cout << "Balance of account 3: " << bank->bal[2] << endl << endl;
    
    // Test transfer
    cout << "Transfer 5 from account 1 to account 2: " << (bank->transfer(1, 2, 5) ? "Success" : "Failed") << endl;
    cout << "Balance of account 1: " << bank->bal[0] << endl;
    cout << "Balance of account 2: " << bank->bal[1] << endl << endl;
    
    // Test deposit
    cout << "Deposit 20 into account 5: " << (bank->deposit(5, 20) ? "Success" : "Failed") << endl;
    cout << "Balance of account 5: " << bank->bal[4] << endl << endl;
    
    // Test invalid operations
    cout << "Withdraw 50 from account 1 (insufficient funds): " << (bank->withdraw(1, 50) ? "Success" : "Failed") << endl;
    cout << "Transfer to account 10 (invalid account): " << (bank->transfer(1, 10, 5) ? "Success" : "Failed") << endl;
    
    delete bank;
    return 0;
}