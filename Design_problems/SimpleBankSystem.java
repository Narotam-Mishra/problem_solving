
// Problem link - https://leetcode.com/problems/simple-bank-system/?envType=daily-question&envId=2025-10-26

package Design_problems;

public class SimpleBankSystem {
    static class Bank {
        private long[] bal;
        private int n;

        public Bank(long[] balance) {
            this.n = balance.length;
            this.bal = balance.clone();
        }

        public boolean transfer(int account1, int account2, long money) {
            if(account1 > n || account2 > n || bal[account1 - 1] < money){
                return false;
            }
            bal[account1 - 1] -= money;
            bal[account2 - 1] += money;
            return true;
        }

        public boolean deposit(int account, long money) {
            if(account > n) return false;
            bal[account - 1] += money;
            return true;
        }

        public boolean withdraw(int account, long money) {
            if(account > n || bal[account - 1] < money){
                return false;
            }
            bal[account - 1] -= money;
            return true;
        }
    }

    public static void main(String[] args) {
        long[] balance = {10, 100, 20, 50, 30};
        Bank bank = new Bank(balance);
        
        System.out.print("Initial balances: ");
        for(long b : bank.bal) {
            System.out.print(b + " ");
        }
        System.out.println("\n");
        
        // Test withdraw
        System.out.println("Withdraw 10 from account 3: " + (bank.withdraw(3, 10) ? "Success" : "Failed"));
        System.out.println("Balance of account 3: " + bank.bal[2] + "\n");
        
        // Test transfer
        System.out.println("Transfer 5 from account 1 to account 2: " + (bank.transfer(1, 2, 5) ? "Success" : "Failed"));
        System.out.println("Balance of account 1: " + bank.bal[0]);
        System.out.println("Balance of account 2: " + bank.bal[1] + "\n");
        
        // Test deposit
        System.out.println("Deposit 20 into account 5: " + (bank.deposit(5, 20) ? "Success" : "Failed"));
        System.out.println("Balance of account 5: " + bank.bal[4] + "\n");
        
        // Test invalid operations
        System.out.println("Withdraw 50 from account 1 (insufficient funds): " + (bank.withdraw(1, 50) ? "Success" : "Failed"));
        System.out.println("Transfer to account 10 (invalid account): " + (bank.transfer(1, 10, 5) ? "Success" : "Failed"));
    }
}