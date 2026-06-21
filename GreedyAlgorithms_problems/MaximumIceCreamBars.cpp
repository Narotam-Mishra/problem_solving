
// Problem link - https://leetcode.com/problems/maximum-ice-cream-bars/description/?envType=daily-question&envId=2026-06-21

#include<bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    // step 1 - sort costs in non-decreasing order
    // to buy cheaper bars first maximizes the number of bars
    sort(costs.begin(), costs.end());

    // maxCount: keep track of number of bars bought so far
    int maxCount = 0;

    // step 2 - iterate over sorted costs and buy while we have enough coins
    for (int cost : costs) {
        // step 3 - check if current cost cannot be afforded, no further (more expensive)
        if (cost > coins) {
            return maxCount;
        }

        // step 4 - otherwise, purchase this bar and decrement coins
        maxCount++;
        coins -= cost;
    }

    // step 5 - all bars were affordable; return total purchased
    return maxCount;
}

int main(){
    // vector<int> costs = {1,3,2,4,1};
    // int coins = 7;

    vector<int> costs = {10,6,8,7,7,8};
    int coins = 5;

    // vector<int> costs = {1,6,3,1,2,5};
    // int coins = 20;
    cout<<maxIceCream(costs, coins);
    return 0;
}