
// Problem link - https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int findDigitsSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int minElement(vector<int>& nums) {
    // store minimum number after replacement in `minNum`
    int minNum = INT_MAX;

    // step 1 - iterate on `nums` array
    for (int num : nums) {
        // step 2 - find digit sum if it is grater than 9
        if (num > 9) {
            int s = findDigitsSum(num);
            // step 3 - update minimum number
            minNum = min(minNum, s);
        }
        else {
            // update minimum number
            minNum = min(minNum, num);
        }
    }

    // step 4 - return minimum number `minNum` after replacement
    return minNum;
}

int main(){
    // vector<int> nums = {10,12,13,14};

    // vector<int> nums = {1,2,3,4};

    vector<int> nums = {999,19,199};
    cout<<minElement(nums);
    return 0;
}