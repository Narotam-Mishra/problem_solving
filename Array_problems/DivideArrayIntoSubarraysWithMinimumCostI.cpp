
// Problem link - https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01

#include<bits/stdc++.h>
using namespace std;

int minimumCost(vector<int>& nums) {
    // find size of nums
    int n = nums.size();

    // keep track of minimum cost in `minScore`
    int minScore = nums[0];

    // step 1 - keep track of first and second minimum
    int firstMinimum = INT_MAX;
    int secondMinimum = INT_MAX;

    // step 2 - iterate of remaining part of array and compute
    for(int i=1; i<n; i++){
        if(nums[i] < firstMinimum){
            secondMinimum = firstMinimum;
            firstMinimum = nums[i];
        }else if(nums[i] < secondMinimum){
            secondMinimum = nums[i];
        }
    }

    // step 3 - return the minimum possible sum
    return minScore + firstMinimum + secondMinimum;
}

int main(){
    // vector<int> nums = {1,2,3,12};

    // vector<int> nums = {5,4,3};

    vector<int> nums = {10,3,1,1};
    cout<<minimumCost(nums);
    return 0;
}
