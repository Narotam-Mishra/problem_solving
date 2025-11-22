
// Problem link - https://leetcode.com/problems/set-intersection-size-at-least-two/description/

#include<bits/stdc++.h>
using namespace std;

int intersectionSizeTwo(vector<vector<int>>& intervals) {
    int n = intervals.size();

    // step 1 - sort intervals on the basis of 2nd point in ascending order
    // if end points of interval is same then sort on basis of descending order of first point
    auto customSort = [](auto &vec1, auto &vec2){
        if(vec1[1] != vec2[1]){
            // ascending order sorting on the basis of second point
            return vec1[1] < vec2[1];
        }
        // otherwise descending order sorting on the basis of first point
        return vec1[0] > vec2[0];
    };

    sort(intervals.begin(), intervals.end(), customSort);

    // store final result in `res`
    int res = 0;

    // maintain two elements from interval in `f` & `s`
    int f = -1, s = -1;

    // step 2 - process each interval
    for(int i=0; i<n; i++){
        int l = intervals[i][0];
        int r = intervals[i][1];

        if(l <= f) continue;

        if(l > s){
            res += 2;
            s = r;
            f = r - 1;
        }else{
            res += 1;
            f = s;
            s = r;
        }
    }

    // step 3 - return final result `res`
    return res;
}

int main(){
    // vector<vector<int>> intervals = {{1,3},{3,7},{8,9}};

    // vector<vector<int>> intervals = {{1,3},{1,4},{2,5},{3,5}};

    vector<vector<int>> intervals = {{1,2},{2,3},{2,4},{4,5}};
    cout<<intersectionSizeTwo(intervals);
    return 0;
}