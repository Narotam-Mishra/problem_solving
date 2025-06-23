
// Problem link - https://leetcode.com/problems/sort-array-by-parity/?envType=problem-list-v2&envId=two-pointers

#include<bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    // using two-pointer approach
    int s = 0, e = nums.size() - 1;

    // step 1 - iterate through array using two-pointers
    while (s < e) {
        // step 2 - if left element is odd and right element is even, swap them
        if (nums[s] % 2 == 1 && nums[e] % 2 == 0) {
            // perform swap
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
        // step 3 - if left element is even, move left pointer
        else if (nums[s] % 2 == 0) {
            s++;
        }
        // step 4 - otherwise, if right element is odd, move right pointer
        else {
            e--;
        }
    }

    // step 5 - return array after operation completed
    return nums;
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
    // vector<int> nums = {3,1,2,4};

    vector<int> nums = {0};
    vector<int> res = sortArrayByParity(nums);
    printVector(res);
    return 0;
}