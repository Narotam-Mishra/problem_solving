
// Problem link - https://leetcode.com/problems/delete-greatest-value-in-each-row/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int deleteGreatestValue(vector<vector<int>>& grid) {
    // step 1 - sort each row in descending order
    for (int i = 0; i < grid.size(); i++) {
        sort(grid[i].begin(), grid[i].end(), greater<int>());
    }

    // step 2 - process each column
    int ans = 0;
    for (int j = 0; j < grid[0].size(); j++) {
        int maxNum = 0;

        // step 3 - find maximum among all rows for this column
        for (int i = 0; i < grid.size(); i++) {
            maxNum = max(maxNum, grid[i][j]);
        }

        // step 4 - add the maximum of deleted elements to the answer
        ans += maxNum;
    }

    // step 5 - return answer, `ans`
    return ans;
}

int main(){
    // vector<vector<int>> grid = {{1,2,4}, {3,3,1}};

    vector<vector<int>> grid = {{ 10 }};
    cout<<deleteGreatestValue(grid);
    return 0;
}