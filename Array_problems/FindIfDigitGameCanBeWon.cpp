
// Problem link - https://leetcode.com/problems/find-if-digit-game-can-be-won/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

bool canAliceWin(vector<int>& nums) {
    // store single digit and double digits sum
    int sdSum = 0, ddSum = 0;

    // step 1 - iterate on each number of `nums`
    for (int num : nums) {
        if (num < 10) {
            // find single digit number sum
            sdSum += num;
        }
        else {
            // find doubel digit number sum
            ddSum += num;
        }
    }

    // step 2 - Alice wins if the sums are different (she picks the larger one)
    return sdSum != ddSum;
}

int main(){
    // vector<int> nums = {1,2,3,4,10};

    // vector<int> nums = {1,2,3,4,5,14};

    vector<int> nums = {5,5,5,25};
    bool res = canAliceWin(nums);
    res ? cout<<"true" : cout<<"false";
    return 0;
}