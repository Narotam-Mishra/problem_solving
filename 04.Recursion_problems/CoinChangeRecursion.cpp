
// Problem link - https://leetcode.com/problems/coin-change/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> c;
int maxVal = numeric_limits<int>::max();

int coinChangeRecursion(int amount){
    // Base case: if amount is negative or 0
    if(amount < 0) return maxVal;
    if(amount == 0) return 0;

    int ans = maxVal;
    int n = c.size();

    // Recursive case f(amount) = 1 + min(f(amount - coins[i]))
    for (int i = 0; i < n; i++){
        if(amount >= c[i]){
            ans = min(ans, coinChangeRecursion(amount - c[i]));
        }
    }

    // if ans is still infinity then coinChange is not possible
    if(ans == maxVal) return maxVal;

    return 1 + ans;
    
}
int coinChange(vector<int>& coins, int amount) {
    c = coins;
    int minCoins = coinChangeRecursion(amount);
    return minCoins == maxVal ? -1 : minCoins;
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    int ans = coinChange(coins, amount);
    cout<<ans<<endl;
    return 0;
}