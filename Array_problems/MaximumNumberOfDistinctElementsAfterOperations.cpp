
// Problem link - https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/?envType=daily-question&envId=2025-10-18

#include<bits/stdc++.h>
using namespace std;

int maxDistinctElements(vector<int>& nums, int k) {
    // find size of input array `nums`
    int n = nums.size();

    // step 1 - sort input array `nums` to process elements in ascending order
    sort(nums.begin(), nums.end());

    // step 2 - keep track of previously updated element
    // we need this to ensure the next element gets a value > prev (distinct)
    int prev = INT_MIN;

    // step 3 - iterate through each element in the sorted array
    int count = 0;
    for(int i=0; i<n; i++){
        // step 4 - calculate the minimum possible value for current element
        int minVal = nums[i] - k;
        
        // case 1 - if previous value is less than the minimum possible value
        // this means there's a gap, and we can place current element at its minimum
        if(prev < minVal){
            prev = nums[i] - k;
            
            // increment count for this distinct element
            count++;
        }

        // case 2 - if previous value is within or just before the valid range
        // check if prev is less than the maximum possible value (nums[i]+k)
        else if(prev < nums[i] + k){
            // this means we can place the element just after prev
            prev = prev + 1;

            // increment count for this distinct element
            count++;
        }
    }

    // step 5 - return the total count of distinct elements we could create
    return count;
}

int main(){
    // vector<int> nums = {1,2,2,3,3,4};
    // int k = 2;

    vector<int> nums = {4,4,4,4};
    int k = 1;
    cout<<maxDistinctElements(nums, k);
    return 0;
}