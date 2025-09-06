
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/?envType=daily-question&envId=2025-09-06

#include<bits/stdc++.h>
using namespace std;

// utility function to calculate total operations needed for all numbers in range [l, r]
long long findSteps(int l, int r){
    // start of current operation level range, let say L
    long long L = 1;

    // how many operations needed for numbers in this range), let say steps
    long long steps = 1;

    // total operations accumulator
    long long actualSteps = 0;

    // step 1 - process each operation level until we exceed the query range
    while(L <= r){
        // step 2 - calculate end of current level range
        // level k contains numbers [4^(k-1), 4^k - 1]
        long long R = 4 * L - 1;

        // step 3 - find intersection of current level range [L, R] with query range [l, r]
        long long start = max(L, (long long)l);  // find max of level start, L and query start, l
        long long end = min(R, (long long)r);    // find min of level end, R and query end, r

        // step 4 - if intersection exists, add contribution to total steps
        if(start <= end){
            // count of numbers in intersection * operations needed per number
            actualSteps += (end - start + 1) * steps;
        }

        // step 5 - move to next operation level
        steps += 1;   // next level needs one more operation
        L *= 4;       // next level starts at 4 times current start (4^k)
    }

    // step 6 - return total operations accumulator
    return actualSteps;
}

long long minOperations(vector<vector<int>>& queries) {
    // store final answer in `ans`
    long long ans = 0;

    // step 1 - iterate on each query
    for(auto &query : queries){
        // find start and end range [l,r]
        int l = query[0];
        int r = query[1];

        // step 2 - calculate total operations needed for range [l, r]
        long long steps = findSteps(l, r);
        
        // we can operate on 2 numbers simultaneously,
        // so actual operations = ceil(total_steps / 2) = (total_steps + 1) / 2
        ans += (steps + 1) / 2;
    }

    // step 3 - return final answer `ans`
    return ans;
}

int main(){
    vector<vector<int>> queries = {{1,2},{2,4}};

    // vector<vector<int>> queries = {{2,6}};
    cout<<minOperations(queries);
    return 0;
}