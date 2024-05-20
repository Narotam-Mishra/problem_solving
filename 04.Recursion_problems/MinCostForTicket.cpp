
// Problem link - https://leetcode.com/problems/minimum-cost-for-tickets/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> costsArr;
vector<int> daysArr;
vector<int> dp;
unordered_set<int> s;
int lastDay;

int findMinimumCostRecursive(int day){
    // base case1: if 'd'th day is greater than last day of days array
    if(day > daysArr[daysArr.size() - 1]) return 0;

    // Recursive case: if dth day doesn't exist in set 
    if(s.find(day) == s.end()) return findMinimumCostRecursive(day+1);

    // recursively calculate minimim cost: f(day) = min(costs[0]+f(d+1), costs[1]+f(d+8), costs[2]+f(d+30))
    int ans = min(costsArr[0]+findMinimumCostRecursive(day+1), min(costsArr[1]+findMinimumCostRecursive(day+7), costsArr[2]+findMinimumCostRecursive(day+30)));

    return ans;
}

int findMinimumCostBottomUpDP(){
    dp.assign(400, 0);
    for (int day = 365; day >= 0; day--){
        // base case1: if 'd'th day is greater than last day of days array
        if (day > lastDay) dp[day] = 0;

        // Recursive case: if dth day doesn't exist in set
        if (s.find(day) == s.end()) dp[day] = dp[day + 1];

        else{
            int ans = min(costsArr[0]+dp[day + 1], min(costsArr[1]+dp[day + 7], costsArr[2]+ dp[day + 30]));
            dp[day] = ans;
        }
    }
    return dp[1];
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    for(int day : days){
        s.insert(day);
    }
    costsArr = costs;
    daysArr = days;
    lastDay = daysArr[daysArr.size() - 1];
    return findMinimumCostBottomUpDP();
    // return findMinimumCostRecursive(days[0]);
}

int main(){
    // vector<int> days = {1,4,6,7,8,20};
    // vector<int> costs = {2,7,15};

    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs = {2,7,15};

    cout<<mincostTickets(days, costs)<<endl;
    return 0;
}