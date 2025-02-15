
// Problem link : https://leetcode.com/problems/check-if-array-is-good/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

bool isGood(vector<int>& nums) {
    // step 1: find the length of the array and calculate `n`
    int n = nums.size() - 1;

    // step 2: find the maximum value in the array
    int maxNum = *max_element(nums.begin(), nums.end());

    // edge case check: `maxNum` must be equal to `n`
    if (maxNum != n) return false;

    // step 3: calculate frequency of each number in `nums`
    vector<int> freqMap(maxNum + 1, 0);
    for (int num : nums) {
        freqMap[num]++;
    }

    // step 4: validate frequency conditions
    for (int i = 1; i < n; i++) {
        if (freqMap[i] != 1) {
            return false;
        }
    }

    // step 5: `n` should appear exactly twice
    return freqMap[n] == 2;
}

int main(){
    // vector<int> nums = {2, 1, 3};

    // vector<int> nums = {1, 3, 3, 2};

    // vector<int> nums = {1, 1};

    // vector<int> nums = {3, 4, 4, 1, 2, 1};

    vector<int> nums = {14, 2, 2};
    bool res = isGood(nums);
    res ? cout<<"true" : cout<<"false";
    return 0;
}