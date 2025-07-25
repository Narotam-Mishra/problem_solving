
// Problem link - https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

double minimumAverage(vector<int>& nums) {
    // find length of `nums` array
    int n = nums.size();

    // store minimum average in `minAvg`
    double minAvg = DBL_MAX;

    // step 1 - sort `nums` for easy iteration using two pointers
    sort(nums.begin(), nums.end());

    // step 2 - rpeat operation n/2 times
    int s = 0, e = n - 1;
    while (s < e) {
        // step 3 - calculate current average `currAvg`
        double currAvg = static_cast<double>(nums[s] + nums[e]) / 2;

        // step 4 - update minimum average `minAvg`
        minAvg = min(currAvg, minAvg);

        // move start `s` and end `e` pointer
        s++;
        e--;
    }

    // step 5 - return minimum running average
    return minAvg;
}

int main(){
    // vector<int> nums = {7,8,3,4,15,13,4,1};

    // vector<int> nums = {1,9,8,3,10,5};

    vector<int> nums = {1,2,3,7,8,9};
    cout<<minimumAverage(nums)<<endl;
    return 0;
}