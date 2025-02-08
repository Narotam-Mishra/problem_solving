
#include<bits/stdc++.h>
using namespace std;

int findShortestSubArray(vector<int>& nums) {
    // step 1: find the maximum number in nums
    int maxNum = 0;
    for (int num : nums) {
        maxNum = max(maxNum, num);
    }

    // step 2: create map arrays as map to store frequency, first index, and last index
    vector<int> map(maxNum + 1, 0);        // frequency map
    vector<int> firstIndex(maxNum + 1, 0); // first occurrence index
    vector<int> lastIndex(maxNum + 1, 0);  // last occurrence index

    // step 3: populate the frequency map and find the degree
    int degree = 0;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        map[num]++;
        degree = max(degree, map[num]);
        if (map[num] == 1) {
            firstIndex[num] = i;
        }
        lastIndex[num] = i;
    }

    // step 4: find the smallest subarray length
    int minLengthSubArray = INT_MAX;
    for (int num = 0; num <= maxNum; num++) {
        if (map[num] == degree) {
            int subArrLen = lastIndex[num] - firstIndex[num] + 1;
            minLengthSubArray = min(minLengthSubArray, subArrLen);
        }
    }

    // step 5: return the result
    return minLengthSubArray;
}

int main(){
    // vector<int> nums = {1,2,2,3,1};

    vector<int> nums = {1,2,2,3,1,4,2};
    cout<<findShortestSubArray(nums);
    return 0;
}