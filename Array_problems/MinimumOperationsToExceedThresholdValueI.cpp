
// Problem link - https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums, int k) {
    // store minimum number of operations needed
    int minOps = 0;

    // step 1 - iterate on input array `nums`
    for (int num : nums) {
        // step 2 - increment minimum operation `minOps`
        // if current `num` is less than `k`
        if (num < k) {
            minOps++;
        }
    }

    // step 3 - return minimum number of operations needed
    return minOps;
}

int main(){
    vector<int> nums = {2,11,10,1,3};
    int k = 10;
    cout<<minOperations(nums, k)<<endl;
    return 0;
}