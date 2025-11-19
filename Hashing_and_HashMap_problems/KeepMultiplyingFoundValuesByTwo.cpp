
// Problem link - - [2154. Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two/?envType=daily-question&envId=2025-11-19)

#include<bits/stdc++.h>
using namespace std;

int findFinalValue(vector<int>& nums, int original) {
    // step 1 - store all elements of `nums` in set for better lookup
    unordered_set<int> set(nums.begin(), nums.end());

    // step 2 - keep searching `original` till it exists in set
    while (set.find(original) != set.end()) {
        // step 3 - double it each time when it is found
        original = 2 * original;
    }

    // step 4 - return `original` when it is not found
    return original;
}


int main(){
    vector<int> nums = {5,3,6,1,12};
    int original = 3;
    cout<<findFinalValue(nums, original);
    return 0;
}