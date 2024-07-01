
// Problem link - https://leetcode.com/problems/rotting-oranges/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> neighbourArr = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int bfsTraversal(vector<vector<int>>& grid){
    // using queue for BFS traversal
    queue<vector<int>> qu;

    // find row and column size
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;

    // add all initial rotten oranges to the queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                qu.push({i, j, 0}); // {x, y, time}
            }
        }
    }

    // perform BFS traversal
    // till the time queue is empty
    while(!qu.empty()){
        vector<int> curr = qu.front();
        qu.pop();

        // get co-ordinates of the rotten orange
        int x = curr[0];
        int y = curr[1];

        // get time
        int time = curr[2];

        for(auto& neighbour : neighbourArr){
            int nx = x + neighbour[0];
            int ny = y + neighbour[1];

            // check boundary condition for grid
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            // we need to traverse within grid boundary
            if (grid[nx][ny] == 1) {
                // calculate result 'res'
                res = max(res, time + 1);

                // mark as rotten
                grid[nx][ny] = 2;

                // add newly rotten orange to the queue
                qu.push({nx, ny, time + 1});
            }
        }
    }

    // Check if any fresh orange is left
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }

    // return result 'res'
    return res;
}

int orangesRotting(vector<vector<int>>& grid) {
    return bfsTraversal(grid);
}

int main(){
    // vector<vector<int>> grid = {{0, 2}};

    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout<<orangesRotting(grid);
    return 0;
}