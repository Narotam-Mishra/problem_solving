
// Problem link - https://leetcode.com/problems/sign-of-the-product-of-an-array/

#include<bits/stdc++.h>
using namespace std;

int arraySign(vector<int>& nums) {
    int countNegatives = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0) return 0;
        else if(nums[i] < 0){
            countNegatives++;
        }
    }
    return countNegatives % 2 == 0 ? 1 : -1;
}

int main(){
    vector<int> arr = {-1, -2, -3, -4, 3, 2, 1};
    cout<<arraySign(arr)<<endl;
    return 0;
}