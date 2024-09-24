
// Problem link : https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int num : nums) {
        res ^= num;
    }
    return res;
}

int main(){
    // vector<int> nums = {2, 2, 1};

    vector<int> nums = {4, 1, 2, 1, 2};
    cout<<singleNumber(nums);
    return 0;
}