
#include<bits/stdc++.h>
using namespace std;

int countKDifference(vector<int>& nums, int k) {
    // step 1 - hash map to store the frequency of each number
    unordered_map<int,int> mp;
    int count = 0;
    
    // step 2 - iterate through each number in the array
    for(int i=0;i<nums.size();i++){
        // 2.1 - check if there exists a number such that num - k = otherNum
        if(mp.find(nums[i]-k)!=mp.end()){
            count += mp[nums[i]-k];
        }

        // 2.2 - check if there exists a number such that num + k = otherNum
        if(mp.find(nums[i]+k)!=mp.end()){
            count += mp[nums[i]+k];
        }

        // step 3 - updated the frequency map with the current number
        mp[nums[i]]++;
    }

    // step 4 - return the total count of valid pairs
    return count;
}

int main(){
    // vector<int> nums = {1,2,2,1};
    // int k = 1;

    // vector<int> nums = {1,3};
    // int k = 3;

    vector<int> nums = {3,2,1,5,4};
    int k = 2;
    cout<<countKDifference(nums,k)<<endl;
    return 0;
}