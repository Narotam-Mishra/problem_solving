
// Problem link - https://leetcode.com/problems/detect-cycles-in-2d-grid/description/?envType=daily-question&envId=2026-04-26

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
int m, n;

// utility function to check cycle using DFS
bool DFSCycleCheck(int i, int j, int pi, int pj, vector<vector<char>>& grid, vector<vector<bool>>& visited){
    if(visited[i][j] == true){
        return true;
    }

    visited[i][j] = true;

    for(auto& dir : directions){
        int ni = i + dir[0];
        int nj = j + dir[1];

        if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[i][j] == grid[ni][nj]){
            if(ni == pi && nj == pj) continue;

            if(DFSCycleCheck(ni, nj, i, j, grid, visited)){
                return true;
            }
        }
    }

    return false;
}

bool containsCycle(vector<vector<char>>& grid) {
    // find size of row and column of frid
    m = grid.size();
    n = grid[0].size();

    // keep track of visted cell
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // step 1 - iterate on non visted grid and mark visited
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            // step 2 - check cycle is detected or not
            if(!visited[i][j] && DFSCycleCheck(i, j, -1, -1, grid, visited)){
                return true;
            }
        }
    }

    // step 3 - return false if no cycle detected
    return false;
}

int main(){
    // vector<vector<char>> grid = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    
    vector<vector<char>> grid = {{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}};
    bool res = containsCycle(grid);
    res ? cout << "true" : cout << "false";
    return 0;
}