
// Problem link - https://leetcode.com/problems/sum-of-two-integers/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int getSum(int a, int b) {
    while (b != 0) {
        // calculate the carry
        int carry = (a & b) << 1;

        // find sum without carry
        a = a ^ b;

        // assign carry to b and repeat
        b = carry;
    }
    return a;
}

int main(){
    // int a = 3, b = 2;

    int a = 1, b = 2;
    cout<<getSum(a, b);
    return 0;
}