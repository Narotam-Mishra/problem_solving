
// Problem link : https://leetcode.com/problems/number-of-common-factors/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

int findGCD(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int commonFactors(int a, int b) {
    // intialize counter to count common factors
    int commonFactorsCount = 0;

    // step 2: Compute the GCD of a and b
    int gcdVal = findGCD(a, b);

    // step 3 : count divisors of the GCD
    for (int i = 1; i * i <= gcdVal; i++) {
        // count i as a factor
        if (gcdVal % i == 0) {
            commonFactorsCount++;
            // count gcdVal/i as distinct factor
            if (i != gcdVal / i) {
                commonFactorsCount++;
            }
        }
    }

    // step 4: Return the count of common factors
    return commonFactorsCount;
}

int main(){
    // int a = 6, b = 12;

    int a = 25, b = 30;
    cout<<commonFactors(a, b);
    return 0;
}