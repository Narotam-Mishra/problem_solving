
// Problem link - https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2026-01-12

#include<bits/stdc++.h>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int n = points.size();

    // keep track of total time 
    int minTime = 0;

    // step 1 - traverse through each consecutive pair of points
    for (int i = 0; i < n - 1; i++) {
        // current point co-ordinates
        int x1 = points[i][0];
        int y1 = points[i][1];

        // next point co-ordinates
        int x2 = points[i + 1][0];
        int y2 = points[i + 1][1];

        // step 2 - find absolute differences in x and y directions
        int dy = abs(y2 - y1);
        int dx = abs(x2 - x1);

        /*
         * We can move diagonally for min(dx, dy) seconds
         * Each diagonal move reduces both dx and dy by 1
         *
         * After diagonal moves, we move straight
         * for the remaining |dx - dy| units
         */

         // step 3 - calculate time to visit all points
        minTime += (min(dx, dy) + abs(dy - dx));
    }

    // step 4 - return minimum time
    return minTime;
}

int main(){
    // vector<vector<int>> points = {{1,1},{3,4},{-1,0}};

    vector<vector<int>> points = {{3,2},{-2,2}};
    cout<<minTimeToVisitAllPoints(points);
    return 0;
}