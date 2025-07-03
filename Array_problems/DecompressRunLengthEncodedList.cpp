
// Problem link - https://leetcode.com/problems/decompress-run-length-encoded-list/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> decompressRLElist(vector<int>& nums) {
    // store resultant decompressed list in `res`
    vector<int> res;

    // step 1 - iterate on input array `nums`
    for (int i = 0; i < nums.size(); i += 2) {
        // step 2 - extraxt frq and value
        int frq = nums[i];
        int val = nums[i + 1];

        // step 3 - fill the value in `res`
        while (frq > 0) {
            res.push_back(val);
            frq--;
        }
    }

    // step 4 - return resultant array `res`
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
    // vector<int> nums = {1,2,3,4};

    vector<int> nums = {1,1,2,3};
    vector<int> res = decompressRLElist(nums);
    printVector(res);
    return 0;
}