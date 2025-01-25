
#include<bits/stdc++.h>
using namespace std;

int numberOfPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
    // step 1 - intialize variable to count good pairs
    int goodPairsCount = 0;

    // step 2 - loop through both arrays
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            // step 3 - check if the number is divisible by the product of the number in the
            // second array and k
            if (nums1[i] % (nums2[j] * k) == 0) {
                goodPairsCount++;
            }
        }
    }

    // step 4 - return the count of good pairs
    return goodPairsCount;
}

int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    // step 1: create a hash map to store the frequency of nums2[j] * k
    unordered_map<int, int> divisorMap;
    for (int num : nums2) {
        // calculate the divisor
        int divisor = num * k;
        // increment frequency in the map 
        divisorMap[divisor]++; 
    }

    // step 2: iterate through nums1 and count good pairs
    int goodPairs = 0;
    for (int num : nums1) {
        for (auto& [divisor, count] : divisorMap) {
            // check divisibility
            if (num % divisor == 0) {
                // add the count of this divisor to the result 
                goodPairs += count; 
            }
        }
    }

    // step 3 - return all good pairs count
    return goodPairs;
}

int main(){
    vector<int> nums1 = {1,3,4};
    vector<int> nums2 = {1,3,4};
    int k = 1;

    // vector<int> nums1 = { 1, 2, 4, 12 };
    // vector<int> nums2 = {2,4};
    // int k = 3;
    cout<<numberOfPairs(nums1, nums2, k)<<endl;
    return 0;
}