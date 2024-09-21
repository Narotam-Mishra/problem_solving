
// Problem link : https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

bool hasTrailingZeros(vector<int>& nums) {
    int count = 0;
    for (int num : nums) {
        if ((num & 1) != 1) count++;
    }
    return count >= 2;
}

int main(){
    // vector<int> nums = {1, 2, 3, 4, 5};

    vector<int> nums = {2, 4, 8, 16};
    bool res = hasTrailingZeros(nums);
    res ? cout<<"true" : cout<<"false";
    return 0;
}