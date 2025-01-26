
#include<bits/stdc++.h>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    // step 1: create a frquency array map to store the frequency of each element
    vector<int> freq(101, 0);
    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }

    // step 2: find the maximum frequency
    int maxFreq = 0;
    for (int i = 0; i < freq.size(); i++) {
        maxFreq = max(maxFreq, freq[i]);
    }

    // step 3: sum up the frequencies of elements with the maximum frequency
    int totalFrquency = 0;
    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] == maxFreq) {
            totalFrquency += freq[i];
        }
    }

    // step 4 : return the total frequency
    return totalFrquency;
}

int main(){
    // vector<int> nums = {1,2,2,3,1,4};

    // vector<int> nums = {1,2,3,4,5};

    // vector<int> nums = {15};

    vector<int> nums = {81,81,81,81,81,81,81,17,28,81,81,56,81,54,81,81,81,81,81,60,81,28,81,81,81,81,81,54,81,81,81,81,100,28};
    cout << maxFrequencyElements(nums) << endl;
    return 0;
}