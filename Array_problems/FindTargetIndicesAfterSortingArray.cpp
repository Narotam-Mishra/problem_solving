
// Problem link - https://leetcode.com/problems/find-target-indices-after-sorting-array/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
    // store result in `res` array
    vector<int> res;

    // step 1 - sort that array
    sort(nums.begin(), nums.end());

    // step 2 - iterate on each element of array
    for (int i = 0; i < nums.size(); i++) {
        // step 3 - check if current element of array is equal to target
        if (nums[i] == target) {
            // store indices in `res`
            res.push_back(i);
        }
    }

    // step 4 - return `res`
    return res;
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}


int main(){
    // vector<int> nums = {1,2,5,2,3};
    // int target = 2;

    // vector<int> nums = {1,2,5,2,3};
    // int target = 3;

    vector<int> nums = {1,2,5,2,3};
    int target = 5;
    
    vector<int> res = targetIndices(nums, target);
    printVector(res);
}