
#include<bits/stdc++.h>
using namespace std;

bool containsValue(vector<int>& nums, int x) {
    // check if the value x is present in the array
    for(int num : nums) {
        if(num == x) {
            return true;
        }
    }
    return false;
}

int missingInteger(vector<int>& nums) {
    // step 1 - initialize the sum of the longest sequential prefix
    int prefixSum = nums[0];

    // intialize the expected next value in the sequential prefix
    int expectedSum = nums[0] + 1;

    // step 2 - traverse through the array to find the longest sequential prefix
    for(int i=1; i<nums.size(); i++) {
        // if the current number is the expected sequential number
        if(nums[i] == expectedSum) {
            // add to the prefix sum
            prefixSum += nums[i];

            // move to the next expected sequential number
            expectedSum++;
        } else {
            // otherwise break if sequence is broken
            break;
        }
    }

    // step 3 - find the smallest missing number >= prefixSum
    int x = prefixSum;
    
    // check for the smallest missing value
    while(containsValue(nums, x)) {
        // keep checking until we find a missing number
        x++;
    }

    // step 4 - return the smallest missing number
    return x;
}

int main(){
    vector<int> nums = {1, 2, 3, 2, 5};

    // vector<int> nums = {3,4,5,1,12,14,13};
    cout << missingInteger(nums) << endl;
    return 0;
}