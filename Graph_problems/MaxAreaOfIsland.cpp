
// Problem link - https://leetcode.com/problems/max-area-of-island/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> neighbourArr = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int bfsTraversal(int i, int j, vector<vector<int>>& grid){
    // using queue to perform BFS
    queue<pair<int, int>> qu;

    // push the starting point (src) in queue
    qu.push({i, j});

    // mark this source cell(i,j) as visited by using '-'
    grid[i][j] = -1;

    // every connected component of a size atleast 1
    int sizeOfCC = 1;

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

            if(grid[newNeighbourX][newNeighbourY] == 1){
                // it's an unvisited piece of land
                grid[newNeighbourX][newNeighbourY] = -1;
                // we will mark it as visited
                qu.push({newNeighbourX, newNeighbourY});
                // push new neighbour into queue

                //increment the size of connected component after each visit
                sizeOfCC++;
            }
        }
    }

    // return size of connected component
    return sizeOfCC;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int numOfMaxCC = 0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == 1){
                numOfMaxCC = max(numOfMaxCC, bfsTraversal(i, j, grid));
            }
        }
    }
    return numOfMaxCC;
}

int main(){
    vector<vector<int>> grid = {
        { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
        { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0 , 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        { 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
    };
    cout<<"Maximum area of Island: "<<maxAreaOfIsland(grid)<<endl;
    return 0;
}