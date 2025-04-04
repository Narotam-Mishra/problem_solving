
// Problem link - https://leetcode.com/problems/jump-game/

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    // step 1 - track the farthest index that we can reach
    int maxReach = 0;

    for (int i = 0; i < nums.size(); i++) {
        // step 2 - if we are struck before reaching this index, return false
        // immediately
        if (i > maxReach)
            return false;

        // step 3 - updated the farthest index reachable
        maxReach = max(maxReach, i + nums[i]);
    }

    // step 4 - if we made it through the loop, we can reach the end
    return true;
}

int main(){
    // vector<int> nums = {2, 3, 1, 1, 4};

    vector<int> nums = {3, 2, 1, 0, 4};
    bool res = canJump(nums);
    res ? cout<<"true" : cout<<"false";
    return 0;
}