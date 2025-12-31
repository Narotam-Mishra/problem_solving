
// Problem link - https://leetcode.com/problems/last-day-where-you-can-still-cross/description/?envType=daily-question&envId=2025-12-31

#include<bits/stdc++.h>
using namespace std;

int R, C;

// directions for moving up, down, left, right
vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

// utility function for DFS to check if we can reach the bottom row starting from (i,j)
bool canReachBottomUsingDFS(vector<vector<int>>& grid, int i, int j){
    // out of bounds OR water cell OR already visited
    if(i < 0 || i >= R || j < 0 || j >= C || grid[i][j] == 1){
        return false;
    }

    // check if we have reach the bottom
    if(i == R-1){
        return true;
    }

    // mark current cell as visited by converting it to water
    grid[i][j] = 1;

    // explore all 4 directions
    for(auto &dir : directions){
        int ni = i + dir[0];
        int nj = j + dir[1];

        if(canReachBottomUsingDFS(grid, ni, nj)){
            return true;
        }
    }

    return false;
}


// utility function to check if crossing is possible on day `m`
bool canCross(vector<vector<int>>& cells, int m){
    // initialize grid as land (0)
    vector<vector<int>> grid(R, vector<int>(C, 0));
    
    // flood cells from day 0 to day m
    for(int i=0; i<=m; i++){
        // change 1-based indexing to 0
        int x = cells[i][0] - 1;
        int y = cells[i][1] - 1;

        // mark as water
        grid[x][y] = 1;
    }

    // try to start DFS from any land cell in the top row
    for(int j=0; j<C; j++){
        // check if we can able to reach bottom using BFS / DFS
        if(grid[0][j] == 0 && canReachBottomUsingDFS(grid, 0 , j)){
            return true;
        }
    }

    return false;
}

int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    R = row;
    C = col;

    // step 1 - perform binary search on cells over days
    int s = 0;
    int e = cells.size() - 1;

    // store final result in `lastDay`
    int lastDay = 0;

    while(s <= e){
        int mid = s + (e - s)/2;

        // step 2 - check if crossing is possible on day `mid`
        if(canCross(cells, mid)){
            lastDay = mid+1;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }  
    
    // step 3 - return the last day where it is possible to walk from the top to the bottom
    return lastDay;
}

int main(){
    // int row = 2, col = 2;
    // vector<vector<int>> cells = {{1,1},{2,1},{1,2},{2,2}};

    // int row = 2, col = 2;
    // vector<vector<int>> cells = {{1,1},{1,2},{2,1},{2,2}};

    int row = 3, col = 3;
    vector<vector<int>> cells = {{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};
    cout<<latestDayToCross(row, col, cells);
    return 0;
}