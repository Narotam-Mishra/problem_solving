
// Problem link - https://leetcode.com/problems/swim-in-rising-water/description/?envType=daily-question&envId=2025-10-06

#include<bits/stdc++.h>
using namespace std;

// direction vector to help traverse in all four directions (down, up, right, left)
vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int n;

// DFS utility function to check if we can reach destination with water level t
bool isPossibleToReach(vector<vector<int>>& grid, int i, int j, int t, vector<vector<bool>>& visited){
    // base cases: out of bounds, already visited, or elevation too high for current water level
    if(i < 0 || i >= n || j < 0 || j>= n || visited[i][j] == true || grid[i][j] > t){
        return false;
    }

    // mark current cell as visited
    visited[i][j] = true;

    // check if we reached the destination (bottom-right corner)
    if(i == n-1 && j == n-1){
        return true;
    }

    // explore all four directions
    for(vector<int> dirs : directions){
        int newRow = i + dirs[0];
        int newCol = j + dirs[1];

        // recursively check if we can reach destination from new position
        if(isPossibleToReach(grid, newRow, newCol, t, visited)){
            return true;
        }
    }

    // cannot reach destination from this path
    return false;
}

int swimInWater(vector<vector<int>>& grid) {
    // find size of grid
    n = grid.size();

    // using binary search algorithm
    // minimum possible time is the starting cell elevation
    // maximum possible time is n*n-1
    int s = grid[0][0], e = n * n - 1;

    // store result in `res`
    int res = 0;

    // step 1 - perform binary search on the water level
    while(s <= e){
        // step 2 - calculate mid point to test as potential water level
        int mid = s + (e-s) / 2;

        // create a fresh visited array for each binary search iteration
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // step 3 - check if we can reach destination with water level = mid
        if(isPossibleToReach(grid, 0, 0, mid, visited)){
            // step 4 - if reachable, try to find a smaller water level
            res = mid;
            e = mid - 1;
        }else{
            // step 5 - if not reachable, we need higher water level
            s = mid + 1;
        }
    }

    // step 6 - return final result `res`
    return res;
}

int main(){
    // vector<vector<int>> grid = {{0,2},{1,3}};

    vector<vector<int>> grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout<<swimInWater(grid);
    return 0;
}