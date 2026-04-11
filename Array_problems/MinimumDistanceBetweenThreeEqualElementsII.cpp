
// Problem link - https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/?envType=daily-question&envId=2026-04-11

#include<bits/stdc++.h>
using namespace std;

int minimumDistance(vector<int>& nums) {
    int n = nums.size();

    // store each number with their index of occurences
    // number --> vector<int>
    unordered_map<int, vector<int>> numMap;

    // keep track of final result in `res`
    int res = INT_MAX;

    // step 1 - iterate on each number 
    for(int k=0; k<n; k++){
        // step 2 - generate map
        numMap[nums[k]].push_back(k);

        // minimum three indices is required
        if(numMap[nums[k]].size() >= 3){
            // step 3 - extract i & k
            vector<int>& vec = numMap[nums[k]];
            int len = vec.size();
            int i = vec[len-3];

            // step 4 - calculate and update result
            res = min(res, 2*(k-i));
        }
    }

    // step 4 - return final result, `res`
    return res == INT_MAX ? -1 : res;
}

int main(){
    // vector<int> nums = {1,2,1,1,3};

    // vector<int> nums = {1,1,2,3,2,1,2};

    vector<int> nums = {1};
    cout<<minimumDistance(nums);
    return 0;
    cout<<minimumDistance(nums);
    return 0;
}