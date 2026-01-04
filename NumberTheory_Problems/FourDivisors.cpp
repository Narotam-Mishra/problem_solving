
// Problem link - https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04

#include<bits/stdc++.h>
using namespace std;

int findDivisorSum(int num) {
    // keep track of factors count and factors sum
    int factorsCount = 0;
    int currentSum = 0;

    // iterate on each posisble factor from 1 to sqrt(n)
    for (int f = 1; f * f <= num; f++) {
        // check if `num` is divisble 
        if (num % f == 0) {
            // find other factor
            int f2 = num / f;

            // check if num is perfect square number
            if (f2 == f) {
                // count only one factor
                factorsCount += 1;

                // calculate factors sum
                currentSum += f;
            }
            else {
                // count factors in pair
                factorsCount += 2;

                // calculate factors sum
                currentSum += (f + f2);
            }
        }

        // check if factors count is greater than 4 than return 0
        if (factorsCount > 4) {
            return 0;
        }
    }

    // return factors sum if factors count is exactly four otherwise 0
    return factorsCount == 4 ? currentSum : 0;
}

int sumFourDivisors(vector<int>& nums) {
    // keep track of factors sum 
    int factorSum = 0;

    // step 1 - iterate on each num of `nums` 
    for(int num : nums){
        // step 2 - finad factors sum
        factorSum += findDivisorSum(num);
    }

    // step 3 - return factors sum, `factorSum`
    return factorSum;
}

int main(){
    vector<int> nums = {21,4,7};

    // vector<int> nums = {21,21};

    // vector<int> nums = {1,2,3,4,5};
    cout<<sumFourDivisors(nums);
    return 0;
}