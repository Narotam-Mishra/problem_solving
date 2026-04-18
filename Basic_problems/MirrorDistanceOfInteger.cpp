
// Problem link - https://leetcode.com/problems/mirror-distance-of-an-integer/description/?envType=daily-question&envId=2026-04-18

#include<bits/stdc++.h>
using namespace std;

// utility function to reverse a number
int reverseNum(int num) {
    int rev = 0;
    while (num > 0) {
        int rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }
    return rev;
}

int mirrorDistance(int n) {
    // step 1 - perfrome the given and return result
    return abs(n - reverseNum(n));
}

int main(){
    // int n = 25;

    // int n = 10;

    int n = 7;
    cout<<mirrorDistance(n);
}