
// Problem link : https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-100-liked

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int reqNum = nums[0];
    int count = 1;

    for(int i=1; i<nums.size(); i++){
        if(reqNum == nums[i]){
            count++;
        }else{
            count--;
            if(count == 0){
                reqNum = nums[i];
                count = 1;
            }
        }
    }
    return reqNum;
}

int main(){
    vector<int> arr = {2,2,1,1,1,2,2};
    cout<<majorityElement(arr)<<endl;
}