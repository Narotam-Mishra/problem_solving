
#include<bits/stdc++.h>
using namespace std;

int findMaxK(vector<int>& nums) {
    // step 1 - create a Set to store all numbers for quick lookup
    unordered_set<int> numSet;
    for (int num : nums) {
        numSet.insert(num);
    }

    // step 2 - initialize a variable to keep track of the largest k
    int largestK = -1;

    // step 3 - iterate through the array
    for (int num : numSet) {
        // check if both num and its negative counterpart -num exist
        if (numSet.count(-num)) {
            // update largestK if num is positive and larger than current largestK
            largestK = max(largestK, abs(num));
        }
    }

    // step 4 - return the largest k, or -1 if no such k was found
    return largestK;
}

int main(){
    // vector<int> nums = {-1, 2, -3, 3};

    // vector<int> nums = {-1,10,6,7,-7,1};

    vector<int> nums = {-10,8,6,7,-2,-3};
    cout<<findMaxK(nums)<<endl;
    return 0;
}