
// Problem link - https://leetcode.com/problems/maximum-subarray-with-equal-products/?envType=problem-list-v2&envId=number-theory

#include<bits/stdc++.h>
using namespace std;

// helper function to compute GCD
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// helper function to compute LCM
long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int maxLength(vector<int>& nums) {
    // store length of longest product equivalent subarray in `maxLen`
        int maxLen = 0;
        int n = nums.size();

        // step 1 - loop through all subarrays
        for (int i = 0; i < n; i++) {
            long long currGCD = nums[i];
            long long currLCM = nums[i];
            long long currProd = nums[i];

            // step 2 - iterate on each subarray starting from index `i`
            for (int j = i; j < n; j++) {
                if (j > i) {
                    // step 3 - to prevent overflow, break if product is too large
                    if(currProd > 1e18) break;

                    currProd *= nums[j];

                    // step 4 - update GCD and LCM
                    currGCD = gcd(currGCD, nums[j]);
                    currLCM = lcm(currLCM, nums[j]);
                }

                // step 5 - check the product equivalent condition
                if(currProd == currGCD * currLCM){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        // step 6 - return maxLen
        return maxLen;
}

int main(){
    // vector<int> nums = {1,2,1,2,1,1,1};

    // vector<int> nums = {2,3,4,5,6};

    vector<int> nums = {1,2,3,1,4,5,1};
    cout<<maxLength(nums)<<endl;
    return 0;
}