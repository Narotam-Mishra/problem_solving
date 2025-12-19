
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/

#include<bits/stdc++.h>
using namespace std;

// for memoization
long long memo[1001][501][3];

// Case:
// 0 - fresh transaction - you have not bought anything and you have not short-sold anything
// 1 - Normal transaction - you have bought a stock and you need to sell it later
// 2 - Short sell transaction - you have short-sold a stock and you need to buy it later

long long solveRec(int i, int k, int c, vector<int>& prices){
    // base case: no more transactions left or no more days left
    if(i >= prices.size()){
        if(c == 0) return 0;

        // unfinished transaction: transaction is invalid
        return INT_MIN;
    }

    // memoization check
    if(memo[i][k][c] != -1){
        return memo[i][k][c];
    }

    // recursive case: 
    long long skip = solveRec(i+1, k, c, prices);
    long long take = INT_MIN;
    if(k > 0){
        if(c == 1){
            // normal transaction
            take = prices[i] + solveRec(i+1, k-1, 0, prices);
        }else if(c == 2){
            // short sell, you have to buy later
            take = -prices[i] + solveRec(i+1, k-1, 0, prices);
            
        }else{
            // fresh transaction: buy-sell or short sell-buy
            take = max(
                -prices[i] + solveRec(i+1, k, 1, prices), // buy-sell (normal transaction)
                prices[i] + solveRec(i+1, k, 2, prices) // short sell-buy
            );
        }
    }

    return memo[i][k][c] = max(skip, take);
}

long long maximumProfit(vector<int>& prices, int k) {
    int n = prices.size();

    // reset memoization array
    memset(memo, -1, sizeof(memo));

    return solveRec(0, k, 0, prices);
}

int main(){
    // vector<int> prices = {1,7,9,8,2};
    // int k = 2;

    vector<int> prices = {12,16,19,19,8,1,19,13,9};
    int k = 3;
    cout<<maximumProfit(prices, k);
    return 0;
}