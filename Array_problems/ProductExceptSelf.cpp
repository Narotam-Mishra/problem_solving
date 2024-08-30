
// Problem link : https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-100-liked

#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> ansArr(len, 1);

    // compute left product
    int leftProduct = 1;
    for(int i=0; i<len; i++){
        ansArr[i] = leftProduct;
        leftProduct *= nums[i];
    }

    // compute right product and combine it with right product
    int rightProduct = 1;
    for(int i=len-1; i>=0; i--){
        ansArr[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return ansArr;
}

int main(){
    vector<int> arr = {1, 2, 3, 4};
    vector<int> res = productExceptSelf(arr);

    for(int num : res){
        cout<<num<<" ";
    }
    return 0;
}