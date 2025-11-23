
// Problem link - https://leetcode.com/problems/greatest-sum-divisible-by-three/?envType=daily-question&envId=2025-11-23

#include<bits/stdc++.h>
using namespace std;

int maxSumDivThree(vector<int>& nums) {
    // step 1 - store those numbers whose remainder are 1 & 2
    vector<int> remain1;
    vector<int> remain2;

    // calculate total sum of each element
    int sum = 0;
    for(int &num : nums){
        sum += num;

        // categorize based on remainder
        if(num % 3 == 1){
            remain1.push_back(num);
        }else if(num % 3 == 2){
            remain2.push_back(num);
        }
    }

    // corner case: if overall sum is divisible by 3 then
    // that will be final answer
    if(sum % 3 == 0){
        return sum;
    }

    // step 2 - sort them in ascending order
    // this allows us to easily access the smallest numbers for removal
    sort(remain1.begin(), remain1.end());
    sort(remain2.begin(), remain2.end());

    // step 3 - based on the remainder of total sum, decide what to remove
    int res = 0;
    int remainder = sum % 3;
    if(remainder == 1){
        // total sum has remainder 1
        // case 1: remove one smallest number with remainder 1
        int r1 = remain1.size() >= 1 ? remain1[0] : INT_MAX;
        
        // case 2 - remove two smallest numbers with remainder 2
        int r2 = remain2.size() >= 2 ? remain2[0] + remain2[1] : INT_MAX;

        // choose the option that removes the minimum
        res = max(res, sum - min(r1,r2));
    }else{
        // total sum has remainder 2
        // case 1: remove one smallest number with remainder 2
        int r1 = remain2.size() >= 1 ? remain2[0] : INT_MAX;
        
        // case 2 - remove two smallest numbers with remainder 1
        int r2 = remain1.size() >= 2 ? remain1[0] + remain1[1] : INT_MAX;

        // choose the option that removes the minimum
        res = max(res, sum - min(r1,r2));
    }

    // step 4 - return final result, `res`
    return res;
}

int main(){
    // vector<int> nums = {3,6,5,1,8};

    // vector<int> nums = {4};

    vector<int> nums = {1,2,3,4,4};
    cout<<maxSumDivThree(nums);
    return 0;
}