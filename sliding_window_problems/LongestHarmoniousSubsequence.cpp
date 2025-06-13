
// Problem link - https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=problem-list-v2&envId=sliding-window

#include<bits/stdc++.h>
using namespace std;

int findLHS(vector<int>& nums) {
    // step 1 - count frquencies
    unordered_map<int, int> count;
    for (int num : nums) {
        count[num]++;
    }

    // step 2 - iterate on each number of `nums`
    int maxLength = 0;
    for (int num : nums) {
        // step 3 - check if adjacent pairs exist
        if (count.count(num + 1)) {
            // step 4 - calculate length of harmonious subsequence
            int currLen = count[num] + count[num + 1];

            // step 5 - update maximum length
            maxLength = max(maxLength, currLen);
        }
    }

    // step 6 - return maximun subsequence length `maxLength`
    return maxLength;
}

int main(){
    // vector<int> nums = {1,3,2,2,5,2,3,7};

    // vector<int> nums = {1,2,3,4};

    vector<int> nums = {1,1,1,1};
    cout<<findLHS(nums)<<endl;
    return 0;
}