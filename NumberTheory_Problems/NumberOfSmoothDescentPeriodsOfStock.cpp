
// Problem link -  https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/?envType=daily-question&envId=2025-12-15

#include <bits/stdc++.h>
using namespace std;

long long getDescentPeriods(vector<int>& prices) {
    int n = prices.size();
    
    // step 1 - find all the descent periods
    long long count = 1, res = 1;
    for(int i = 1; i < n; i++){
        // step 2 - check if the current price is one less than the previous price
        if(prices[i] == prices[i-1] - 1){
            count++;
        } else {
            // step 3 - if not, add the count of the previous descent period to the result
            // and reset the count
            count = 1;
        }

        // step 4 - add the count of the current descent period to the result
        res += count;
    }

    // step 5 - return the result
    return res;
}

int main(){
    // vector<int> prices = {3,2,1,4};

    // vector<int> prices = {8,6,7,7};

    vector<int> prices = {1};
    cout<<getDescentPeriods(prices);
    return 0;
}