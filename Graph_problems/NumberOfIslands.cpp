
// Problem link - https://leetcode.com/problems/number-of-islands/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> neighbourArr = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void bfsTraversal(int i, int j, vector<vector<char>>& grid){
    // using queue to perform BFS
    queue<pair<int, int>> qu;

    // push the starting point (src) in queue
    qu.push({i, j});

    // mark this source cell(i,j) as visited by using '-'
    grid[i][j] = '-';

    // until queue is not empty, visit neighbour of current cell(i,j)
    while(!qu.empty()){
        pair<int, int> curr = qu.front();
        qu.pop();

        // traverse nearest neighbours
        for(int n=0; n<4; n++){
            int newNeighbourX = curr.first + neighbourArr[n][0];
            int newNeighbourY = curr.second + neighbourArr[n][1];

            // check boundary condition
            if (newNeighbourX < 0 || newNeighbourY < 0 || newNeighbourX >= grid.size() || newNeighbourY >= grid[0].size()) {
                // We are outside of grid, so we will continue
                continue;
            }

            if(grid[newNeighbourX][newNeighbourY] == '1'){
                // it's an unvisited piece of land
                grid[newNeighbourX][newNeighbourY] = '-';
                // we will mark it as visited
                qu.push({newNeighbourX, newNeighbourY});
                // push new neighbour into queue
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int numOfIslands = 0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == '1'){
                bfsTraversal(i, j, grid);
                numOfIslands++;
            }
        }
    }
    return numOfIslands;
}

int main() {
    // vector<vector<char>> grid = {
    //     {'1', '1', '1', '1', '0'},
    //     {'1', '1', '0', '1', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '0', '0', '0'}
    // };

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << "Number of islands: " << numIslands(grid) << endl;
    return 0;
}