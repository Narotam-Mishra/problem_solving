
// Problem link - https://leetcode.com/problems/separate-squares-i/?envType=daily-question&envId=2026-01-13

#include<bits/stdc++.h>
using namespace std;

bool isBottomAreaEqualsTopArea(vector<vector<int>>& squares, double mid_y, double totalArea){
    double bottomArea = 0.0;

    for(auto& square : squares){
        double y = square[1];
        double len = square[2];

        double bottom_y = y;
        double top_y = y + len;

        if(mid_y >= top_y){
            // full square below
            bottomArea += (len * len);
        }else if(mid_y > bottom_y){
            // partial area below
            bottomArea += (mid_y - bottom_y) * len;
        }
    }

    // check if bottom area more than above
    return bottomArea >= totalArea/2.0;
}

double separateSquares(vector<vector<int>>& squares) {
    double s = INT_MAX;
    double e = INT_MIN;

    // keep track of total area
    double total = 0.0000;

    // step 1 - iterate on each square of squares
    for(auto& square : squares){
        // extract co-ordinates and side
        double x = square[0];
        double y = square[1];
        double len = square[2];

        // step 2 - find total area
        total += (len * len);

        // update range
        s = min(s, y);
        e = max(e, y+len);
    }

    // step 2 - using binary search technique
    double res = 0.0000;
    while(e - s > 1e-5){
        double mid_y = s + (e - s)/2;
        res = mid_y;

        // step 3 - check if bottom area is greater or equal
        if(isBottomAreaEqualsTopArea(squares, mid_y, total) == true){
            // then shift mid_y down side to balance area
            e = mid_y;
        }else{
            // otherwise shift mid_y to up side
            s = mid_y;
        }
    }

    // step 4 - retun final result, `res`
    return res;
}

int main(){
    // vector<vector<int>> squares = {{0,0,1},{2,2,1}};

    vector<vector<int>> squares = {{0,0,2},{1,1,1}};
    cout<<separateSquares(squares);
    return 0;
}