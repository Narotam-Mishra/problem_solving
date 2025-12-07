
// Problem link - https://leetcode.com/problems/count-number-of-trapezoids-ii/

#include<bits/stdc++.h>
using namespace std;

int countTrapezoids(vector<vector<int>>& points) {
    int n = points.size();
    
    // map to slope -> list of intercepts for all segments with that slope
    unordered_map<float, vector<float>> slopeIntercepts;

    // map to store mid points and its corresponding slopes
    // this to detect duplicates (that forms parallelogram)
    unordered_map<int, vector<float>> midPointsMap;

    // step 1 - generate all line segments from pairs of points
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[j][0];
            int y2 = points[j][1];

            int dx = x2 - x1;
            int dy = y2 - y1;

            // handle vertical lines (undefined slope)
            float slope, intercept;
            if(x2 == x1){
                // dx == 0
                // use large number as "infinity"
                slope = 1e9 + 7;

                // X-coordinate is the "intercept"
                intercept = x1;
            }else{
                // calculate slope: m = dy/dx
                slope = (float)(y2 - y1)/(x2 - x1);

                // calculate y-intercept: b = y - mx
                // rearranged as: b = (y1*dx - x1*dy) / dx
                intercept = (float)(y1*dx - x1*dy) / dx;
            }

            // create unique hash for midpoint (x1+x2, y1+y2)
            int midPointKey = (x1+x2)*10000 + (y1+y2);

            // store segment by its slope and intercept
            slopeIntercepts[slope].push_back(intercept);

            // store segment by its midpoint and slope (for parallelogram detection)
            midPointsMap[midPointKey].push_back(slope);
        }
    }

    // step 2: count all quadrilaterals with at least one pair of parallel sides
    for(auto &it : slopeIntercepts){
        // need at least 2 segments with same slope
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

    // step 3: subtract parallelograms (have 2 pairs of parallel sides)
    // parallelograms detected by: segments share same midpoint
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

    // step 4 - return final result from `res`
    return res;
}

int main(){
    // vector<vector<int>> points = {{-3,2},{3,0},{2,3},{3,2},{2,-3}};

    vector<vector<int>> points = {{0,0},{1,0},{0,1},{2,1}};
    cout<<countTrapezoids(points);
    return 0;
}