
// Problem link - https://leetcode.com/problems/find-closest-number-to-zero/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int findClosestNumber(vector<int>& nums) {
    // step 1 - assume first number of `nums` as closest number
    int closestNum = nums[0];

    // step 2 - iterate through the rest of the array starting from index 1
    for (int i = 1; i < nums.size(); i++) {
        int currNum = nums[i];

        // step 3 - calculate absolute distances from 0
        int currDistance = abs(currNum);
        int closestDistance = abs(closestNum);

        // step 4 - check if current number is closer to 0
        if (currDistance < closestDistance) {
            closestNum = currNum;
        }
        else if (currDistance == closestDistance) {
            // step 5 - if distances are equal, we need to pick the larger number
            closestNum = max(currNum, closestNum);
        }
    }

    // step 6 - return closest number `closestNum`
    return closestNum;
}

int main(){
    // vector<int> nums = {-4,-2,1,4,8};

    vector<int> nums = {2,-1,1};
    cout<<findClosestNumber(nums);
    return 0;
}