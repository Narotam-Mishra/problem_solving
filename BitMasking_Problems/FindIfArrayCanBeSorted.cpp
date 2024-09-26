
// Problem link : https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int num) {
    int setBits = 0;
    while (num > 0) {
        setBits += num & 1;
        num = num >> 1;
    }
    return setBits;
}

bool isSorted(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] > nums[i]) return false;
    }
    return true;
}

bool canSortArray(vector<int>& nums) {
    int n = nums.size();

    // outer loop for passes
    for(int i=0; i<n-1; i++){
        // inner loop for comparisons in each pass
        for(int j=0; j<n-i-1; j++){
            // if adjacent elements can be swapped and are in wrong order
            if(countSetBits(nums[j]) == countSetBits(nums[j+1]) && nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }

    // check if array can be sorted or not
    return isSorted(nums);
}

int main(){
    // vector<int> nums = {8, 4, 2, 30, 15};

    // vector<int> nums = {3,16,8,4,2};

    // vector<int> nums = {1, 2, 3, 4, 5};

    vector<int> nums = {20, 16};
    bool res = canSortArray(nums);
    res == 1 ? cout<<"true" : cout<<"false";
    return 0;
}