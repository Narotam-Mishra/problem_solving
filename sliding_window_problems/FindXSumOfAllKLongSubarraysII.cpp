
// Problem link - https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/?envType=daily-question&envId=2025-11-05

#include<bits/stdc++.h>
using namespace std;

vector<long long> findXSum(vector<int>& nums, int k, int x) {
    vector<long long> res;
    return res;
}

void printVector(vector<long long>& vec){
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
    // vector<int> nums = {1,1,2,2,3,4,2,3};
    // int k = 6, x = 2;

    vector<int> nums = {3,8,7,8,7,5};
    int k = 2, x = 2;
    vector<long long> res = findXSum(nums, k, x);
    printVector(res);
    return 0;
}