
// Problem link - https://leetcode.com/problems/minimum-number-game/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> numberGame(vector<int>& nums) {
    int n = nums.size();
    // store result in `res`
    vector<int> res(n, 0);

    // step 1 - sort the array to get minimum number easily
    sort(nums.begin(), nums.end());

    // step 2 - iterate on `nums` array
    for (int i = 0; i < n; i += 2) {
        // step 3 - get minimum element for Alicer and Bob
        int minAlice = nums[i];
        int minBob = nums[i + 1];

        // step 4 - store minimum element as per given condition
        res[i] = minBob;
        res[i + 1] = minAlice;
    }

    // step 5 - return result `res`
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
    // vector<int> nums = {5,4,2,3};

    vector<int> nums = {2,5};
    vector<int> res = numberGame(nums);
    printVector(res);
    return 0;
}