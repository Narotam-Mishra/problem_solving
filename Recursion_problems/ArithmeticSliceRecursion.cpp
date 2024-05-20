
// Problem link - https://leetcode.com/problems/arithmetic-slices/description/

// Approach - using Recursion

#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

int findNumOfArithmeticSlicesRec(int i){
    // Base case1: if ith index is 0 or 1 then there is no Arithmetic slice return 0
    if(i == 0 || i == 1) return 0;

    // Base case2 : if the difference between any two consecutive elements is not the same then return 0
    if(arr[i] -arr[i-1] != arr[i-1] - arr[i-2]) return 0;

    // Recursive case
    return 1 + findNumOfArithmeticSlicesRec(i-1);
}

int numberOfArithmeticSlices(vector<int>& nums) {
    arr = nums;
    int res = 0;
    for(int i=0; i<nums.size(); i++){
        res += findNumOfArithmeticSlicesRec(i);
    }
    return res;
}

int main(){
    vector<int> arr = {1,2,3,4};
    cout<<numberOfArithmeticSlices(arr)<<endl;
    return 0;
}