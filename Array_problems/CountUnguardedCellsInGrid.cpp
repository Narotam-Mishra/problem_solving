
// Problem link - https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2025-11-02

#include<bits/stdc++.h>
using namespace std;

// utility function to mark cells guarded
void markGaurded(int r, int c, vector<vector<int>>& grid){
    // up
    for(int i=r-1; i>=0; i--){
        if(grid[i][c] == 2 || grid[i][c] == 3){
            break;
        }

        // marking it as guarded
        grid[i][c] = 1;
    }

    // down
    for(int i=r+1; i<grid.size(); i++){
        if(grid[i][c] == 2 || grid[i][c] == 3){
            break;
        }

        // marking it as guarded
        grid[i][c] = 1;
    }

    // left
    for(int j=c-1; j>=0; j--){
        if(grid[r][j] == 2 || grid[r][j] == 3){
            break;
        }

        // marking it as guarded
        grid[r][j] = 1;
    }

    // right
    for(int j=c+1; j<grid[0].size(); j++){
        if(grid[r][j] == 2 || grid[r][j] == 3){
            break;
        }

        // marking it as guarded
        grid[r][j] = 1;
    }
}

int countUnguarded1(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0));

    // step 1 - mark guards position
    for(vector<int>& guard : guards){
        int i = guard[0];
        int j = guard[1];
        grid[i][j] = 2;
    }

    // step 2 - mark walls posiiton
    for(vector<int>& wall : walls){
        int i = wall[0];
        int j = wall[1];
        grid[i][j] = 3;
    }

    // step 3 - cells which can be guarded will be marked as `1`
    for(vector<int>& guard : guards){
        int i = guard[0];
        int j = guard[1];
        markGaurded(i, j, grid);
    }

    // step 4 - count unguareded cell
    int count = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 0) count++;
        }
    }

    // step 5 - return count of unguarded cells
    return count;
}

// DFS: recursive function to mark guarded cells in one direction
void DFS(int r, int c, int dr, int dc, vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size();

    // base case:
    if(r < 0 || r >= m || c < 0 || c >= n) return;

    if(grid[r][c] == 2 || grid[r][c] == 3) return;

    // mark cell as guarded (if not already marked)
    if(grid[r][c] == 0) grid[r][c] = 1;

    // recursive case: continue in same direction
    DFS(r + dr, c + dc, dr, dc, grid);
}

void dfsHelper(int r, int c, vector<vector<int>>& grid){
    // move in four directions: up, down, left & right
    // up
    DFS(r-1, c, -1, 0, grid);
    // down
    DFS(r+1, c, 1, 0, grid);
    // left
    DFS(r, c-1, 0, -1, grid);
    // right
    DFS(r, c+1, 0, 1, grid);
}

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0));

    // step 1 - mark guard
    for(auto& g : guards){
        grid[g[0]][g[1]] = 2;
    }

    // step 2 - mark walls
    for(auto& w : walls){
        grid[w[0]][w[1]] = 3;
    }

    // step 3 - recursively mark guarded cells
    for(auto& g : guards){
        dfsHelper(g[0], g[1], grid);
    }

    // step 4 - count unguarded cells
    int count = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 0) count++;
        }
    }

    // step 5 - return count of unguarded cells
    return count;
}

int main(){
    int m = 4, n = 6;
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}}, walls = {{0,1},{2,2},{1,4}};

    // int m = 3, n = 3;
    // vector<vector<int>> guards = {{1,1}}, walls = {{0,1},{1,0},{2,1},{1,2}};
    cout<<countUnguarded(m, n, guards, walls);
    return 0;
}