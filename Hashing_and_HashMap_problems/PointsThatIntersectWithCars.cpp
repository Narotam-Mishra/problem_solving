
#include<bits/stdc++.h>
using namespace std;

int numberOfPoints(vector<vector<int>>& nums) {
    // step 1 - create set to store unique covered points
    unordered_set<int> coveredPoints;

    // step 2 - iterate over each car's parking range
    for (vector<int> car : nums) {
        int start = car[0];
        int end = car[1];

        // add each integer point from start to end into the set
        for (int i = start; i <= end; i++) {
            coveredPoints.insert(i);
        }
    }

    // step 3 - return the size of set 
    return coveredPoints.size();
}

int main(){
    // vector<vector<int>> nums = {{3, 6}, {1, 5}, {4,7}};

    vector<vector<int>> nums = {{1, 3}, {5, 8}};
    cout<<numberOfPoints(nums)<<endl;
    return 0;
}