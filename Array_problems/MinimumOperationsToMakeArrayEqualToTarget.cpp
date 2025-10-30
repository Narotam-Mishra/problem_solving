
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/

#include<bits/stdc++.h>
using namespace std;

long long minimumOperations(vector<int>& nums, vector<int>& target) {
    // get size of input array `nums`
    int n = nums.size();

    // store final result in `res`
    long long res = 0;

    // step 1 - find difference between target and nums array
    // vector<int> diff(n);
    // for(int i=0; i<n; i++){
    //     diff[i] = target[i] - nums[i];
    // }

    // step 2 - iterate on nums perform given operations
    int curr = 0, prev = 0;
    for(int i=0; i<n; i++){
        curr = target[i] - nums[i];

        // step 3 - check for sign change
        if((curr > 0 && prev < 0) || (curr < 0 && prev > 0)){
            res += abs(curr);
        }

        // step 4 - check if absolute value of current is greater than previous value
        else if(abs(curr) > abs(prev)){
            res += abs(curr - prev);
        }

        // step 5 - update previous, `prev`
        prev = curr;
    }

    // step 6 - return final result `res`
    return res;
}

int main(){
    vector<int> nums = {3,5,1,2}, target = {4,6,2,4};

    // vector<int> nums = {1,3,2}, target = {2,1,4};
    cout<<minimumOperations(nums, target);
    return 0;
}