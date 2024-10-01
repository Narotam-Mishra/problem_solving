
// Problem link :- https://leetcode.com/problems/set-mismatch/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    // sort the array to make it easier to spot the duplicate
    sort(nums.begin(), nums.end());

    // initialize with default values
    int missingNum = -1, duplicateNum = -1;
    int n = nums.size();

    // iterate through the sorted array to find the duplicate number
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] == nums[i]) {
            // find duplicate
            duplicateNum = nums[i];
        }
    }

    // calculate the expected sum of numbers from 1 to n
    int expSum = (int)(n * (n + 1)) / 2;

    // calculate the actual sum of the array with the duplicate
    int actSum = 0;
    for (int num : nums) {
        actSum += num;
    }

    // Missing number = expected sum - (actual sum - duplicate number)
    missingNum = expSum - (actSum - duplicateNum);

    vector<int> res{ duplicateNum, missingNum };
    return res;
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" <<endl;
}

int main(){
    // vector<int> nums = {1, 2, 2, 4};

    vector<int> nums = {2, 2};
    vector<int> res = findErrorNums(nums);
    printVector(res);
    return 0;
}