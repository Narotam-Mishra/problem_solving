
// Problem link - https://leetcode.com/problems/array-partition/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    // store maximum sum of minimums in `maxSum`
    int maxSum = 0;

    // step 1 - sort the array to group similar values together
    // this ensures we pair each number with its closest neighbor
    sort(nums.begin(), nums.end());

    // step 2 - iterate of array's number
    // we take elements at even indices (0, 2, 4, ...) because after sorting,
    // these will be the minimum values in each optimal pair
    for (int i = 0; i < nums.size(); i += 2) {
        // step 3 - calculate the sum
        maxSum += nums[i];
    }

    // step 4 - return maximum sum of minimums in `maxSum`
    return maxSum;
}

int main(){
    // vector<int> nums = {1,4,3,2};

    vector<int> nums = {6,2,6,5,1,2};
    cout<<arrayPairSum(nums);
    return 0;
}