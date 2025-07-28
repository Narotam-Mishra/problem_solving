
// Problem link - https://leetcode.com/problems/type-of-triangle/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

string triangleType(vector<int>& nums) {
    // step 1 - extract three sides from `nums` array
    int a = nums[0], b = nums[1], c = nums[2];

    // step 2 - check condition for valid traingle
    if (a + b <= c || b + c <= a || c + a <= b) {
        // return as it is invalid case for triangle
        return "none";
    }

    // step 3 - check condition for each type of triangle and return its type
    if (a == b && b == c) {
        return "equilateral";
    }
    else if (a == b || b == c || c == a) {
        return "isosceles";
    }
    else {
        return "scalene";
    }
}

int main(){
    // vector<int> nums = {3,3,3};

    // vector<int> nums = {3,4,5};

    vector<int> nums = {4,4,5};
    cout<<triangleType(nums)<<endl;
    return 0;
}