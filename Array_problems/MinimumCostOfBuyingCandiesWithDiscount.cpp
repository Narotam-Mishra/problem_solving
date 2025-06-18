
// Problem link - https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

#include<bits/stdc++.h>
using namespace std;

int minimumCost(vector<int>& cost) {
    // store minimum cost of all candies in `minCost`
    int minCost = 0;
    int n = cost.size();

    // step 1 - sort the candies in desending order to get most expensive first
    // this ensures we buy the most expensive candies and get cheaper ones free
    sort(cost.rbegin(), cost.rend());

    // step 2 - process candies in groups of 3
    // for every 3 candies: buy 2 most expensive, get 1 cheapest free
    for (int i = 0; i < n; i += 3) {

        // step 3 - buy the first candy in the group (most expensive)
        minCost += cost[i];

        // step 4 - buy the second candy in the group if it exists
        if (i + 1 < n) {
            minCost += cost[i + 1];
        }
    }

    // step 5 - return minimum cost of all candies in `minCost`
    return minCost;
}

int main(){
    // vector<int> cost = {1,2,3};

    // vector<int> cost = {6,5,7,9,2,2};

    vector<int> cost = {5,5};
    cout<<minimumCost(cost);
    return 0;
}