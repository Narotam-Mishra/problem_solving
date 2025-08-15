
// Problem link - https://leetcode.com/problems/check-if-it-is-a-straight-line/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();

    // base case - if there're only 2 points, return true
    if (n <= 2) return true;

    // For three points to be collinear, the slope between points 1-2 should equal the slope between points 2-3:
    // (y2 - y1) / (x2 - x1) = (y3 - y2) / (x3 - x2)

    // step 1 - check every consecutive triplet of points
    for (int i = 0; i < n - 2; i++) {
        // extract co-ordinates
        int x1 = coordinates[i][0], y1 = coordinates[i][1];
        int x2 = coordinates[i + 1][0], y2 = coordinates[i + 1][1];
        int x3 = coordinates[i + 2][0], y3 = coordinates[i + 2][1];

        // step 2 - cross multiplication to check for collinearity
        if ((y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1)) {
            return false;
        }
    }

    // step 3 - return true as all points are collinear that forms straight line
    return true;
}

int main(){
    // vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    
    vector<vector<int>> coordinates = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
    
    bool res = checkStraightLine(coordinates);
    res ? cout<<"true" : cout<<"false";
    return 0;
}