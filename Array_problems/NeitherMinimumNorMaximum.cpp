
// Problem link - https://leetcode.com/problems/neither-minimum-nor-maximum/

#include<bits/stdc++.h>
using namespace std;

int findNonMinOrMax(vector<int>& nums) {
    // step 1 - find minimum and maximum number in `nums`
    int minNum = INT_MAX, maxNum = -1;
    for (int num : nums) {
        if (num > maxNum) {
            maxNum = num;
        }

        if (num < minNum) {
            minNum = num;
        }
    }

    // step 2 - iterate on nums
    for (int num : nums) {
        // step 3 - compare numbers `num` from minimum and maximum number that are not equal
        if (num != minNum && num != maxNum) {
            // step 4 - return neither maximum nor minimum number
            return num;
        }
    }

    // step 5 - if no number found, return -1
    return -1;
}

int main(){
    // vector<int> nums = {3,2,1,4};

    // vector<int> nums = {1,2};

    vector<int> nums = {2,1,3};
    cout<<findNonMinOrMax(nums)<<endl;
    return 0;
}