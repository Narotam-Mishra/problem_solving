
// Problem link - https://leetcode.com/problems/third-maximum-number/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int thirdMax(vector<int>& nums) {
    // step 1 - using Long.MIN_VALUE to handle negative numbers properly
    long max1 = LONG_MIN;
    long max2 = LONG_MIN;
    long max3 = LONG_MIN;

    // step 2 - iterate on each num of `nums`
    for (int num : nums) {
        // step 3 - skip duplicates
        if (num == max3 || num == max2 || num == max1) {
            continue;
        }
        // step 4 - if current number is greater than first max
        if (num > max1) {
            // shift all values: max1 becomes max2, max2 becomes max3
            max3 = max2;
            max2 = max1;
            max1 = num;
        }

        // step 4 - if current number is between max1 and max2
        else if (num > max2) {
            max3 = max2;
            max2 = num;
        }

        // step 5 - if current number is between max2 and max3
        else if (num > max3) {
            max3 = num;
        }
    }

    // step 6 - if third maximum exists (not -Infinity), return it, otherwise return
    // first maximum `max1`
    return (max3 != LONG_MIN) ? (int)max3 : (int)max1;
}

int main(){
    // vector<int> nums = {3, 2, 1};

    // vector<int> nums = {1, 2};

    vector<int> nums = {2, 2, 3, 1};
    cout<<thirdMax(nums)<<endl;
    return 0;
}