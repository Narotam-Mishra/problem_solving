
// Problem link - https://leetcode.com/problems/most-frequent-even-element/description/

#include<bits/stdc++.h>
using namespace std;

int mostFrequentEven(vector<int>& nums) {
    // step 1 - Count frequency of even numbers only
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        if (num % 2 == 0) {
            freqMap[num]++;
        }
    }

    int maxFreq = 0;
    int result = -1;

    // step 2 - find the most frequent even number (smallest in case of tie)
    for (auto& pair : freqMap) {
        int num = pair.first;
        int freq = pair.second;

        if (freq > maxFreq || (freq == maxFreq && num < result)) {
            maxFreq = freq;
            result = num;
        }
    }

    // step 3 - return the result
    return result;
}

int main(){
    // vector<int> nums = {0,1,2,2,4,4,1};

    // vector<int> nums = {4,4,4,9,2,4};

    vector<int> nums = {29,47,21,41,13,37,25,7};
    cout<<mostFrequentEven(nums)<<endl;
    return 0;
}