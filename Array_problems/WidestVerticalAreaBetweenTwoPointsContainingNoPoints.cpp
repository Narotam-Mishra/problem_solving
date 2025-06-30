
// Problem link - https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    // step 1 - extract and sort x-coordinates
    // we only care about x-coordinates since we're looking for vertical gaps
    vector<int> xPoints;
    for (const auto& point : points) {
        xPoints.push_back(point[0]);
    }

    // sort x-coordinates
    sort(xPoints.begin(), xPoints.end());

    // step 2 - find the maximum gap between consecutive x-coordinates
    int maxWidth = 0;
    for (int i = 1; i < xPoints.size(); i++) {
        int currentWidth = xPoints[i] - xPoints[i - 1];

        // step 3 - update maximum width
        maxWidth = max(maxWidth, currentWidth);
    }

    // step 4 - return maximum widest vertical area
    return maxWidth;
}

int main(){
    // vector<vector<int>> points = {{8,7}, {9,9}, {7,4}, {9,7}};

    vector<vector<int>> points = {{3,1}, {9,0}, {1,0}, {1,4}, {5,3}, {8,8}};
    cout<<maxWidthOfVerticalArea(points)<<endl;
    return 0;
}