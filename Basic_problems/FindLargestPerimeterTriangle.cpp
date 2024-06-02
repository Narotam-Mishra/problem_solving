
// Problem link - https://leetcode.com/problems/largest-perimeter-triangle/description/

#include<bits/stdc++.h>
using namespace std;

int largestPerimeter(vector<int>& nums) {
    // Step 1: Sort the array in descending order
    sort(nums.begin(), nums.end(), greater<int>());

    // Step 2: Iterate through the array and check for valid triangles
    for (int i = 0; i < nums.size() - 2; i++) {
        // Pick three consecutive elements
        int a = nums[i];
        int b = nums[i + 1];
        int c = nums[i + 2];

        // Step 3: Check the triangle inequality theorem
        if (a < b + c) {
            return a + b + c;
        }
    }

    // Step 4: If no valid triangle is found, return 0
    return 0;
}

int main(){
    // vector<int> arr = {2, 1, 2};

    vector<int> arr = {1, 2, 1, 10};
    cout<<largestPerimeter(arr)<<endl;
    return 0;
}