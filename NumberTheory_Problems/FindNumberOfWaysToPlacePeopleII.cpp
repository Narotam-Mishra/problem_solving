
// Problem link - https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/?envType=daily-question&envId=2025-09-03

#include<bits/stdc++.h>
using namespace std;

int numberOfPairs1(vector<vector<int>>& points) {
    int n = points.size();

    // store count of valid points
    int count = 0;

    // step 1 - sort points by x-coordinate, then by y-coordinate (descending)
    auto customCom = [](vector<int>& point1, vector<int>& point2){
        if(point1[0] == point2[0]){
            return point1[1] > point2[1];
        }
        return point1[0] < point2[0];
    };

    sort(begin(points), end(points), customCom);

    // step 2 - now iterate over possible x and y co-ordinates
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // extract co-ordinate points
            vector<int>& A = points[i];
            vector<int>& B = points[j];

            // step 3 - check A.y >= B.y (A is on upper left of B)
            // no need to check x point as it sorted i.e A.x <= B.x
            if (A[1] >= B[1]) {
                // step 4 - check second condition : there is no points inside rectangle
                bool hasPointsInside = false;

                // check every other possible points to see if it lies in the rectangle
                for (int k = i+1; k<j && !hasPointsInside; k++) {
                    // extract co-ordinate points
                    vector<int>& point = points[k];
                    int x = point[0];
                    int y = point[1];

                    // check if this point lies inside rectangle or not
                    if (x >= A[0] && x <= B[0] && y >= B[1] && y <= A[1]) {
                        hasPointsInside = true;
                        break;
                    }
                }

                // step 5 - if no points lies inside rectangle
                if (!hasPointsInside) {
                    // this is valid pair, so increment count
                    count++;
                }
            }
        }
    }

    // step 6 - return valid count
    return count;
}

int numberOfPairs(vector<vector<int>>& points) {
    int n = points.size();

    // store count of valid points
    int count = 0;

    // step 1 - sort points by x-coordinate, then by y-coordinate (descending)
    auto customCom = [](vector<int>& point1, vector<int>& point2){
        if(point1[0] == point2[0]){
            return point1[1] > point2[1];
        }
        return point1[0] < point2[0];
    };

    sort(begin(points), end(points), customCom);

    // step 2 - now iterate over possible x and y co-ordinates
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // extract co-ordinate points
            vector<int>& A = points[i];
            vector<int>& B = points[j];

            // step 3 - check A.y >= B.y (A is on upper left of B)
            // no need to check x point as it sorted i.e A.x <= B.x
            if (A[1] >= B[1]) {
                // step 4 - check second condition : there is no points inside rectangle
                bool hasPointsInside = false;

                // check every other possible points to see if it lies in the rectangle
                for (int k = i+1; k<j && !hasPointsInside; k++) {
                    // extract co-ordinate points
                    vector<int>& point = points[k];
                    int x = point[0];
                    int y = point[1];

                    // early termination
                    if(x > B[0]) break;

                    // check if this point lies inside rectangle or not
                    if (x >= A[0] && y >= B[1] && y <= A[1]) {
                        hasPointsInside = true;
                        break;
                    }
                }

                // step 5 - if no points lies inside rectangle
                if (!hasPointsInside) {
                    // this is valid pair, so increment count
                    count++;
                }
            }
        }
    }

    // step 6 - return valid count
    return count;
}

int main(){
    // vector<vector<int>> points = {{1,1},{2,2},{3,3}};

    // vector<vector<int>> points = {{6,2},{4,4},{2,6}};

    vector<vector<int>> points = {{3,1},{1,3},{1,1}};
    cout<<numberOfPairs(points);
    return 0;
}