
// Problem link : https://leetcode.com/problems/sum-of-all-subset-xor-totals/

#include<bits/stdc++.h>
using namespace std;

int subsetXORSum(vector<int>& nums) {
    int totalSum = 0;
    int n = nums.size();

    for(int num : nums){
        totalSum |= num;
    }

    return (totalSum << n-1);
}

int main(){
    vector<int> arr = {3, 4, 5, 6, 7, 8};
    cout<<subsetXORSum(arr);
    return 0;
}