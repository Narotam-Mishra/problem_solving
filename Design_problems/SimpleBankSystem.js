
// Problem link - https://leetcode.com/problems/simple-bank-system/description/?envType=daily-question&envId=2025-10-26

/**
 * @param {number[]} balance
 */
let Bank = function(balance) {
    this.bal = [...balance];
    this.n = balance.length;
};

/** 
 * @param {number} account1 
 * @param {number} account2 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.transfer = function(account1, account2, money) {
    if(account1 > this.n || account2 > this.n || this.bal[account1 - 1] < money) {
        return false;
    }
    this.bal[account1 - 1] -= money;
    this.bal[account2 - 1] += money;
    return true;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.deposit = function(account, money) {
    if(account > this.n) return false;
    this.bal[account - 1] += money;
    return true;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.withdraw = function(account, money) {
    if(account > this.n || this.bal[account - 1] < money) return false;
    this.bal[account - 1] -= money;
    return true;
};

// Main runner for testing
function main() {
    const balance = [10, 100, 20, 50, 30];
    const bank = new Bank(balance);
    
    console.log("Initial balances:", bank.bal.join(" "), "\n");
    
    // Test withdraw
    console.log("Withdraw 10 from account 3:", bank.withdraw(3, 10) ? "Success" : "Failed");
    console.log("Balance of account 3:", bank.bal[2], "\n");
    
    // Test transfer
    console.log("Transfer 5 from account 1 to account 2:", bank.transfer(1, 2, 5) ? "Success" : "Failed");
    console.log("Balance of account 1:", bank.bal[0]);
    console.log("Balance of account 2:", bank.bal[1], "\n");
    
    // Test deposit
    console.log("Deposit 20 into account 5:", bank.deposit(5, 20) ? "Success" : "Failed");
    console.log("Balance of account 5:", bank.bal[4], "\n");
    
    // Test invalid operations
    console.log("Withdraw 50 from account 1 (insufficient funds):", bank.withdraw(1, 50) ? "Success" : "Failed");
    console.log("Transfer to account 10 (invalid account):", bank.transfer(1, 10, 5) ? "Success" : "Failed");
}

// runner method
main();