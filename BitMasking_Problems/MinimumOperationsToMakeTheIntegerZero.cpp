
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/?envType=daily-question&envId=2025-09-05

#include<bits/stdc++.h>
using namespace std;

// using while(true)
int makeTheIntegerZero1(int num1, int num2) {
    // step 1 - number of operations to try
    int k = 1;

    while(true){
        // step 2 - calculate the remaining value after k operations
        // each operation subtracts (2^i + num2), so after k operations:
        // num1 - k*num2 = sum of k powers of 2
        long long val = (long long) num1 - (long long) k * num2;

        // Edge case - if val becomes negative, it's impossible to represent as sum of powers of 2
        if(val < 0){
            return -1;
        }

        // step 3 - check two conditions:
        // 1. __builtin_popcountll(val) <= k: 
        //    The minimum number of powers of 2 needed (popcount) should not exceed 
        //    the number of operations available (k)
        // 2. k <= val: 
        //    we need at least k operations, and since minimum power is 2^0 = 1,
        //    val must be at least k to allow k operations
        if(__builtin_popcountll(val) <= k && k <= val){
            return k;
        }

        // try next number of operations
        k++;
    }
}

int makeTheIntegerZero(int num1, int num2) {
    // step 1 - try operations from 1 to 36
    // Why 36? It's a reasonable upper bound:
    // - In worst case, if num2=1, then val = num1 - k
    // - We need k <= val, so k <= num1 - k, which gives k <= num1/2
    // - For 32-bit int, max value is ~2^31, so max k is around 2^30
    // - In practice, 36 covers almost all realistic cases
    for(int k = 1; k <= 36; k++) {

        // step 2 - calculate remaining value after k operations
        // Each operation subtracts (2^i + num2), so after k operations:
        // num1 - k*num2 = sum of k distinct powers of 2
        long long val = (long long) num1 - (long long) k * num2;
        
        // Edge case - If val becomes negative, no valid representation exists
        if(val < 0) {
            return -1;
        }
        
        // Step 2 - check feasibility with two conditions:
        // 1. __builtin_popcountll(val) <= k: 
        //    Minimum distinct powers of 2 needed <= available operations
        // 2. k <= val:
        //    Total value must be at least k (since minimum power is 2^0 = 1)
        //    This ensures we can distribute the value across k operations
        if(__builtin_popcountll(val) <= k && k <= val) {
            return k;
        }
    }
    
    // Step 3 - if no solution found within 36 operations, return -1
    return -1;
}


int main(){
    int num1 = 3, num2 = -2;

    // int num1 = 5, num2 = 7;
    cout<<makeTheIntegerZero(num1, num2);
    return 0;
}
