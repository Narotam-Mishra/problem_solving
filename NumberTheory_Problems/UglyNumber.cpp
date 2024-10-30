
// Problem link : https://leetcode.com/problems/ugly-number/description/

#include<bits/stdc++.h>
using namespace std;

bool isUgly(int n) {
    // corner case: Ugly numbers are positive integers only
    if(n <= 0) return false;

    // list of allowed prime factors.
    int factors[] = {2, 3, 5};

    // for each allowed factor, divide n by that factor until it's no longer divisible
    for(int factor : factors){
        while(n % factor == 0){
            // remove one occurrence of the factor
            n = n / factor;
        }
    }
    // after removing all 2, 3, and 5 factors, check if n is reduced to 1
    return n == 1;
}

int main(){
    // int num = 6;

    int num = 14;
    bool res = isUgly(num);
    res ? cout<<"true" : cout<<"false";
    return 0;
}