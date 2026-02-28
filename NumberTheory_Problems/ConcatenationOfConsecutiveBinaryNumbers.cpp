
// Problem link - https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/?envType=daily-question&envId=2026-02-28

#include<bits/stdc++.h>
using namespace std;

int concatenatedBinary1(int n) {
    const int mod = 1e9+7;

    // keep track of final result, `res`
    long res = 0;

    // step 1 - iterate on each number from 1 to n
    for(int num=1; num<=n; num++){
        // step 2 - find number of bits to represent this number
        int bits = log2(num) + 1;

        // step 3 - calculate result
        res = ((res<<bits) % mod + num) % mod;
    }

    // step 4 - return final result, `res`
    return (int)res;
}

int concatenatedBinary(int n) {
    const int mod = 1e9+7;

    // keep track of final result, `res`
    long res = 0;

    int bits = 0;
    // step 1 - iterate on each number from 1 to n
    for(int num=1; num<=n; num++){
        // step 2 - check if number, `num` is power of 2
        if((num & (num - 1)) == 0){
            //if it is power of 2 then increment number of bits
            bits++;
        }

        // step 3 - calculate result
        res = ((res<<bits) % mod + num) % mod;
    }

    // step 4 - return final result, `res`
    return (int)res;
}

int main(){
    // int n = 1;

    int n = 12;
    cout<<concatenatedBinary(n);
    return 0;
}