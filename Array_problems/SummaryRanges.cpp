
// Problem link - https://leetcode.com/problems/summary-ranges/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    // store result in `res` array
    vector<string> res;
    int n = nums.size();

    // edge case:
    if (n == 0)
        return res;

    // step 1 - start current range
    int start = nums[0];

    // step 2 - iterate through the array
    for (int i = 1; i < n; i++) {
        // step 3 - if current number is not consecutive
        if (nums[i] != nums[i - 1] + 1) {
            // step 4 - end the current range and add to result
            if (start == nums[i - 1]) {
                // add single number
                res.push_back(to_string(start));
            }
            else {
                // add range
                res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
            }

            // step 5 - start new range from current number
            start = nums[i];
        }
    }

    // step 6 - handle last range after loop
    if (start == nums[n - 1]) {
        // add single number
        res.push_back(to_string(start));
    }
    else {
        // add range
        res.push_back(to_string(start) + "->" + to_string(nums[n - 1]));
    }

    // step 7 - return result `res`
    return res;
}

void printVector(vector<string>& vec){
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
    // vector<int> nums = {0,1,2,4,5,7};

    vector<int> nums = {0,2,3,4,6,8,9};
    vector<string> res = summaryRanges(nums);
    printVector(res);
    return 0;
}