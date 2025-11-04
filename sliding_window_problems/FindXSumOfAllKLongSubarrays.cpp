
// Problem link - https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/?envType=daily-question&envId=2025-11-04

#include<bits/stdc++.h>
using namespace std;

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

vector<int> findXSum(vector<int>& nums, int k, int x) {
        
}

int main(){
    vector<int> nums = {1,1,2,2,3,4,2,3};
    int k = 6, x = 2;
    vector<int> res = findXSum(nums, k, x);

    return 0;
}