
// Problem link - https://leetcode.com/problems/jump-game-ix/description/?envType=daily-question&envId=2026-05-07

#include<bits/stdc++.h>
using namespace std;

vector<int> maxValue(vector<int>& nums) {
    int n = nums.size();

    // res[i] stores the maximum value reachable from index i.
    vector<int> res(n);

    // maxLeft[i] = maximum value in nums[0...i].
    // minRight[i] = minimum value in nums[i...n-1].
    vector<int> maxLeft(n);
    vector<int> minRight(n);

    // initialize boundary values for prefix maximum and suffix minimum.
    maxLeft[0] = nums[0];
    minRight[n-1] = nums[n-1];

    // step 1 - build prefix maximum.
    for(int i=1; i<n; i++){
        maxLeft[i] = max(nums[i], maxLeft[i-1]);
    }

    // step 2 - build suffix minimum.
    for(int i=n-2; i>=0; i--){
        minRight[i] = min(nums[i], minRight[i+1]);
    }

    // step 3 - traverse from right to left and form connected reachable groups.
    // the last index can always reach the maximum value seen on its left side.
    res[n-1] = maxLeft[n-1];

    for(int i=n-2; i>=0; i--){
        // case 1 - if every value on the left side is <= every value on the right side,
        // index i cannot connect to the next reachable group. Its answer is
        // only the maximum value within nums[0...i].
        if(maxLeft[i] <= minRight[i+1]){
            res[i] = maxLeft[i];
        }
        else{
            // case 2 - otherwise, both parts are connected through valid jumps, so
            // index i gets the same answer as the group starting at i + 1.
            res[i] = res[i+1];
        }
    }

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
    // vector<int> nums = {2,1,3};

    vector<int> nums = {2,3,1};
    vector<int> res = maxValue(nums);
    printVector(res);
    return 0;
}
