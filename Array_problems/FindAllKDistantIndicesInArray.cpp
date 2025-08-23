
// Problem link - https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int n = nums.size();

    // store key indices that matches nums[j] == key
    vector<int> keyIndices;

    // store result in `res` list
    vector<int> res;

    // step 1 - find all indices where `nums[j] == key`
    for (int j = 0; j < n; j++) {
        if (nums[j] == key) {
            keyIndices.push_back(j);
        }
    }

    // step 2 - for each index `i`, check if any key is within diatance `k`
    for (int i = 0; i < n; i++) {
        bool isKDistant = false;

        // step 3 - check each key position
        for (int j : keyIndices) {
            if (abs(i - j) <= k) {
                isKDistant = true;
                break;
            }
        }

        // if current index is within k-distance then add it to result
        if (isKDistant) {
            res.push_back(i);
        }
    }

    // step 4 - return final result `res`
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
    // vector<int> nums = {3,4,9,1,3,9,5};
    // int key = 9, k = 1;

    vector<int> nums = {2,2,2,2,2};
    int key = 2, k = 2;
    vector<int> res = findKDistantIndices(nums, key, k);
    printVector(res);
    return 0;
}