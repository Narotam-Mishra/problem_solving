
// Problem link - https://leetcode.com/problems/container-with-most-water/description/?envType=daily-question&envId=2025-10-04

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    // find size of height
    int n = height.size();

    // step 1 - use two pointers: start at the leftmost and rightmost lines
    int s=0, e=n-1;

    // store the maximum water capacity found
    int maxWater = 0;

    // step 2 - continue until two-pointers meet
    while(s < e){
        // step 2 - calculate the width of the container
        // width is the distance between the two lines
        int width = e - s;

        // step 3 - find the effective height of the container
        // water level is constrained by the shorter of the two lines
        int reqHeight = min(height[s], height[e]);

        // step 4 - calculate the area (water capacity) of current container
        // Area = width × height
        int area = width * reqHeight;

        // step 5 - update maximum water capacity if current is larger
        maxWater = max(area, maxWater);

        // step 6 - move the pointer pointing to the shorter line
        // moving the taller line inward can only decrease area
        // moving the shorter line gives potential to find a taller line
        if(height[s] > height[e]){
            // right line is shorter, move it inward
            e--;
        }else{
            // left line is shorter or equal, move it inward
            s++;
        }
    }

    // step 7 - return the maximum water capacity found
    return maxWater;
}

int main(){
    // vector<int> height = {1,8,6,2,5,4,8,3,7};

    vector<int> height = {1,1};
    cout<<maxArea(height);
    return 0;
}