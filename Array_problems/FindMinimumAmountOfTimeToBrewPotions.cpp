
// Problem link - https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/?envType=daily-question&envId=2025-10-09

#include<bits/stdc++.h>
using namespace std;

long long minTime(vector<int>& skill, vector<int>& mana) {
    // find the size of skill & mana
    int n = skill.size();
    int m = mana.size();

    // store ith-wizard time taken to finish the potion
    vector<long long> finishTime(n, 0);

    // step 1 - iterate on all potion one by one
    for(int j=0; j<m; j++){
        // step 2 - calculate initial finish time
        finishTime[0] += mana[j] * skill[0];

        // step 3 - iterate on each wizard along the potion
        for(int i=1; i<n; i++){
            finishTime[i] = max(finishTime[i], finishTime[i-1]) + 1LL * mana[j] * skill[i];
        }

        // step 4 - synchronize of time(correct time)
        for(int i=n-1; i>0; i--){
            finishTime[i-1] = finishTime[i] - 1LL * mana[j] * skill[i];
        }
    }

    // step 5 - return minimum time
    return finishTime[n-1];
}

int main(){
    // vector<int> skill = {1,5,2,4};
    // vector<int> mana = {5,1,4,2};

    // vector<int> skill = {1,1,1};
    // vector<int> mana = {1,1,1};

    vector<int> skill = {1,2,3,4};
    vector<int> mana = {1,2};
    cout<<minTime(skill, mana);
    return 0;
} 