
// Problem link - https://leetcode.com/problems/transformed-array/description/?envType=daily-question&envId=2026-02-05

#include<bits/stdc++.h>
using namespace std;

vector<int> constructTransformedArray(vector<int>& nums) {
    int n = nums.size();

    // store result in `res`
    vector<int> res(n);

    // step 1 - iterate on each num of `nums`
    for(int i=0; i<n; i++){
        // step 2 - check if it is positive value
        if(nums[i] > 0){
            // then move right
            int newIndex = (i + nums[i]) % n;
            res[i] = nums[newIndex];
        }

        // step 3 - check if it is negative value
        else if(nums[i] < 0){
            // move left
            int steps = abs(nums[i]);
            int newIndex = ((i - steps) % n + n) % n;
            res[i] = nums[newIndex];
        }
        // step 4 - check if value is zero
        else{
            // then stay at same index
            res[i] = nums[i];
        }
    }

    // step 5 - return final result, `res`
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
    // vector<int> nums = {3,-2,1,1};

    vector<int> nums = {-1,4,-1};
    vector<int> res = constructTransformedArray(nums);
    printVector(res);
    return 0;
}