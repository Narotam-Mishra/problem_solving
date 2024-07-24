
// Problem link - https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/

#include<bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& nums) {
    int count1 = 0, count2 = 0;
    for(int num : nums){
        int rem = num % 3;
        if(rem == 1) count1++;
        else if(rem == 2) count2++;
    }
    int ans = min(count1, count2) * 2 + abs(count1 - count2);
    return ans;
}

int main(){
    vector<int> nums = {1, 2 ,3, 4};
    cout<<minimumOperations(nums)<<endl;
    return 0;
}