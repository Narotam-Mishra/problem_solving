
// Problem link : https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

bool divideArray(vector<int>& nums) {
    // using hashmap to store the frequency of each number
    unordered_map<int, int> freqMap;

    // count the occurrences of each number in the array
    for(int num : nums){
        freqMap[num]++;
    }

    // to make pairs, check if each number's frequency is even
    for(const auto& entry : freqMap){
        // if any number appears an odd number of times, we cannot divide into pairs
        if(entry.second & 1){
            // if any count is odd, return false
            return false;
        }
    }

    // all numbers have even counts
    return true;
}

int main(){
    // vector<int> nums = {3, 2, 3, 2, 2, 2};

    vector<int> nums = {1, 2, 3, 4};
    bool res = divideArray(nums);
    res ? cout<<"true" : cout<<"false"<<endl;
    return 0;
}