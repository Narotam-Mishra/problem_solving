
// Problem link :- https://leetcode.com/problems/total-hamming-distance/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int totalHammingDistance(vector<int>& nums) {
    int n = nums.size(), thdSum = 0;

    // iterate over each bit position (0 to 31)
    for(int i=0; i<32; i++){
        int ones = 0;

        // count how many numbers have a 1 at bit position i
        for(int num : nums){
            ones += (num >> i) & 1;
        }

        // number of zeros at this bit position
        int zeroes = n - ones;
        
        // contribution of this bit position to total Hamming distance
        thdSum += (ones * zeroes);
    }

    // return total hamming distance sum (thdSum)
    return thdSum;
}

int main(){
    // vector<int> nums = {4, 14, 2};

    vector<int> nums = {4, 14, 4};
    cout<<totalHammingDistance(nums);
    return 0;
}