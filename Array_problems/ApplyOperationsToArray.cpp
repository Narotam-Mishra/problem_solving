
// Problem link - https://leetcode.com/problems/apply-operations-to-an-array/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> applyOperations(vector<int>& nums) {
    // find size of `nums` size
    int n = nums.size();

    // step 1 - iterate on input array and perform operations
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    // step 2 - move zeros to end
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            int temp = nums[i];
            nums[i] = nums[k];
            nums[k] = temp;
            k++;
        }
    }

    // step 3 - return resultant array `nums`
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
    // vector<int> nums = {1,2,2,1,1,0};

    vector<int> nums = {0,1};
    vector<int> res = applyOperations(nums);
    printVector(res);
    return 0;
}