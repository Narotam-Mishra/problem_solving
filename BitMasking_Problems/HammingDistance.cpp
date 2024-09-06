
// Problem link : https://leetcode.com/problems/hamming-distance/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
    // XOR the two numbers. The result will have bits set to 1 where x and y have different bits.
    int xorVal = x ^ y;

    // initialize a counter to keep track of the number of different bits
    int dist = 0;

    // loop through all bits in the XOR result
    while(xorVal > 0){
        // increment the counter if the least significant bit is 1
        dist += xorVal & 1;

        // right shift the XOR result by 1 to check the next bit
        xorVal = xorVal >> 1;
    }

    // return the total count of different bits
    return dist;
}

int main(){
    // int x = 1, y = 4;

    int x = 3, y = 1;
    cout<<hammingDistance(x, y)<<endl;
    return 0;
}