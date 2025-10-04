
// Problem link - https://leetcode.com/problems/trapping-rain-water-ii/?envType=daily-question&envId=2025-10-03

#include<bits/stdc++.h>
using namespace std;

// to store height along with its co-ordinates, we will create pair of pairs
typedef pair<int, pair<int, int>> pp;

int trapRainWater(vector<vector<int>>& heightMap) {
    // direction array for finding neighbour
    vector<vector<int>> directions = {{0,-1}, {0,1}, {-1,0}, {1,0}}; 

    // find row and column size
    int m = heightMap.size();
    int n = heightMap[0].size();

    // base case
    if (heightMap.empty() || m < 3 || n < 3) {
        return 0;
    }

    // use min-heap to process each height {height, (i, j)}
    priority_queue<pp, vector<pp>, greater<>> boundaryCells;

    // visited array to mark already visited cell
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // step 1 - add left and right columns
    // left and right most columns are boundary
    for (int row = 1; row < m - 1; row++) {
        boundaryCells.push({heightMap[row][0], {row, 0}});
        visited[row][0] = true;
        boundaryCells.push({heightMap[row][n-1], {row, n-1}});
        visited[row][n-1] = true;
    }

    // step 2 - add top and bottom most rows
    // topmost and bottommost rows are also bounday
    for (int col = 0; col < n; col++) {
        boundaryCells.push({heightMap[0][col], {0, col}});
        visited[0][col] = true;
        boundaryCells.push({heightMap[m-1][col], {m-1, col}});
        visited[m-1][col] = true;
    }

    // step 3 - process cells from lowest to highest
    // store volumne of water in `waterVolumn`
    int waterVolumn = 0;
    while(!boundaryCells.empty()){
        pp p = boundaryCells.top();
        boundaryCells.pop();

        // step 4 - extract height and its co-ordinates
        int height = p.first;
        int i = p.second.first;
        int j = p.second.second;

        // step 5 - find its neightbour
        for(vector<int>& dir : directions){
            int newRow = i + dir[0];
            int newCol = j + dir[1];

            // step 6 - check for boundary cell and it should not be already visited
            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]){
                // step 7 - calculate water stored on current buidling
                waterVolumn += max(height - heightMap[newRow][newCol], 0);

                // step 8 - update height once water is collected
                boundaryCells.push({max(height, heightMap[newRow][newCol]), {newRow, newCol}});

                // step 9 - mark neighbour as visted
                visited[newRow][newCol] = true;
            } 
        }
    }

    // step 10 - return the volume of water it can trap after raining.
    return waterVolumn;
}

int main(){
    // vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};

    vector<vector<int>> heightMap = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3}, {3,2,2,2,3}, {3,3,3,3,3}};
    cout<<trapRainWater(heightMap);
    return 0;
}