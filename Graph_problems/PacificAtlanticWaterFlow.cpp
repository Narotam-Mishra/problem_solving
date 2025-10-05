
// Problem link - https://leetcode.com/problems/pacific-atlantic-water-flow/description/?envType=daily-question&envId=2025-10-05

#include<bits/stdc++.h>
using namespace std;

// utility method to check for valid path
bool isValid(int x, int y, int r, int c) {
    return x >= 0 && y >= 0 && x < r && y < c;
}

// utility method to perform Depth First Search (DFS)
void dfs(int x, int y, vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
    // four directions: up, down, left, right
    vector<vector<int>> directions = { {-1,0}, {1,0}, {0,-1}, {0,1} };

    // mark this cell as reachable from the ocean we started from
    visited[x][y] = true;

    // explore all four neighbous
    for (vector<int> dirs : directions) {
        int newX = x + dirs[0];
        int newY = y + dirs[1];

        // check for valid path
        // main condition: heights[newX][newY] >= heights[x][y]
        // we're going BACKWARDS from ocean to inland
        // water flows DOWN in reality, but we're searching UP from ocean
        // it means: "Can we climb UP from current cell to neighbor?"
        // if yes, then water can flow DOWN from neighbor to current cell to ocean
        if (isValid(newX, newY, r, c) && !visited[newX][newY] && heights[newX][newY] >= heights[x][y]) {
            dfs(newX, newY, heights, visited, r, c);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    // find row and column size of heights grid
    int r = heights.size();
    int c = heights[0].size();

    // track which cells can reach Pacific Ocean
    vector<vector<bool>> pacificVisited(r, vector<bool>(c, false));

    // track which cells can reach Atlantic Ocean
    vector<vector<bool>> atlanticVisited(r, vector<bool>(c, false));

    // step 1 - start DFS from all Pacific Ocean border cells (left and top edges)
    for (int i = 0; i < r; i++) {
        // left edge (Pacific)
        dfs(i, 0, heights, pacificVisited, r, c);

        // right edge (Atlantic)
        dfs(i, c - 1, heights, atlanticVisited, r, c);
    }

    for (int j = 0; j < c; j++) {
        // top edge (Pacific)
        dfs(0, j, heights, pacificVisited, r, c);

        // bottom edge (Atlantic)
        dfs(r - 1, j, heights, atlanticVisited, r, c);
    }

    // step 2 - find cells that can reach both oceans
    vector<vector<int>> res;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // step 3 - if reachable from both Pacific and Atlantic
            if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                // step 4 - add its co-ordinates to result `res` list
                res.push_back({ i, j });
            }
        }
    }

    // step 5 - return result `res` list
    return res;
}

void print2DVector(vector<vector<int>>& matrix) {
    cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ",";
    }
    cout << "]" << std::endl;
}

int main(){
    // vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};

    vector<vector<int>> heights = {{1}};
    vector<vector<int>> res = pacificAtlantic(heights);
    print2DVector(res);
    return 0;
}