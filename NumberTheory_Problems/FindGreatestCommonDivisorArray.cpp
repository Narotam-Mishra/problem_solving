
#include<bits/stdc++.h>
using namespace std;

// helper function to calculate the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findGCD(vector<int>& nums) {
    // find maximum number from array
    int minNum = INT_MAX;

    // find minimum number from array
    int maxNum = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        // maximum number
        maxNum = max(maxNum, nums[i]);

        // minimum number
        minNum = min(minNum, nums[i]);
    }

    // find and return GCD of maximum and minimum number
    return gcd(minNum, maxNum);
}

int main(){
    // vector<int> nums = {2,5,6,9,10};

    // vector<int> nums = {7, 5, 6, 8, 3};

    vector<int> nums = {3, 3};
    cout<<findGCD(nums);
    return 0;
}