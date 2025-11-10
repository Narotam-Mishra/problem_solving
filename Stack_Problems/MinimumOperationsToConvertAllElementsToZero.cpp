
// Problem link - https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/?envType=daily-question&envId=2025-11-10

#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums) {
    int ops = 0;

    // stack to maintain increasing sequence of values
    stack<int> st;

    // step 1 - iterate on each number of `nums`
    for (int num : nums) {
        // step 2 - remove all elements from stack that are greater than current number
        // this is because we can extend previous operations to cover current element
        while (!st.empty() && st.top() > num) {
            st.pop();
        }

        // skip zeros as they don't need any operation
        if (num == 0) continue;

        // step 3 - if stack is empty or current number is greater than stack top,
        // we need a new operation starting from this position
        if (st.empty() || st.top() < num) {
            ops++;
            st.push(num);
        }
    }

    // step 4 - return minimum operations `ops`
    return ops;
}


int main(){
    // vector<int> nums = {0,2};

    // vector<int> nums = {3,1,2,1};

    vector<int> nums = {1,2,1,2,1,2};
    cout<<minOperations(nums);
    return 0;
}