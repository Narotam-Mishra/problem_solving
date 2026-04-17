
// Problem link - https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/?envType=daily-question&envId=2026-04-17

#include<bits/stdc++.h>
using namespace std;

// utility function to reverse number
int reverseNum(int num){
    int rev = 0;
    while(num > 0){
        int rem = num % 10;
        rev = rev*10 + rem;
        num = num / 10;
    }
    return rev;
}

int minMirrorPairDistance(vector<int>& nums) {
    int n = nums.size();

    // step 1 - store reverse of each number of nums in mao
    unordered_map<int, int> revMap;
    int res = INT_MAX;
    for(int i=0; i<n; i++){
        // step 2 - check reverse num exist in map or not
        if(revMap.count(nums[i])){
            res = min(res, abs(i - revMap[nums[i]]));
        }

        int revNum = reverseNum(nums[i]);
        revMap[revNum] = i;
    }

    // step 3 - return final result, `res`
    return res == INT_MAX ? -1 : res;
}

int main(){
    vector<int> nums = {12,21,45,33,54};

    // vector<int> nums = {21,120};
    cout<<minMirrorPairDistance(nums);
    return 0;
}