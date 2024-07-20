
// /Problem link - https://leetcode.com/problems/number-of-good-pairs/

#include<bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    int cnt = 0;
    unordered_map<int, int> freq;

    for(int num : nums){
        if(freq.find(num) != freq.end()){
            cnt += freq[num];
            freq[num]++;
        }else{
            freq[num] = 1;
        }
    }
    return cnt;
}

int main(){
    vector<int> nums = {1,2,3,1,1,3,3};
    cout<<numIdenticalPairs(nums)<<endl;
    return 0;
}