
// Problem link - https://leetcode.com/problems/find-the-array-concatenation-value/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

long long findTheArrayConcVal(vector<int>& nums) {
    int n = nums.size();

    // store final result in `res`
    long long res = 0;

    // step 1 - use two-pointers to point start and end of `nums`
    int s = 0, e = n - 1;

    // step 2 - iterate on `nums` using two-pointers
    while (s < e) {
        // step 3 - concate first and last value from nums
        string concatVal = to_string(nums[s]) + to_string(nums[e]);

        // step 4 - add it to final result `res`
        res += stoi(concatVal);

        // step 5 - update both pointers
        s++;
        e--;
    }

    // step 6 - if size of `nums` is odd 
    // then add one remaining element in result `res`
    if (n % 2 == 1) {
        res += nums[s];
    }

    // step 7 - return final `res`
    return res;
}

int main(){
    // vector<int> nums = {7,52,2,4};

    vector<int> nums = {5,14,13,8,12};
    cout<<findTheArrayConcVal(nums);
    return 0;
}