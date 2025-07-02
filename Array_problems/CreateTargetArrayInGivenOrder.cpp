
// Problem link - https://leetcode.com/problems/create-target-array-in-the-given-order/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    int n = nums.size();

    // strore result in target array `target`
    vector<int> target;

    // step 1 - process each (value, index) pair from left to right
    for (int i = 0; i < n; i++) {
        // current value to insert
        int value = nums[i];

        // position where to insert
        int idx = index[i];

        // step 2 - insert value at specified index and shift existing elements to the right
        target.insert(target.begin() + idx, value);

    }

    // step 3 - return target array
    return target;
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
    // vector<int> nums = {0,1,2,3,4}, index = {0,1,2,2,1};

    // vector<int> nums = {1,2,3,4,0}, index = {0,1,2,3,0};

    vector<int> nums = {1}, index = {0};
    vector<int> res = createTargetArray(nums, index);
    printVector(res);
    return 0;
}
