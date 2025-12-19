
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/description/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// using sliding window approach
ll maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    // step 1 - find profit for each price and strategy using profit array
    int n = prices.size();
    ll actualProfit = 0;
    vector<ll> profit(n, 0);
    for(int i=0; i<n; i++){
        profit[i] = (ll)prices[i] * strategy[i];
        actualProfit += profit[i];
    }

    // keep track of original window profit
    ll originalWindowProfit = 0;

    // keep track of modified window profit (half array's prices sum)
    ll modifiedWindowProfit = 0;

    // keep track of maximum possible profit
    ll maxGain = 0;

    // using sliding window approach
    int i = 0, j = 0;
    while(j < n){
        originalWindowProfit += profit[j];

        // step 2 - find modified window profit using second half of window
        if(j - i + 1 > k/2){
            modifiedWindowProfit += prices[j];
        }

        // check if window size exceed `k`
        if(j - i + 1 > k){
            // shrink window
            originalWindowProfit -= profit[i];
            modifiedWindowProfit -= prices[i + k/2];
            i++;
        }

        // step 3 - find maximum profit in window of size `k`
        if(j - i + 1 == k){
            maxGain = max(maxGain, modifiedWindowProfit - originalWindowProfit);
        }

        // move to next window
        j++;
    }

    // step 4 - return maximum profit
    return actualProfit + maxGain;
}

int main() {
    // vector<int> prices = {4,2,8};
    // vector<int> strategy = {-1,0,1};
    // int k = 2;

    vector<int> prices = {5,4,3};
    vector<int> strategy = {1,1,0};
    int k = 2;

    cout << maxProfit(prices, strategy, k) << endl;
    return 0;
}