
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2026-04-28

#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> arr;

    // step 1 - Flatten the grid and check feasibility
    // All numbers must have same remainder modulo x
    int rem = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int currRem = grid[i][j] % x;
            if (rem == -1) {
                rem = currRem;
            }
            else if (rem != currRem) {
                return -1;  // Impossible: different remainders
            }
            arr.push_back(grid[i][j]);
        }
    }

    // step 2 - Sort to find median
    sort(arr.begin(), arr.end());

    // step 3 - Median minimizes sum of absolute deviations
    int median = arr[arr.size() / 2];

    // step 4 - Calculate total operations
    int operations = 0;
    for (int num : arr) {
        int diff = abs(num - median);
        // Since we've verified all numbers have same remainder,
        // diff is always divisible by x
        operations += diff / x;
    }

    return operations;
}

int main(){
    vector<vector<int>> grid = {{2,4},{6,8}};
    int x = 2;
    cout<<minOperations(grid, x);
    return 0;
}