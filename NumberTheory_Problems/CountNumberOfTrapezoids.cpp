
// Problem link - https://leetcode.com/problems/count-number-of-trapezoids-ii/

#include<bits/stdc++.h>
using namespace std;

int countTrapezoids(vector<vector<int>>& points) {
    int n = points.size();
    
    // step 1 - find slope and its corresponding intercepts
    unordered_map<float, vector<float>> slopeIntercepts;

    unordered_map<int, vector<float>> midPointsMap;

    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[j][0];
            int y2 = points[j][1];

            int dx = x2 - x1;
            int dy = y2 - y1;

            float slope, intercept;

            if(x2 == x1){
                // dx == 0
                slope = 1e9 + 7;
                intercept = x1;
            }else{
                slope = (float)(y2 - y1)/(x2 - x1);
                intercept = (y1*dx - x1*dy) / dx;
            }

            int midPointKey = (x1+x2)*1000 + (y1+y2);
            slopeIntercepts[slope].push_back(intercept);
            midPointsMap[midPointKey].push_back(slope);
        }
    }

    for(auto &it : slopeIntercepts){
        if(it.second.size() <= 1) continue;

        // {intercept -> count}
        map<float, int> mp;
        for(float intercept : it.second){
            mp[intercept]++;
        }

        int prevHorizontal = 0;
        for(auto &it : mp){
            int count = it.second;
            // counting duplicates also
            res += count * prevHorizontal;

            prevHorizontal += count;
        }
    }

    for(auto &it : midPointsMap){
        if(it.second.size() <= 1) continue;
        
        // {intercept -> count}
        map<float, int> mp;
        for(float slope : it.second){
            mp[slope]++;
        }

        int prevHorizontal = 0;
        for(auto &it : mp){
            int count = it.second;
            // removing duplicates
            res -= count * prevHorizontal;

            prevHorizontal += count;
        }
    }

    return res;
}

int main(){
    // vector<vector<int>> points = {{-3,2},{3,0},{2,3},{3,2},{2,-3}};

    vector<vector<int>> points = {{0,0},{1,0},{0,1},{2,1}};
    cout<<countTrapezoids(points);
    return 0;
}