
#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    // step 1 - place each number at its correct position
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            // swap nums[i] with its correct index
            int correctIndex = nums[i] - 1;
            swap(nums[i], nums[correctIndex]);
        }
    }

    // step 2 - find the first missing number
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // step 3 - if all numbers 1 to n are present, return n+1
    return n + 1;
}

int main(){
    // vector<int> nums = {1, 2, 0};

    // vector<int> nums = {3,4,-1,1};

    vector<int> nums = {7,8,9,11,12};
    cout<<firstMissingPositive(nums)<<endl;
    return 0;
}