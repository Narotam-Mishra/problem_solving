
#include<bits/stdc++.h>
using namespace std;

int repeatedNTimes(vector<int>& nums) {
    // step 1: create an unordered_map to store the frequency of each number
    unordered_map<int, int> map;

    // step 2: iterate through the array and track frequencies
    for (int num : nums) {
        map[num]++;
        // if a number appears more than once, return it
        if (map[num] > 1) {
            return num;
        }
    }
    // this case should never occur
    return -1;
}

int main(){
    // vector<int> nums = {1,2,3,3};

    // vector<int> nums = {2,1,2,5,3,2};

    vector<int> nums = {5,1,5,2,5,3,5,4};
    cout<<repeatedNTimes(nums)<<endl;
}