
// Problem link : https://leetcode.com/problems/xor-operation-in-an-array/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int xorOperation(int n, int start) {
    int xorVal = 0;

    for (int i = 0; i < n; i++) {
        // calculate running XOR value
        xorVal ^= start + 2 * i;
    }

    // return XOR value 'xorVal'
    return xorVal;
}

int main(){
    // int n = 5, start = 0;

    int n = 4, start = 3;
    cout<<xorOperation(n, start);
    return 0;
}