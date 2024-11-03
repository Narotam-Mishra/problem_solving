
// Problem link : https://leetcode.com/problems/perfect-number/description/

#include<bits/stdc++.h>
using namespace std;

bool checkPerfectNumber(int num) {
    // edge case: perfect numbers are greater than 1
    if (num <= 1) return false;

    // start 'sum' with 1 as it is a divisor of every number
    int sum = 1;

    // loop from 2 to sqrt(n) to find divisors
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            // if i divides n, add i as a divisor
            sum += i;

            // add n/i if it is distinct divisor
            if (i != num / i) sum += num / i;
        }
    }

    // return true if sum equals input number 'num'
    return sum == num;
}

int main(){
    // int num = 6;

    int num = 28;
    bool res = checkPerfectNumber(num);
    res ? cout<<"true" : cout<<"false"<<endl;
    return 0;
}
