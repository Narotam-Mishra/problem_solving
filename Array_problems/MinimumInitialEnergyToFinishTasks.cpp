
// Problem link - https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/?envType=daily-question&envId=2026-05-12

#include<bits/stdc++.h>
using namespace std;

bool isMinimumEngergyPossible(vector<vector<int>>& tasks, int mid){
    for(auto &task : tasks){
        // extract actual and minimum energy
        int actual = task[0];
        int minimum = task[1];

        // early exit
        if(minimum > mid){
            // return false immediately
            return false;
        }
        
        // update mid
        mid -= actual;
    }

    // return true
    return true;
}

int minimumEffort(vector<vector<int>>& tasks) {
    // keep track of start and end of binary search
    int s=0, e=1e9, mid;

    // applying custom sorting
    auto lambda = [](auto task1, auto task2){
        int diff1 = task1[1] - task1[0];
        int diff2 = task2[1] - task2[0];

        return diff1 > diff2;
    };

    // step 1 - ordering of the task
    // sort the task on the basis of difference between actual and minimum
    sort(begin(tasks), end(tasks), lambda);

    // step 2 - apply binary search on answer technique
    int res = INT_MAX;
    while(s<=e){
        mid = s + (e - s) / 2;

        // step 3 - check if this mid is sufficient as minimum energy
        if(isMinimumEngergyPossible(tasks, mid)){
            res = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    // step 4 - return final result, `res`
    return res;
}

int main(){
    // vector<vector<int>> tasks = {{1,2},{2,4},{4,8}};

    // vector<vector<int>> tasks = {{1,3},{2,4},{10,11},{10,12},{8,9}};

    vector<vector<int>> tasks = {{1,7},{2,8},{3,9},{4,10},{5,11},{6,12}};
    cout<<minimumEffort(tasks);
    return 0;
}