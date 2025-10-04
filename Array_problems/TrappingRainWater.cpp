
// Problem link - https://leetcode.com/problems/trapping-rain-water/description/

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();

    // step 1 - find left max height
    vector<int> leftMax(n);
    leftMax[0] = height[0];
    for(int i=1; i<n; i++){
        leftMax[i] = max(leftMax[i-1], height[i]);
    }

    // step 2 - find right max heigh
    vector<int> rightMax(n);
    rightMax[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1], height[i]);
    }

    // step 3 - find total water stored 
    int totalWaterStored = 0;
    for(int i=0; i<n; i++){
        int h = min(leftMax[i], rightMax[i]) - height[i];
        totalWaterStored += h;
    }

    // step 4 - return total water stored
    return totalWaterStored;
}

int main(){
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    vector<int> height = {4,2,0,3,2,5};
    cout<<trap(height);
    return 0;
}