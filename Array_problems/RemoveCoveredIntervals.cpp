
// Problem link - https://leetcode.com/problems/remove-covered-intervals/description/?envType=daily-question&envId=2026-07-06

#include<bits/stdc++.h>
using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) {
    // step 1 - use custom sorting
    // if start tie, end descending.
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    });

    // counter to keep track of overlapping intervals
    int count = 0;

    // keep track of maximum value in interval end
    int maxEnd = -1;

    // step 2 - iterate on each interval
    for(auto &interval : intervals){
        // extract start and end value
        int l = interval[0];
        int r = interval[1];

        // step 3 - check if current end > maxEnd, 
        // it is not covered by any previous interval
        if(r > maxEnd){
            // increment counter
            count++;

            // update maximum end value
            maxEnd = r;
        }
    }

    // step 4 - return the number of remaining intervals
    return count;
}

int main(){
    // vector<vector<int>> intervals = {{1,4},{3,6},{2,8}};

    vector<vector<int>> intervals = {{1,4}, {2,3}};
    cout<<removeCoveredIntervals(intervals);
    return 0;
}