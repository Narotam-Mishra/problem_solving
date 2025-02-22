
#include<bits/stdc++.h>
using namespace std;

int sumCounts1(vector<int>& nums) {
    // store total sum of distinct subarray count
    int totalSum = 0;

    // step 1 - iterate over all possible starting points of subarrays
    for (int i = 0; i < nums.size(); i++) {
        // stor unique elements in current subarray
        unordered_set<int> numSet;

        // step 2 - iterate over all possible ending points of subarrays starting at i
        for (int j = i; j < nums.size(); j++) {
            // add current subarray element to set
            numSet.insert(nums[j]);

            // step 3 - calculate the distinct count and its square
            int distinctCount = numSet.size();
            totalSum += (distinctCount * distinctCount);
        }
    }

    // step 4 - return the total sum
    return totalSum;
}

int sumCounts(vector<int>& nums) {
    // store total sum of distinct subarray count
    int totalSum = 0;

    // step 1 - iterate over all possible starting points of subarrays
    for (int i = 0; i < nums.size(); i++) {
        // stor unique elements in frequency array map
        int freqMap[101] = {0};

        // track distinct element count
        int distinctCount = 0;

        // step 2 - iterate over all possible ending points of subarrays starting at i
        for (int j = i; j < nums.size(); j++) {
            // if element is not present in subarray
            if (freqMap[nums[j]] == 0) {
                distinctCount++;
            }

            // increment frequency of current element
            freqMap[nums[j]]++;

            // step 3 - calculate the distinct count and its square
            totalSum += (distinctCount * distinctCount);
        }
    }

    // step 4 - return the total sum
    return totalSum;
}

int main(){
    // vector<int> nums = {1, 1};

    vector<int> nums = {1, 2, 1};
    cout<<sumCounts(nums)<<endl;
    return 0;
}