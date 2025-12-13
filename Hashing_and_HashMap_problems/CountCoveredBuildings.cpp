
// Problem link - https://leetcode.com/problems/count-covered-buildings/description/

#include <bits/stdc++.h>
using namespace std;

// using brute-force approach
int countCoveredBuildings1(int n, vector<vector<int>>& buildings) {
    int m = buildings.size();

    // step 1 - iterate on each building
    int coveredCount = 0;
    for (int i = 0; i < m; ++i) {
        // get coordinates of current building
        int x = buildings[i][0];
        int y = buildings[i][1];
        
        // step 2 - define four directions
        bool left = false, right = false, up = false, down = false;
        
        // step 3 - compare this building with other buildings
        for(int j=0; j<m; j++){
            // skip same buildings
            if(i == j) continue;

            int nx = buildings[j][0];
            int ny = buildings[j][1];

            // check left side: same y, x is smaller
            if(ny == y && nx < x){
                left = true;
            }

            // check right side: same y, x is greater
            if(ny == y && nx > x){
                right = true;   
            }

            // check down side: same x, y is smaller
            if(nx == x && ny < y){
                down = true;
            }

            // check up side: same x, y is greater
            if(nx == x && ny > y){
                up = true;
            }
        }

        // step 4 - if all four directions are covered, increment count
        if(left && right && up && down){
            coveredCount++;
        }
    }

    // step 5 - return the total count of covered buildings
    return coveredCount;
}

// using optimized approach 
int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    int m = buildings.size();

    // map of pairs to store building minimum and maxiumum coordinates
    unordered_map<int, pair<int, int>> yMinMaxX; // row -> {minX, maxX}
    unordered_map<int, pair<int, int>> xMinMaxY; // col -> {minY, maxY}

    // step 1 - iterate on each building and update min-max maps
    for (auto & building : buildings) {
        // get coordinates of current building
        int x = building[0];
        int y = building[1];
        
        // update min and max for row (y)
        if(!yMinMaxX.count(y)){
            yMinMaxX[y] = {INT_MAX, INT_MIN};
        }

        // update min and max for column (x)
        if(!xMinMaxY.count(x)){
            xMinMaxY[x] = {INT_MAX, INT_MIN};
        }

        // update min and max values
        yMinMaxX[y].first = min(yMinMaxX[y].first, x);
        yMinMaxX[y].second = max(yMinMaxX[y].second, x);

        xMinMaxY[x].first = min(xMinMaxY[x].first, y);
        xMinMaxY[x].second = max(xMinMaxY[x].second, y);
    }

    // step 2 - iterate on each building again to check coverage
    int coveredCount = 0;
    for (auto & building : buildings) {
        // get coordinates of current building
        int x = building[0];
        int y = building[1];

        // get min and max values for x and y from maps
        auto &xr = yMinMaxX[y]; // row
        auto &yc = xMinMaxY[x]; // column
        
        // step 3 - check if current building is covered in all four directions
        bool left = (xr.first < x);   // left side covered if minX < x
        bool right = (xr.second > x); // right side covered if maxX > x
        bool down = (yc.first < y);   // down side covered if minY < y
        bool up = (yc.second > y);    // up side covered if max

        // step 4 - if all four directions are covered, increment count
        if(left && right && up && down){
            coveredCount++;
        }
    }

    // step 5 - return the total count of covered buildings
    return coveredCount;
}

int main(){
    int n = 3;
    vector<vector<int>> buildings = {{1,2}, {2,2}, {3,2}, {2,1}, {2,3}};
    
    // int n = 3;
    // vector<vector<int>> buildings = {{1,1}, {1,2}, {2,1}, {2,2}};
    
    // int n = 5;
    // vector<vector<int>> buildings = {{1,3}, {3,2}, {3,3}, {3,5}, {5,3}};
    cout << countCoveredBuildings(n, buildings) << endl;
    return 0;
}