
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

// Approach - Using Recursion

#include<bits/stdc++.h>
using namespace std;

vector<int> pArr;

int findMaxProfitRec(int i, bool ts, int k){
    // Base case: all days are completed
    if(i == pArr.size()) return 0;

    int ans = -1;

    // Recursive case:
    // Case 1: Ignore stock
    ans = max(ans, findMaxProfitRec(i+1, ts, k));

    // Case 2: Buy the stock on ith day
    if(k > 0 && ts == false){
        ans = max(ans, -pArr[i] + findMaxProfitRec(i+1, true, k));
    }

    // Case 3: sell the stock on ith day
    if(ts == true){
        ans = max(ans, pArr[i] + findMaxProfitRec(i+1, false, k-1));
    }

    return ans;
}

int maxProfit(int k, vector<int>& prices) {
    pArr = prices;
    return findMaxProfitRec(0, false, k);
}

int main(){
    int k = 2;
    vector<int> prices = {3,2,6,5,0,3};
    cout<<maxProfit(k, prices)<<endl;
    return 0;
}