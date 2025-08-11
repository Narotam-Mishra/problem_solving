
// Problem link - https://leetcode.com/problems/find-the-maximum-divisibility-score/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    // step 1 - store maximum divisibility score in `maxScore`
    int maxScore = -1;

    // best divisor (smallest in case of tie)
    int bestDivisor = INT_MAX;

    // step 2 - iterate on each divisor
    for (int i = 0; i < divisors.size(); i++) {
        int currDivisor = divisors[i];
        int currScore = 0;

        // step 3 - count how many numbers in nums are divisible by current divisor
        for (int j = 0; j < nums.size(); j++) {

            // step 4 - check if number is divisble by divisor
            if (nums[j] % currDivisor == 0) {
                currScore++;
            }
        }

        // step 5 - update maximum score if
        // case 1 - current score is higher than max score, or
        // case 2 - current score equals max score but current divisor is smaller
        if (currScore > maxScore || currScore == maxScore && currDivisor < bestDivisor) {
            maxScore = currScore;
            bestDivisor = currDivisor;
        }
    }

    // step 6 - return the divisor with the maximum divisibility score
    return bestDivisor;
}

int main(){
    // vector<int> nums = {2,9,15,50}, divisors = {5,3,7,2};

    // vector<int> nums = {4,7,9,3,9}, divisors = {5,2,3};

    vector<int> nums = {20,14,21,10}, divisors = {10,16,20};
    cout<<maxDivScore(nums, divisors);
    return 0;
}