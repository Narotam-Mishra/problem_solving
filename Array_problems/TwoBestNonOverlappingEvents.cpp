
// Problem link - https://leetcode.com/problems/two-best-non-overlapping-events/?envType=daily-question&envId=2025-12-23

#include<bits/stdc++.h>
using namespace std;

// using Brute force approach
int maxTwoEvents1(vector<vector<int>>& events) {
    // get size of events
    int n1 = events.size();

    // step 1 - iterate on every event 
    int res = 0;
    for(int i=0; i<n1; i++){
        int val = events[i][2];
        // update result for single event
        res = max(res, val);

        for(int j=0; j<n1; j++){
            // skip same event
            if(i == j) continue;

            // step 2 - check if it is overlapping event or not
            if(events[i][0] <= events[j][1]) continue;

            // step 3 - update maximum sum
            res = max(res, val + events[j][2]);
        }
    }

    // step 4 - return final result, `res`
    return res;
}

int n;
int memo[1000001][3];

// upper bound of events end time
int binarySearch(vector<vector<int>>& events, int endTime){
    int s = 0;
    int e = n - 1;
    int res = n;

    while(s <= e){
        int mid = s + (e - s) / 2;

        if(events[mid][0] > endTime){
            res = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }

    return res;
}

int solveRec(vector<vector<int>>& events, int i, int cnt){
    // base case: if we have already attended two events 
    // or we have completed all events
    if(cnt == 2 || i >= n){
        return 0;
    }

    // if answer is already computed then return it
    if(memo[i][cnt] != -1){
        return memo[i][cnt];
    }

    // find next valid event index using binary search
    int nextValidEventIdx = binarySearch(events, events[i][1]);

    // attend event
    int attendEvent = events[i][2] + solveRec(events, nextValidEventIdx, cnt+1);

    // skip event
    int skipEvent = solveRec(events, i+1, cnt);

    return memo[i][cnt] = max(attendEvent, skipEvent);
}

// using Recursion + Memoization
int maxTwoEvents(vector<vector<int>>& events) {
    // get size of events
    n = events.size();

    // sort events on the basis of start time
    sort(begin(events), end(events));

    // initialize value in memo
    memset(memo, -1, sizeof(memo));

    // step 1 - solve it using recursion and return result
    int cnt = 0;
    return solveRec(events, 0, cnt);
}

int main(){
    // vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};

    // vector<vector<int>> events = {{1,3,2},{4,5,2},{1,5,5}};

    vector<vector<int>> events = {{1,5,3},{1,5,1},{6,6,5}};
    cout<<maxTwoEvents(events);
    return 0;
}